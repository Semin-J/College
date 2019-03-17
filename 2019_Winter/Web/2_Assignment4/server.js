/************************************************************************
*  WEB322 – Assignment04
* 
*  Name: Semin Jeon, Student ID: 146453162, Date: 2019-03-02
*
*  Online (Heroku) Link: https://gentle-mesa-20820.herokuapp.com/
*
********************************************************************************/
const dataService = require("./data-service.js");
const path = require("path");
const express = require("express");
const multer = require("multer");
const fs = require('fs');
const bodyParser = require("body-parser");
const exphbs = require("express-handlebars");
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


// multer requires a few options to be setup to store files with file extensions
// by default it won't store extensions for security reasons
const storage = multer.diskStorage({
   destination: "./public/images/uploaded",
   filename: (req, file, cb) => {
      // we write the filename as the current date down to the millisecond
      // in a large web service this would possibly cause a problem if two people
      // uploaded an image at the exact same time. A better way would be to use GUID's for filenames.
      cb(null, Date.now() + path.extname(file.originalname));
   }
});

// tell multer to use the diskStorage function for naming files instead of the default.
const upload = multer({ storage: storage });


// setup a 'route' to listen on the default url path
app.get("/", (req, res) => {
   res.render("home"); //hbs don't need it?
});

// setup another route to listen on /about
app.get("/about", (req, res) => {
   //res.sendFile(path.join(__dirname,"/views/about.html"));
   res.render("about");
});


app.get("/employee/:value", (req, res) => {
   dataService.getEmployeeByNum(req.params.value)
      .then((data) => res.render("employee", { employee: data}))
      .catch((err) => res.render("employee", { message: err }));
      // .then((data) => res.json(data))
      // .catch((err) => res.status(500).send(err));
});

app.post("/employee/update", (req, res) => {
   dataService.updateEmployee(req.body)
      .then(() => res.redirect("/employees"));
});

app.get("/employees", (req, res) => {
   if (req.query.status) {
      dataService.getEmployeesByStatus(req.query.status)
         .then((data) => res.render("employees", { employees: data }))
         .catch((err) => res.render("employees",{ message: err }));
   }

   else if (req.query.department) {
      dataService.getEmployeesByDepartment(req.query.department)
         .then((data) => res.render("employees", { employees: data }))
         .catch((err) => res.render("employees",{ message: err }));
      // .then((data) => res.json(data))
      // .catch((err) => res.status(500).send(err));
   }

   else if (req.query.manager) {
      dataService.getEmployeesByManager(req.query.manager)
         .then((data) => res.render("employees", { employees: data }))
         .catch((err) => res.render("employees",{ message: err }));
      // .then((data) => res.json(data))
      // .catch((err) => res.status(500).send(err));
   }

   else {
      dataService.getAllEmployees()
         .then((data) => res.render("employees", { employees: data }))
         .catch((err) => res.render("employees",{ message: err }));
      // .then((data) => res.json(data))
      // .catch((err) => res.json({ message: err }));
   }
});

// app.get("/managers", (req,res) => {
//    dataService.getManagers()
//       .then((data) => res.json(data))
//       .catch((err) => res.json({ message: err }));
// });

app.get("/departments", (req, res) => {
   dataService.getDepartments()
      .then((data) => res.render("departments", { departments: data }))
      .catch((err) => res.render("departments",{ message: err }));
   // .then((data) => res.json(data))
   // .catch((err) => res.json({ message: err}));
});

app.get("/employees/add", (req, res) => {
   //res.sendFile(path.join(__dirname, "/views/addEmployee.html"));
   res.render("addEmployee");
});

app.post("/addEmployee", (req, res) => {
   data.addEmployee(req.body)
      .then(res.redirect("/employees"))
      .catch(res.status(500).send("Server Error"));
});

app.get("/images/add", (req, res) => {
   //res.sendFile(path.join(__dirname, "/views/addImage.html"))
   res.render("addImage");
});


// middleware(upload.single)
app.post("/images/add", upload.single("imageFile"), (req, res) => {
   res.redirect("/images");
});

app.get("/images", (req, res) => {
   fs.readdir("./public/images/uploaded", (err, files) => {
      res.render("images", { img: files });
   });
});


// No matching route
app.get("*", (req, res) => {
   res.status(404).send("Page Not Found");
});


// setup http server to listen on HTTP_PORT
dataService.initialize()
   .then(() => app.listen(HTTP_PORT, onHttpStart))
   .catch((err) => console.log(err));
