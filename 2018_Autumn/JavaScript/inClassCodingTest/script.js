// Semin Jeon
//sjeon18@myseneca.ca
var customers = [
  {first: "Albert", last: "Danison", saving: 3689.21, cheque: 139.40, id: "99904552"},
  {first: "Kadeem", last: "Best", saving:2500.00, cheque: 864.14, id: "99904553"},
  {first: "Jenelle", last: "Chen", saving: 10000.00, cheque: 137.88, id: "99904554"}
];
var custIndex = -1; //customer Index, global variable
// Lookup Customer button
document.querySelector("#lookup").addEventListener("click", function(){
  var custID = document.querySelector("#cusID").value;
  if(custID == "") {
    alert("ID is empty!");
  }
  else {
    var index = -1;
    for(var i = 0; i < customers.length; i++) {
      if (custID === customers[i].id){
        index = i;
        custIndex = index;
      } 
    }
    if(index == -1) alert("Error, customer not found");
    else alert("Welcome " + customers[index].first + " " + customers[index].last);
  }
}); //checked

var accT; //account type

// Account type & Check balance
document.querySelector("#checkB").addEventListener("click", function(){
  if(custIndex != -1) {
    var type = document.querySelector("#accType").value;
    if(type == "c" || type == "C") {
      var valueC = customers[custIndex].cheque;
      var balance = document.createElement("p");
      balance.innerHTML = `
      Balance of Chequing Account is \$ ${valueC}
      `
      document.querySelector("#balDiv").appendChild(balance);
      accT = type;
    }
    else if(type == "s" || type == "S") {
      var valueS = customers[custIndex].saving;
      var balance = document.createElement("p");
      balance.innerHTML = `
      Balance of Saving Account is \$ ${valueS}
      `
      document.querySelector("#balDiv").appendChild(balance);
      accT = type;
    }
    else alert("Not valid account type, check again!");
  }
  else alert("Validate your Customer ID first!");
}); //checked

// Withdraw Button
document.querySelector("#drawB").addEventListener("click", function(){
  var drawAmount = document.querySelector("#withdraw").value;
  if(drawAmount == "") alert("You must enter a value in the text box");
  else {
    drawAmount = parseFloat(drawAmount);
    if(accT == "s" || accT =="S") {
      if(drawAmount <= customers[custIndex].saving){
        alert("Withdraw successful");
        customers[custIndex].saving -= drawAmount;
      }
      else alert("Error! Not enough money!");
    }
    else if(accT == "c" || accT =="C") {
      if(drawAmount <= customers[custIndex].cheque){
        alert("Withdraw successful");
        customers[custIndex].cheque -= drawAmount;
      }
      else alert("Error! Not enough money!");
    }
    else {
      alert("Check your account type first!");
    }
  }
}); //checked

// Deposit Button
document.querySelector("#depositB").addEventListener("click", function(){
  var depositAmount = document.querySelector("#deposit").value;
  if(depositAmount == "") alert("You must enter a value in the text box");
  else {
    depositAmount = parseFloat(depositAmount);
    if(accT == "s" || accT =="S") {
        alert("Deposit successful");
        customers[custIndex].saving += depositAmount;
    }
    else if(accT == "c" || accT =="C") {
        alert("Deposit successful");
        customers[custIndex].cheque += depositAmount; 
    }
    else {
      alert("Check your account type first!");
    }
  }
});