/********************************************************************************* 
*  WEB – Assignment 02 

*  Name: _Semin Jeon__    Date: _2018/10/19__ 
* ********************************************************************************/

/**********************************
 *          ALL DATA              *
 *  write your CustomerDB Object  *
 *      BELOW this Object         *
 **********************************/

var allData = [
    {type:"store", data:{store_id: 297, name: "Scotiabank - Main Branch", address_id: 1023}},
    {type:"store", data:{store_id: 614, name: "Scotiabank - Hamilton", address_id: 1984}},
    {type:"store", data:{store_id: 193, name: "Scotiabank - Mississauga", address_id: 1757}},
    {type:"customer", data:{customer_id: 26, store_id:297, first_name: "Dave", last_name: "Bennett", email: "dbennett@gmail.com", address_id: 4536, add_date: null}},
    {type:"customer", data:{customer_id: 59, store_id:193, first_name: "John", last_name: "Stevens", email: "jstevens22@hotmail.com", address_id: 2473, add_date: null}},
    {type:"customer", data:{customer_id: 29, store_id:614, first_name: "Sarah", last_name: "Pym", email: "spym99@hotmail.com", address_id: 1611, add_date: null}},
    {type:"customer", data:{customer_id: 63, store_id:297, first_name: "Steven", last_name: "Edwards", email: "steven2231@hotmail.com", address_id: 1836, add_date: null}},
    {type:"customer", data:{customer_id: 71, store_id:614, first_name: "Martin", last_name: "Scott", email: "mdog33@gmail.com", address_id: 2727, add_date: null}},
    {type:"customer", data:{customer_id: 24, store_id:614, first_name: "Jonathan", last_name: "Pym", email: "jjpym@yahoo.ca", address_id: 1611, add_date: null}},
    {type:"customer", data:{customer_id: 36, store_id:193, first_name: "Kaitlyn", last_name: "Adams", email: "katy38@hotmail.com", address_id: 5464, add_date: null}},
    {type:"customer", data:{customer_id: 73, store_id:297, first_name: "Melissa", last_name: "Bennett", email: "mbennett@gmail.com", address_id: 4536, add_date: null}},         
    {type:"address", data:{address_id: 1023, address: "2895 Yonge St.", city:"Toronto", province:"ON", postal_code:"L4C02G"}},
    {type:"address", data:{address_id: 1984, address: "3611 Main St. West", city:"Hamilton", province:"ON", postal_code:"R5O8H5"}},
    {type:"address", data:{address_id: 1757, address: "1177 Ontario St. Unit 8", city:"Mississauga", province:"ON", postal_code:"L9H6B3"}},
    {type:"address", data:{address_id: 4536, address: "3945 John St.", city: "Ajax", province: "ON", postal_code: "L7M4T9"}},
    {type:"address", data:{address_id: 2473, address: "391 Baker St. Apt 231", city: "Mississauga", province: "ON", postal_code: "M4T8S3"}},
    {type:"address", data:{address_id: 1611, address: "183 City Ct.", city: "Hamilton", province: "ON", postal_code: "J3T9V2"}},
    {type:"address", data:{address_id: 1836, address: "67 Rhymer Ave.", city: "Stouffville", province: "ON", postal_code: "L3C8H4"}},
    {type:"address", data:{address_id: 2727, address: "287 Brant St. Apt 4A", city: "Waterdown", province: "ON", postal_code: "R93G3P"}},
    {type:"address", data:{address_id: 5464, address: "11 New St. Apt 2B", city: "Brampton", province: "ON", postal_code: "L694R7"}},
];




 /*  Write your CustomerDB Object  */

