/************************************************************************
 *  WEB Assignment 06
 * 
 *  Name: Semin Jeon,  Date: 2019-04-05
 *
 *  Online (Heroku) Link: https://gentle-mesa-20820.herokuapp.com/
 *
 ********************************************************************************/
const dataService = require("./data-service.js");
const path = require("path");
const express = require("express");
const multer = require("multer");
const fs = require("fs");
const bodyParser = require("body-parser");
const exphbs = require("express-handlebars");
const clientSessions = require("client-sessions");
const dataServiceAuth = require("./data-service-auth.js");
const app = express();

var HTTP_PORT = process.env.PORT || 8080;

// call this function after the http server starts listening for requests
onHttpStart = () => {
    console.log("Express http server listening on: " + HTTP_PORT);
}


// Server to correctly return "the css/site.css", the "static" must be used
app.use(express.static('public'));

app.use(bodyParser.urlencoded({ extended: true }));


// Middleware function for activeRoute
app.use((req, res, next) => {
    let route = req.baseUrl + req.path;
    app.locals.activeRoute = (route == "/") ? "/" : route.replace(/\/$/, "");
    next();
});

// Client Session
app.use(clientSessions({
    cookieName: "session",
    secret: "web322_assignment6",
    duration: 3 * 60 * 1000, //3minutes
    activeDuration: 1000 * 60
}));

// local session
app.use((req, res, next) => {
    res.locals.session = req.session;
    next();
});


// Handle HTML
app.engine('.hbs', exphbs({
    extname: '.hbs',
    defaultLayout: 'main',
    helpers: {
        navLink: (url, options) => {
            return '<li' + ((url == app.locals.activeRoute) ? 'class="active"' : '') +
                '><a href=' + url + '>' + options.fn(this) + '</a></li>';
        },
        equal: (lvalue, rvalue, options) => {
            if (arguments.length < 3)
                throw new Error("Handlebars Helper equal needs 2 parameters");
            if (lvalue != rvalue)
                return options.inverse(this);
            else
                return options.fn(this);
        }
    }
}));

app.set('view engine', '.hbs');

let ensureLogin = (req, res, next) => {
    if (!req.sesiion.user) {
        res.redirect("/login");
    } else next();
};


// multer requires a few options to be setup to store files with file extensions
// by default it won't store extensions for security reasons
const storage = multer.diskStorage({
    destination: "./public/images/uploaded",
    filename: (req, file, cb) => {
        cb(null, Date.now() + path.extname(file.originalname));
    }
});


// tell multer to use the diskStorage function for naming files instead of the default.
const upload = multer({ storage: storage });


//////////////////GET//////////////////////
// setup a 'route' to listen on the default url path
app.get("/", (req, res) => {
    res.render("home");
});


// setup another route to listen on /about
app.get("/about", (req, res) => {
    res.render("about");
});


app.get("/login", (req, res) => {
    res.render("login");
});


app.get("/register", (req, res) => {
    res.render("register");
});


app.get("/logout", (req, res) => {
    req.session.reset();
    res.redirect("/");
});


app.get("/userHistory", ensureLogin, (req, res) => {
    res.render("userHistory");
})


app.get("/employee/:empNum", ensureLogin, (req, res) => {
    // initialize an empty object to store the valueslet viewData = {};
    dataService.getEmployeeByNum(req.params.empNum)
        .then((data) => {
            if (data) {
                viewData.employee = data; //store employee data in the "viewData" object as "employee"
            } else {
                viewData.employee = null; // set employee to nullifnone were returned
            }
        }).catch(() => {
            viewData.employee = null; // set employee to null if there was an error
        }).then(dataService.getDepartments).then((data) => {
            viewData.departments = data; // store department data in the "viewData" object as "departments"
            // loop through viewData.departments and once we have found the departmentId that matches
            // the employee's "department" value, add a "selected" property to the matching 
            // viewData.departments object
            for (let i = 0; i < viewData.departments.length; i++) {
                if (viewData.departments[i].departmentId == viewData.employee.department) {
                    viewData.departments[i].selected = true;
                }
            }
        })
        .catch(() => {
            viewData.departments = []; // set departments to empty if there was an error
        })
        .then(() => {
            if (viewData.employee == null) { // if no employee -return an error
                res.status(404).send("Employee Not Found");
            } else {
                res.render("employee", { viewData: viewData }); // render the "employee" view
            }
        })
        .catch((err) => {
            res.status(500).send("Unable to Show Employees");
        })
});

app.get("employees/delete/:empNum", ensureLogin, (req, res) => {
    dataService.deleteEmployeeByNum(req.params.empNum)
        .then(() => res.redirect("/employees"))
        .catch((err) => res.status(500).send(`Unable to Remove employee number ${req.params.empNum}/employee not found`));
});


