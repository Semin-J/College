/************************************************************************
*  WEB322 – Assignment03
* 
*  Name: Semin Jeon, Date: 2019-2-26
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
const app = express();

var HTTP_PORT = process.env.PORT || 8080;

// call this function after the http server starts listening for requests
onHttpStart = () => {
   console.log("Express http server listening on: " + HTTP_PORT);
}

// Server to correctly return "the css/site.css", the "static" must be used
app.use(express.static('public'));
app.use(bodyParser.urlencoded({extended: true}));

// multer requires a few options to be setup to store files with file extensions
// by default it won't store extensions for security reasons
const storage = multer.diskStorage({
   destination: "./public/images/uploaded",
   filename: (req, file, cb) => {
     // we write the filename as the current date down to the millisecond
     // in a large web service this would possibly cause a problem if two people
     // uploaded an image at the exact same time. A better way would be to use GUID's for filenames.
     // this is a simple example.
     cb(null, Date.now() + path.extname(file.originalname));
   }
 });
 
// tell multer to use the diskStorage function for naming files instead of the default.
const upload = multer({storage: storage});


// setup a 'route' to listen on the default url path (http://localhost)
app.get("/", (req,res) => {
   res.sendFile(path.join(__dirname, "/views/home.html"));
});

// setup another route to listen on /about
app.get("/about", (req,res) => {
   res.sendFile(path.join(__dirname,"/views/about.html"));
});

//???????
app.get("/employee/:value", (req, res) => {
   dataService.getEmployeeByNum(req.params.value)
      .then((data) => {
         console.log(data);
         res.json(data);

      })
      .catch((err) => res.status(500).send(err));
});

app.get("/employees", (req,res) => {
   if(req.query.status) {
      var status = req.query.status;
      dataService.getEmployeesByStatus(status)
      .then((data) => res.json(data))
      .catch((err) => res.status(500).send(err));
   }

   if(req.query.department) {
      var department = (+req.query.department);
      dataService.getEmployeesByDepartment(department)
      .then((data) => res.json(data))
      .catch((err) => res.status(500).send(err));
   }

   if(req.query.manager) {
      var manager = (+req.query.manager);
      dataService.getEmployeesByManager(manager)
      .then((data) => res.json(data))
      .catch((err) => res.status(500).send(err));
   }

   dataService.getAllEmployees()
      .then((data) => res.json(data))
      .catch((err) => res.json({ message: err }));
});

app.get("/managers", (req,res) => {
   dataService.getManagers()
      .then((data) => res.json(data))
      .catch((err) => res.json({ message: err }));
});

app.get("/departments", (req,res) => {
   dataService.getDepartments()
      .then((data) => res.json(data))
      .catch((err) => res.json({ message: err}));
});

app.get("/employees/add", (req,res) => {
   res.sendFile(path.join(__dirname, "/views/addEmployee.html"));
});

app.post("/addEmployee", (req, res) => {
   data.addEmployee(req.body)
   .then(res.redirect("/employees"))
   .catch(res.status(500).send("Server Error"));
})

app.get("/images/add", (req,res) => {
   res.sendFile(path.join(__dirname, "/views/addImage.html"))
});


// middleware(upload.single)
app.post("/images/add", upload.single("imageFile"), (req, res) => {
   res.redirect("/images");
});

app.get("/images", (req, res) => {
   fs.readdir("./public/images/uploaded", (err, files) => {
      res.json({image: files });
   });
});

// No matching route
app.get("*", (req,res) => {
   res.status(404).send("Page Not Found");
});


// setup http server to listen on HTTP_PORT
dataService.initialize()
   .then(() => app.listen(HTTP_PORT, onHttpStart))
   .catch((err) => console.log(err));
