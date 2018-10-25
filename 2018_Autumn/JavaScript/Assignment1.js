/***
******************************************************************************
*
WEB
–
Assignment 01
*

*
Name: Semin Jeon  Date: 09/25/2018
*
**********************************
**********************************************/

/*****************************
Task 1: Student Info
*****************************/
var name, course, program, job;
name = "Semin Jeon";
course = 4;
program = "CPD";
job = "false";
console.log( 
"My name is " + name + " and I’m in " + program + " program. I’m taking " + course + " course" + (course > 1 ? 's' : '') +" in this semester and I " + (job == "true" ? "have" : "don't have") + " a part‐time job now.");


/*****************************
Task 2: Birth and graduate year
*****************************/
var current = 2018;
var age, birth, duration;
age = parseInt(prompt("Please enter your age"));
birth = prompt("Your birthday of this year is passed? (y/n)");
console.log("You were born in the year of " + (birth == "y" ? (current - age) : (current - age - 1)) + ".");
duration = parseInt(prompt("Enter the number of years you expect to study in the college:"));
console.log("You will graduate from Seneca college in the year of " + (current+duration)  + ".");


/*****************************
Task 3: Celsius and Fahrenheit temperatures
*****************************/
const tempC = 27, tempF = 123;
console.log(tempC + "°C is " + (tempC * 9 / 5 + 32) + "°F.");
console.log(tempF + "°F is " + ((tempF - 32) * 5 / 9).toFixed(1) + "°C.");


/*****************************
Task 4: Even and odd numebers
*****************************/
for(var i = 0; i <= 10; i++) {
  console.log(i + " is " + (i % 2 == 0 ? "even" : "odd"));
}


/*****************************
Task 5: Larger or largest number
*****************************/
//Function Declaration
function largerNum(num1, num2) {
  var larger = (num1 >= num2 ? num1 : num2);
  return larger;
}


//Function Expression
var greaterNum = function(num1, num2) {
  var greater = (num1 >= num2 ? num1 : num2);
  return greater;
}

var num1 = 15, num2 = 38, num3 = 26, num4 = 74;

console.log("The larger number of " + num1 + " and " + num2 + " is " + largerNum(num1, num2) + ".");
console.log("The larger number of " + num3 + " and " + num4 + " is " + largerNum(num3, num4) + ".");

console.log("The larger number of " + num1 + " and " + num3 + " is " + greaterNum(num1, num3) + ".");
console.log("The larger number of " + num2 + " and " + num4 + " is " + greaterNum(num2, num4) + ".");


/*****************************
Task 6: Evaluator
*****************************/
function Evaluator() {
  var sum = 0;
  for(var i = 0; i < arguments.length; i++) {
    sum += arguments[i];
  }
  var avg = sum / arguments.length;
  //console.log(avg);
  var value = (avg >= 50 ? true : false);
  return value;
}

console.log("Average is greater than or equal to 50: " + Evaluator(40, 60));
console.log("Average is greater than or equal to 50: " + Evaluator(40, 60, 80));
console.log("Average is greater than or equal to 50: " + Evaluator(40, 60, 10, 20));



/*****************************
Task 7: Grader
*****************************/
var Grader = function(score) {
  var grade;
  if (score >= 80) {
    grade = "A";
  }
  else if (score < 80 && score >= 70 ) {
    grade = "B";
  }
  else if (score < 70 && score >= 60) {
    grade = "C";
  }
  else if (score < 60 && score >= 50) {
    grade = "D";
  }
  else {
    grade = "F"
  }
  return grade;
}

var score1 = 69.9, score2 = 83, score3 = 34
console.log("%d is %s", score1, Grader(score1));
console.log("%d is %s", score2, Grader(score2));
console.log("%d is %s", score3, Grader(score3));


/*****************************
Task 8: ShowMultiples
*****************************/
function showMultiples(num, numMultiples) {
  console.log("%d's multiple table from 1 to %d", num, numMultiples);
  for(var i = 1; i <= numMultiples; i++) {
    console.log("%d x %d = %d", num, i, num*i);
  }
}

showMultiples(2, 7);
showMultiples(13, 4);
showMultiples(6, 5);