app.get("/employees", ensureLogin, (req, res) => {
    if (req.query.status) {
        dataService.getEmployeesByStatus(req.query.status)
            .then((data) => {
                if (data.length > 0) res.render("employees", { employees: data });
                else res.render("employees", { message: "no results" });
            })
            .catch(() => res.render("employees", { message: "no results" }));
    } else if (req.query.department) {
        dataService.getEmployeesByDepartment(req.query.department)
            .then((data) => {
                if (data.length > 0) res.render("employees", { employees: data });
                else res.render("employees", { message: "no results" });
            })
            .catch(() => res.render("employees", { message: "no results" }));
    } else if (req.query.manager) {
        dataService.getEmployeesByManager(req.query.manager)
            .then((data) => {
                if (data.length > 0) res.render("employees", { employees: data });
                else res.render("employees", { message: "no results" });
            })
            .catch(() => res.render("employees", { message: "no results" }));
    } else {
        dataService.getAllEmployees()
            .then((data) => {
                if (data.length > 0) res.render("employees", { employees: data });
                else res.render("employees", { message: "no results" });
            })
            .catch(() => res.render("employees", { message: "no results" }));
    }
});


app.get("/departments", ensureLogin, (req, res) => {
    dataService.getDepartments()
        .then((data) => {
            if (data.length > 0) res.render("departments", { departments: data });
            else res.render("departments", { message: "no results" });

        })
        .catch(() => res.render("departments", { message: "no results" }));

});

app.get("/employees/add", ensureLogin, (req, res) => {
    dataService.getDepartments()
        .then((data) => res.render("addEmployee", { deparments: data }))
        .catch((err) => res.render("addEmployee", { departments: [] }));
});

app.get("/images/add", ensureLogin, (req, res) => {
    res.render("addImage");
});

app.get("/images", ensureLogin, (req, res) => {
    fs.readdir("./public/images/uploaded", (err, files) => {
        res.render("images", { img: files });
    });
});

app.get("/departments/:departmentId", ensureLogin, (req, res) => {
    dataService.getDepartmentById(req.params.departmentId)
        .then((data) => {
            if (data.length > 0) res.render("department", { department: data });
            else res.status(404).send("Department Not Found");
        })
        .catch((err) => res.status(404).send("Department Not Found"));
});


// No matching route
app.get("*", (req, res) => {
    res.status(404).send("Page Not Found");
});


app.get("/departments/add", ensureLogin, (req, res) => {
    res.render("addDepartment");
});


//////////////////POST//////////////////////

app.post("/register", (req, res) => {
    dataServiceAuth.registerUser(req.body)
        .then((value) => {
            res.render("register", { successMessage: "User created" });
        })
        .catch((err) => {
            res.render("register", { errorMessage: err, userName: req.body.userName });
        })
})


app.post("/login", (req, res) => {
    req.body.userAgent = req.get("User-Agent");
    dataServiceAuth.checkUser(req.body)
        .then((user) => {
            req.session.user = {
                userName: user.userName,
                email: user.email,
                loginHistory: user.loginHistory
            }
            res.redirect("/employees");
        })
        .catch((err) => {
            res.render("login", { errorMessage: err, userName: req.body.userName });
        });
});





app.post("/employees/add", ensureLogin, (req, res) => {
    dataService.addEmployee(req.body)
        .then(res.redirect("/employees"))
        .catch((err) => res.status(500).send("Failed to add the employees"));

});


// middleware(upload.single)
app.post("/images/add", upload.single("imageFile"), (req, res) => {
    res.redirect("/images");
});




app.post("/employee/update", ensureLogin, (req, res) => {
    dataService.updateEmployee(req.body)
        .then(res.redirect("/employees"))
        .catch((err) => res.status(500).send("Failed to add the employee"));
});


app.post("/departments/add", ensureLogin, (req, res) => {
    dataService.addDepartment(req.body)
        .then(res.redirect("/departments"))
        .catch((err) => res.status(500).send("Failed to add the department"));
});

app.post("/departments/update", ensureLogin, (req, res) => {
    dataService.updateDepartment(req.body)
        .then(res.redirect("/departments"))
        .catch((err) => res.status(500).send("Failed to update the department"));
});



// setup http server to listen on HTTP_PORT
dataService.initialize()
    .then(dataServiceAuth.initialize)
    .then(() => {
        app.listen(HTTP_PORT, () => {
            console.log("app listening on: " + HTTP_PORT)
        });
    })
    .catch((err) => {
        console.log("unable to start server: " + err);
    });