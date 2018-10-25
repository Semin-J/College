/* -------------------------------------------
Name: Semin-J
Student number: 
Email: 
Section: 
Date: July.29th.2018
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"
#include "contacts.h"
// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+
char choice;

// getName:
void getName(struct Name *name) {
  //first name
  printf("Please enter the contact's first name: ");
  scanf("%[^\n]", name->firstName);
  clearKeyboard();

  //middle name
  printf("Do you want to enter a middle initial(s)? (y or n): ");
  choice = yes();
  if (choice == 1) {
    printf("Please enter the contact's middle initial(s): ");
    scanf("%s", name->middleInitial);
    clearKeyboard();
  }
  else {
    char emp[7];
    strcpy(name->middleInitial, emp);
  }
  //last name
  printf("Please enter the contact's last name: ");
  scanf("%[^\n]", name->lastName);
  clearKeyboard();
}


// getAddress:
void getAddress(struct Address* address) {
  //street number
  printf("Please enter the contact's street number: ");
  address->streetNumber = getInt();
  //street name
  printf("Please enter the contact's street name: ");
  scanf("%[^\n]", address->street);
  clearKeyboard();
  //apartment number
  printf("Do you want to enter an apartment number? (y or n): ");
  choice = yes();
  if (choice == 1) {
    printf("Please enter the contact's apartment number: ");
    scanf("%d", &address->apartmentNumber);
    clearKeyboard();
  }
  else {
    address->apartmentNumber = 0;
  }
  //postal code
  printf("Please enter the contact's postal code: ");
  scanf("%[^\n]", address->postalCode);
  clearKeyboard();
  //city
  printf("Please enter the contact's city: ");
  scanf("%[^\n]", address->city);
  clearKeyboard();
}


// getNumbers:
void getNumbers(struct Numbers* numbers) {
  //cell phone
  printf("Please enter the contact's cell phone number: ");
  getTenDigitPhone(numbers->cell);

  //home phone
  printf("Do you want to enter a home phone number? (y or n): ");
  choice = yes();
  if (choice == 1) {
    printf("Please enter the contact's home phone number: ");
    getTenDigitPhone(numbers->home);
  }
  else {
    char emp[11] = { 0 };
    strcpy(numbers->home,emp);
  }
  //business phone
  printf("Do you want to enter a business phone number? (y or n): ");
  choice = yes();
  if (choice == 1) {
    printf("Please enter the contact's business phone number: ");
    getTenDigitPhone(numbers->business);
  }
  else {
    char emp[11] = { 0 };
    strcpy(numbers->business, emp);
  }
}


// getContact
void getContact(struct Contact contacts[]) {
  getName(&contacts->name);
  getAddress(&contacts->address);
  getNumbers(&contacts->numbers);
}