var CustomerDB = {
   customer:[],
   address:[],
   store:[],
  //Main insert data
  insertData:function(allData){
    for(var i = 0; i < allData.length; i++) {
      if(allData[i].type == "customer") {
        this.addCustomer(allData[i]);
      }
      else if(allData[i].type == "address") {
        this.addAddress(allData[i]);
      }
      else if(allData[i].type == "store") {
        this.addStore(allData[i]);
      }
    }
  },//checked

  //Methods to work with "customer" data
  addCustomer:function(customerObj) {
    var date = new Date();
    customerObj.data.add_date = date.toDateString() + " " + date.toTimeString();
    this.customer.push(customerObj);
  },//checked

  outputCustomerById:function(customer_id) {
    var current_customer, customer_address;
    for(var i = 0; i < this.customer.length; i++){
      if(this.customer[i].data.customer_id == customer_id) {
        current_customer = this.customer[i].data;
        customer_address = this.getAddressById(this.customer[i].data.address_id);
      }
    }
    console.log("Customer " + current_customer.customer_id + ": " + current_customer.first_name + " " + current_customer.last_name + " (" + current_customer.email + ")");
    console.log("Home Address: " + customer_address.address + " " + customer_address.city + ", " + customer_address.province + ". " + customer_address.postal_code);
    console.log("Joined: " + current_customer.add_date + "\n");
  },//checked

  outputAllCustomers:function() {
    console.log("All Customers\n");
    for(var i = 0; i < this.customer.length; i++) {
      this.outputCustomerById(this.customer[i].data.customer_id);
    }
  },//checked

  outputCustomersByStore:function(store_id) {
    var current_customer, customer_address;
    var store_data = this.getStoreById(store_id);
    console.log("Customers in Store: " + store_data.name + "\n");
    for(var i = 0; i < this.customer.length; i++) {
      if(this.customer[i].data.store_id == store_id) {
        current_customer = this.customer[i].data;
        customer_address = this.getAddressById(current_customer.address_id);
        console.log("Customer " + current_customer.customer_id + ": " + current_customer.first_name + " " + current_customer.last_name + " (" + current_customer.email + ")");
        console.log("Home Address: " + customer_address.address + " " + customer_address.city + ", " + customer_address.province + ". " + customer_address.postal_code);
        console.log("Joined: " + current_customer.add_date + "\n");
      }
    }
  },//checked

  removeCustomerById:function(customer_id) {
    for(var i = 0; i < this.customer.length; i++) {
      if(this.customer[i].data.customer_id == customer_id) {
        this.removeAddressById(this.customer[i].data.address_id);
        this.customer.splice(i, 1);
      }
    }
  },//checked

  //Methods to work with "Address" data
  addAddress:function(addressObj) {
    this.address.push(addressObj);
  },//checked

  getAddressById:function(address_id) {
    for(var i = 0; i < this.address.length; i++) {
      if(this.address[i].data.address_id == address_id) {
        return this.address[i].data;
      }
    }
  },//checked

  outputAllAddresses:function() {
    console.log("All Addresses\n");
    var current;
    for(var i = 0 ; i < this.address.length; i++) {
      current = this.address[i].data;
      console.log("Address " + current.address_id + ": " + current.address + " " + current.city + ", " + current.province + ". " + current.postal_code + "\n");
    }
  },//checked

  removeAddressById:function(address_id) {
    var cnt = 0;
    var target;
    for(var i = 0; i < this.address.length; i++) {
      if(this.address[i].data.address_id == address_id) {
        target = i;
        for(var j = 0; j < this.customer.length; j++) {
          if(this.customer[j].data.address_id == address_id) {
            cnt++;
          }
        }
        for(var k = 0; k < this.store.length; k++) {
        if(this.store[k].data.address_id == address_id) {
          cnt++;
          }
        }
      }
    }
    if(cnt > 1);
    else {
      this.address.splice(target, 1);
    }
  },//checked

  //Methods to work with "store" data
  addStore:function(storeObj) {
    this.store.push(storeObj);
  },//checked

  getStoreById:function(store_id) {
    for(var i = 0; i < this.store.length; i++) {
      if(this.store[i].data.store_id == store_id) {
        return this.store[i].data;
      }
    }
  },//checked

  outputAllStores:function() {
    console.log("All Stores\n");
    for(var i = 0; i < this.store.length; i++) {
      current = this.store[i].data;
      current_address = this.getAddressById(current.address_id);
      console.log("Store " + current.store_id + ": " + current.name);
      console.log("Location: " + current_address.address + " " + current_address.city + ", " + current_address.province + ". " + current_address.postal_code + "\n");
    }
  }//checked

};

/**********************************
 *          TEST DATA             *
 **********************************/



// Insert all Data into the Database

CustomerDB.insertData(allData);

// output all customers

console.log("CustomerDB.outputAllCustomers();\n\n--------------------------\n\n");
CustomerDB.outputAllCustomers();
console.log("--------------------------\n\n");

// output all addresses

console.log("CustomerDB.outputAllAddresses();\n\n--------------------------\n\n");
CustomerDB.outputAllAddresses();
console.log("--------------------------\n\n"); 

// output all stores

console.log("CustomerDB.outputAllStores();\n\n--------------------------\n\n");
CustomerDB.outputAllStores();
console.log("--------------------------\n\n"); 

// output all customers in the "Main Branch"

console.log("CustomerDB.outputCustomersByStore(297);\n\n--------------------------\n\n");
CustomerDB.outputCustomersByStore(297);
console.log("--------------------------\n\n"); 

// remove Customer Dave Bennett (customer_id 26) and Martin Scott (customer_id 71)

console.log("CustomerDB.removeCustomerById(26);\nCustomerDB.removeCustomerById(71);\n\n");
CustomerDB.removeCustomerById(26);
CustomerDB.removeCustomerById(71);

console.log("--------------------------\n\n"); 

// output all customers again
// NOTE: Dave Bennett and Martin Scott should be missing

console.log("CustomerDB.outputAllCustomers();\n\n--------------------------\n\n");
CustomerDB.outputAllCustomers();
console.log("--------------------------\n\n");

// output all addresses again
// NOTE: only addrss 287 Brant St. Apt 4A Waterdown, ON. R93G3P should be missing

console.log("CustomerDB.outputAllAddresses();\n\n--------------------------\n\n");
CustomerDB.outputAllAddresses();
console.log("--------------------------\n\n"); 



