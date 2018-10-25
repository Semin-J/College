/* -------------------------------------------
Name: Semin-Je
Student number: 
Email: 
Section: 
Date: July.14th.2018
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"


// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:


int main(void)
{
    // Declare variables here:
  struct Contact contacts = { {{'\0'}}, {0, {'\0'}, 0, {'\0'}, {'\0'}},{{'\0'}}};
    // Create a variable of type Contact and call it something self-describing like "contact"
    // - HINT: Be sure to initialize the values to 0 and empty C strings
    // Display the title
  printf("Contact Management System\n");
  printf("-------------------------\n");

    // Call the Contact function getName to store the values for the Name member
  getName(&contacts.name); //??should I have to pass the address even if that is struct?
    
    // Call the Contact function getAddress to store the values for the Address member
  getAddress(&contacts.address);
    
    // Call the Contact function getNumbers to store the values for the Numbers member
  getNumbers(&contacts.numbers);
  
    // Display Contact summary details
  displaySummary(&contacts);
   
    // Display Completion Message
  printf("Structure test for Contact using functions done!\n");
    
    return 0;
}
