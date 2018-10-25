/* -------------------------------------------
Name: Semin-J
Student number:
Email:
Section:
Date:July.14th.2018
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

char choice; //The variable for y or n, global variable
int size; //size(length) of string
int num; //return from isalpha to check alphabet/number
int i;
// Put your code here that defines the Contact getName function:
int check(const char name[]) {
  size = strlen(name);
  for (i = 0; i < size; i++) {
    if (isalpha(name[i]) == 0) {
      printf("Each letter should be an alphabetic\n");
      //num++;
      return 1;
    }
  }
  return 0;
}

void getName(struct Name *name) {
  //first name
  do {
    printf("Please enter the contact's first name: ");
    scanf("%s", name->firstName);
    num = check(name->firstName);
  } while (num != 0);
  //middle name
  printf("Do you want to enter a middle initial(s)? (y or n): ");
  scanf(" %c", &choice);
  if (choice == 'y' || 'Y') {
    printf("Please enter the contact's middle initial(s): ");
    scanf(" %s", name->middleInitial);
  }
  //last name
  printf("Please enter the contact's last name: ");
  scanf(" %s", name->lastName);
}


// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address* address) {
  //street number
  printf("Please enter the contact's street number: ");
  scanf(" %d", &address->streetNumber);
  //street name
  printf("Please enter the contact's street name: ");
  scanf(" %s", address->street);
  //apartment number
  printf("Do you want to enter an apartment number? (y or n): ");
  scanf(" %c", &choice);
  if (choice == 'y' || 'Y') {
    printf("Please enter the contact's apartment number: ");
    scanf(" %d", &address->apartmentNumber);
  }
  //postal code
  printf("Please enter the contact's postal code: ");
  scanf(" %[^\n]", address->postalCode);
  //city
  printf("Please enter the contact's city: ");
  scanf(" %s", address->city);
}



// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers* numbers) {
  //cell phone
  printf("Do you want to enter a cell phone number? (y or n): ");
  scanf(" %c", &choice);
  if (choice == 'y' || 'Y') {
    printf("Please enter the contact's cell phone number: ");
    scanf(" %s", numbers->cell);
  }
  //home phone
  printf("Do you want to enter a home phone number? (y or n): ");
  scanf(" %c", &choice);
  if (choice == 'y' || 'Y') {
    printf("Please enter the contact's home phone number: ");
    scanf(" %s", numbers->home);
  }
  //business phone
  printf("Do you want to enter a business phone number? (y or n): ");
  scanf(" %c", &choice);
  if (choice == 'y' || 'Y') {
    printf("Please enter the contact's business phone number: ");
    scanf(" %s", numbers->business);
  }
}

// ++ additional function for Displaying Summary
void displaySummary(const struct Contact* contacts) {
  printf("\n");
  printf("Contact Details\n---------------\n");
  printf("Name Details\nFirst name: %s\nMiddle initial(s): %s\nLast name: %s\n",
         contacts->name.firstName, contacts->name.middleInitial, contacts->name.lastName);
  printf("\n");
  printf("Address Details\nStreet number: %d\nStreet name: %s\nApartment: %d\n"
         "Postal code: %s\nCity: %s\n", contacts->address.streetNumber, contacts->address.street,
         contacts->address.apartmentNumber, contacts->address.postalCode, contacts->address.city);
  printf("\n");
  printf("Phone Numbers:\nCell phone number: %s\nHome phone number: %s\n"
         "Business phone number: %s\n", contacts->numbers.cell, contacts->numbers.home, contacts->numbers.business);
  printf("\n");
}
