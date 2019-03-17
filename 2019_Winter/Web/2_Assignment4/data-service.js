var employees = [];
var departments = [];
const fs = require('fs');

module.exports.initialize = () => {
  return new Promise((resolve, reject) => {
    fs.readFile('./data/employees.json', (err, data) => {
      if (err) reject("Unable to read file");
      else {
        employees = JSON.parse(data);
        fs.readFile('./data/departments.json', (err, data) => {
          if (err) reject("Unable to read file");
          else resolve(departments = JSON.parse(data));
        });
      }
    });
  });
}

module.exports.getAllEmployees = () => {
  return new Promise((resolve, reject) => {
    if (employees.length == 0) reject("No results returned");
    else resolve(employees);
  });
}


module.exports.getManagers = () => {
  var result = [];
  for (var i = 0; i < employees.length; i++) {
    if (employees[i].isManager) result.push(employees[i]);
  }

  return new Promise((resolve, reject) => {
    if (result.length == 0) reject("No results returned");
    else resolve(result);
  });
}

module.exports.getDepartments = () => {
  return new Promise((resolve, reject) => {
    if (departments.length == 0) reject("No results returned");
    else resolve(departments);
  });

}

module.exports.addEmployee = (employeeData) => {
  return new Promise((resolve, reject) => {
    if (employeeData.isManager === undefined) {
      employeeData.isManager = false;
    }
    else {
      employeeData.isManager = true;
    }
    employeeData.employeeNum = employees.length + 1;

    employees.push(employeeData);

    resolve(employees);
  });
}

module.exports.getEmployeesByStatus = (status) => {
  return new Promise((resolve, reject) => {
    if (status === "Full Time") {
      var fullTime = [];
      for (let i = 0; i < employees.length; i++) {
        if (employees[i].status === "Full Time")
          fullTime.push(employees[i]);
      }
      resolve(fullTime);
    }
    else if (status === "Part Time") {
      var partTime = [];
      for (let i = 0; i < employees.length; i++) {
        if (employees[i].status === "Part Time")
          partTime.push(employees[i]);
      }
      resolve(partTime);
    }
    else {
      reject("Wrong input");
    }
  });
}

module.exports.getEmployeesByDepartment = (dept) => {
  return new Promise((resolve, reject) => {
    if (dept >= 1 && dept <= 7) {
      var deptTemp = [];
      for (let i = 0; i < employees.length; i++) {
        if (employees[i].department === parseInt(dept)) {
          deptTemp.push(employees[i]);
        }
      }
      resolve(deptTemp);
    }
    else {
      reject("Wrong department number");
    }
  });
}

module.exports.getEmployeesByManager = (manager) => {
  return new Promise((resolve, reject) => {
    if (manager >= 1 && manager <= 30) {
      var managerTemp = [];
      for (let i = 0; i < employees.length; i++) {
        if (employees[i].employeeManagerNum === parseInt(manager)) {
          managerTemp.push(employees[i]);
        }
      }
      resolve(managerTemp);
    }
    else {
      reject("Wrong manager number");
    }
  });
}

module.exports.getEmployeeByNum = (num) => {
  return new Promise((resolve, reject) => {
    let emp;
    if (employees.length > 0) {
      for (let i = 0; i < employees.length; i++) {
        if (employees[i].employeeNum === parseInt(num)) {
          emp = employees[i];
          break;
        }
      }
      resolve(emp);
    }
    else {
      reject("No employee found");
    }
  });
}

module.exports.updateEmployee = (employeeData) => {
  console.log(employeeData);
  return new Promise((resolve, reject) => {
    for(let i = 0; i < employees.length; i++) {
      if (employeeData.employeeNum == employees[i].employeeNum)
        employees[i] = employeeData;
    }
    resolve();
  });
}