const Sequelize = require("sequelize");
const db = "deid1b3j02acvt";
const user = "sphvzpxhzukbdy";
const pw = "11cf9ea2c9b39d924ec1cc84b4d18c69969142680aeb4056ef3705be1de93152";

var sequelize = new Sequelize(db, user, pw, {
    host: "ec2-54-204-2-25.compute-1.amazonaws.com",
    dialect: "postgres",
    port: 5432,
    dialectOptions: {
        ssl: true
    }
});

// Employee Model
var Employee = sequelize.define("Employee", {
    employeeNum: {
        type: Sequelize.INTEGER,
        primaryKey: true,
        autoIncrement: true
    },
    firstName: Sequelize.STRING,
    lastName: Sequelize.STRING,
    email: Sequelize.STRING,
    SSN: Sequelize.STRING,
    addressStreet: Sequelize.STRING,
    addressCity: Sequelize.STRING,
    addressState: Sequelize.STRING,
    addressPostal: Sequelize.STRING,
    maritalStatus: Sequelize.STRING,
    isManager: Sequelize.BOOLEAN,
    employeeManagerNum: Sequelize.INTEGER,
    status: Sequelize.STRING,
    department: Sequelize.INTEGER,
    hireDate: Sequelize.STRING
});

// Department model
var Department = sequelize.define("Department", {
    departmentId: {
        type: Sequelize.INTEGER,
        primaryKey: true,
        autoIncrement: true
    },
    departmentName: Sequelize.STRING
});


module.exports.initialize = () => {
    return new Promise((resolve, reject) => {
        sequelize.sync()
            .then(() => resolve())
            .catch(() => reject("unable to sync the database"));
    });
}

module.exports.getAllEmployees = () => {
    return new Promise((resolve, reject) => {
        Employee.findAll()
            .then(() => resolve(Employee.findAll()))
            .catch(() => reject("no results returned"));
    });
}

module.exports.getEmployeesByStatus = (status) => {
    return new Promise((resolve, reject) => {
        Employee.findAll({
                where: {
                    status: status
                }
            })
            .then(() => resolve(Employee.findAll({
                where: {
                    status: status
                }
            })))
            .catch(() => reject("no results returned"));
    });
}

module.exports.getEmployeesByDepartment = (dept) => {
    return new Promise((resolve, reject) => {
        Employee.findAll({
                where: {
                    department: dept
                }
            })
            .then(() => resolve(Employee.findAll({
                where: {
                    department: dept
                }
            })))
            .catch(() => reject("no result returned"));
    });
}

module.exports.getEmployeesByManager = (manager) => {
    return new Promise((resolve, reject) => {
        Employee.findAll({
                where: {
                    employeeManagerNum: manager
                }
            })
            .then(() => resolve(Employee.findAll({
                where: {
                    employeeManagerNum: manager
                }
            })))
            .catch(() => reject("no result returned"));
    });
}

module.exports.getEmployeeByNum = (num) => {
    return new Promise((resolve, reject) => {
        Employee.findAll({
                where: {
                    employeeNum: num
                }
            })
            .then(() => resolve(Employee.findAll({
                where: {
                    employeeNum: num
                }
            })))
            .catch(() => reject("no result returned"));
    });
}

module.exports.getDepartments = () => {
    return new Promise((resolve, reject) => {
        Department.findAll()
            .then(() => resolve(Department.findAll()))
            .catch(() => reject("no results returned"));
    });
}

module.exports.addEmployee = (employeeData) => {
    employeeData.isManager = (employeeData.isManager) ? true : false;
    for (prop in employeeData) {
        if (prop == "") prop = null;
    }
    return new Promise((resolve, reject) => {
        Employee.create(employeeData)
            .then(() => resolve())
            .catch(() => reject("unable to create employee"));
    });
}

module.exports.updateEmployee = (employeeData) => {
    employeeData.isManager = (employeeData.isManager) ? true : false;
    for (prop in employeeData) {
        if (prop == "") prop = null;
    }
    return new Promise((resolve, reject) => {
        Employee.update(employeeData)
            .then(() => resolve())
            .catch(() => reject("unable to update employee"));
    });
}

module.exports.addDepartment = (departmentData) => {
    for (prop in departmentData) {
        if (prop == "") prop = null;
    }
    return new Promise((resolve, reject) => {
        Department.create(departmentData)
            .then(() => resolve())
            .catch(() => reject("unable to create department"));
    })
}

module.exports.updateDepartment = (departmentData) => {
    for (prop in departmentData) {
        if (prop = "") prop = null;
    }
    return new Promise((resolve, reject) => {
        Department.update(departmentData)
            .then(() => resolve())
            .catch(() => reject("unable to update department"));
    })
}

module.exports.getDepartmentById = (id) => {
    return new Promise((resolve, reject) => {
        Department.findAll({
                where: {
                    departmentId: id
                }
            })
            .then(() => resolve(Department.findAll({
                where: {
                    departmentId: id
                }
            })))
            .catch(() => reject("no result returned"));
    })
}

module.exports.deleteEmployeeByNum = (empNum) => {
    return new Promise((resolve, reject) => {
        Employee.destroy({
                where: {
                    employeeNum: empNum
                }
            })
            .then(() => resolve())
            .catch(() => reject("There was an error removing the employee"));
    })
}