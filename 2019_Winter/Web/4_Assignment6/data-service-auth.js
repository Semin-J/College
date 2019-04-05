const mongoose = require("mongoose");
const bcrypt = require("bcryptjs");
var Schema = mongoose.Schema;
var userSchema = new Schema({
    "userName": {
        "type": String,
        "unique": true
    },
    "password": String,
    "email": String,
    "loginHistory": {
        "dataTime": Date,
        "userAgent": String
    }
});

let User;

module.exports.initialize = () => {
    return new Promise((resolve, reject) => { //realpassword?
        let db = mongoose.createConnection("mongodb+srv://semin:BeMyself18!m@web322-a6-cxc1y.mongodb.net/test?retryWrites=true");
        db.on('error', (err) => {
            reject(err); // reject the promise with the provided error
        });
        db.once('open', () => {
            User = db.model("users", userSchema);
            resolve();
        });
    });
}

module.exports.registerUser = (userData) => {
    return new Promise((resolve, reject) => {
        if (userData.password != userData.password2) {
            reject("Passwords do not match");
        } else {
            bcrypt.genSalt(10, (err, salt) => {
                bcrypt.hash(userData.password, salt, (err, hash) => {
                    if (err) reject("There was an error encrypting the password");
                    else {
                        userData.password = hash;
                        let newUser = new User(userData);
                        newUser.save((err) => {
                            if (err) {
                                if (err.code == 11000) reject("User Name already taken");
                                reject("There was an error creating the user:" + err);
                            } else resolve();
                        })
                    }
                })
            })
        }
    });
}

module.exports.checkUser = (userData) => {
    return new Promise((resolve, reject) => {
        User.find({ userName: userData.userName }).exec()
            .then((users) => {
                if (!users) reject("Unable to find user: " + userData.userName);
                else {
                    bcrypt.compare(userData.password, users[0].password)
                        .then((res) => {
                            if (res === true) {
                                user[0].loginHistory.push({
                                    dateTime: (new Date()).toString(),
                                    userAgent: userData.userAgent
                                });
                                User.update({ userName: user[0].userName }, { $set: { loginHistory: user[0].loginHistory } }, { multi: false }).exec()
                                    .then(() => resolve(users[0]))
                                    .catch((err) => reject("There was an error verifying the user: " + err));
                            } else reject("Incorrect Password for user: " + userData.userName);
                        })
                }
            })
            .catch(() => reject("Unable to find user: " + userData.userName));
    })
}