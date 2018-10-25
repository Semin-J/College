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


// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"
#include "contacts.h"

// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void) {
  while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void) {
  printf("(Press Enter to Continue)");
  clearKeyboard();
}

// getInt:
int getInt(void) {
  int Value;
  char NL = 'x';
  do {
    scanf("%d%c", &Value, &NL);
    if (NL != '\n') {
      printf("*** INVALID INTEGER *** <Please enter an integer>: ");
      clearKeyboard();
    }
  } while (NL != '\n');
  return Value;
}

// getIntInRange:
int getIntInRange(int num1, int num2) {
    int num;
    do {
      num = getInt();
      if (num < num1 || num > num2) {
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", num1, num2);
      }
    } while (num < num1 || num > num2);
    return num;
 }


// yes:
  int yes(void) {
    char Value;
    char NL = 'x';
    int ret;
    do {
      scanf("%c%c", &Value, &NL);
      if ((Value == 'y' || Value == 'Y') && (NL == '\n')) {
        ret = 1;
        return ret;
      }
      else if ((Value == 'n' || Value == 'N') && (NL == '\n')) {
        ret = 0;
        return ret;
      }

      if ((Value != 'y' || 'Y' || 'n' || 'N') || (NL != '\n')) {
        printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        clearKeyboard();
      }
    } while ((Value != 'y' || 'Y' || 'n' || 'N') || (NL != '\n'));
 }

// menu:
 int menu(void) {
    int choice;
    printf("Contact Management System\n"
           "-------------------------\n"
           "1. Display contacts\n"
           "2. Add a contact\n"
           "3. Update a contact\n"
           "4. Delete a contact\n"
           "5. Search contacts by cell phone number\n"
           "6. Sort contacts by cell phone number\n"
           "0. Exit\n\n"
           "Select an option:> ");
    choice = getIntInRange(0, 6);
    return choice;
 }

 
// ContactManagerSystem:
 void ContactManagerSystem(void) {
   struct Contact contacts[MAXCONTACTS] = 
   { { { "Rick", {0} , "Grimes" },
     { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
     { "4161112222", "4162223333", "4163334444" } },
     { { "Maggie", "R.", "Greene" },
     { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
     { "9051112222", "9052223333", "9053334444" } },
     { { "Morgan", "A.", "Jones" },
     { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
     { "7051112222", "7052223333", "7053334444" } },
     { { "Sasha", {0} , "Williams" },
     { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
     { "9052223333", "9052223333", "9054445555" } }, };
   char ch;
   int ter = 1;

   while (ter == 1) {
     int choice = menu();
     switch (choice) {
     case 1:
       printf("\n");
       displayContacts(contacts, MAXCONTACTS);
       pause();
       printf("\n");
       break;
     case 2:
       printf("\n");
       addContact(contacts, MAXCONTACTS);
       pause();
       printf("\n");
       break;
     case 3:
       printf("\n");
       updateContact(contacts, MAXCONTACTS);
       pause();
       printf("\n");
       break;
     case 4:
       printf("\n");
       deleteContact(contacts, MAXCONTACTS);
       pause();
       printf("\n");
       break;
     case 5:
       printf("\n");
       searchContacts(contacts, MAXCONTACTS);
       pause();
       printf("\n");
       break;
     case 6:
       printf("\n<<< Feature to sort is unavailable >>>\n\n");
       pause();
       printf("\n");
       break;
     case 0:
       printf("\nExit the program? (Y)es/(N)o: ");
       ch = yes();
       if (ch == 1) {
         printf("\nContact Management System: terminated\n");
         ter++;
         break;
       }
       else
         printf("\n");
       break;

     }
   }
 }

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
 void getTenDigitPhone(char telNum[]) {
   int needInput = 1;
   //int i;

   while (needInput == 1) {
     scanf("%10s", telNum);
     clearKeyboard();

     // (String Length Function: validate entry of 10 characters)
     if (strlen(telNum) == 10) {
       /*for (i = 0; i < 10; i++) {
       if (telNum[i] < 48 || telNum[i] > 57) {
       printf("All digits should be numeric numbers\n");
       printf("Enter a 10-digit phone number: ");
       break;
       } break;
       } break;*/
       needInput = 0;
     }

     else
       printf("Enter a 10-digit phone number: ");
   }
 }

// findContactIndex:
 int findContactIndex(const struct Contact contacts[], int num, const char cell[]) {
   int index = 0;
   int i;
   for(i = 0; i < MAXCONTACTS; i++) {
   if (strcmp(contacts[i].numbers.cell, cell) == 0) {
     index = i;
     break;
     }
   else {
     index = -1;
     }
   }
   return index;
 }

// displayContactHeader
 void displayContactHeader(void) {
   printf("+-----------------------------------------------------------------------------+\n"
          "|                              Contacts Listing                               |\n"
          "+-----------------------------------------------------------------------------+\n");
 }

// displayContactFooter
 void displayContactFooter(int cnt) {
   printf("+-----------------------------------------------------------------------------+\n"
          "Total contacts: %d\n\n", cnt);
 }

// displayContact:
 void displayContact(const struct Contact* contacts) {
   printf(" %s", contacts->name.firstName);
   if (*contacts->name.middleInitial != 0) {
     printf(" %s",contacts->name.middleInitial);
   }
   printf(" %s\n", contacts->name.lastName);
   printf("    C: %-10s   H: %-10s   B: %-10s\n", contacts->numbers.cell, contacts->numbers.home, contacts->numbers.business);
   printf("       %d %s, ", contacts->address.streetNumber, contacts->address.street);
   if (contacts->address.apartmentNumber > 0) {
     printf("Apt# %d, ", contacts->address.apartmentNumber);
   }
   printf("%s, %s\n", contacts->address.city, contacts->address.postalCode);
 }

// displayContacts:
 void displayContacts(const struct Contact contacts[], int num) {
   int i;
   int cnt = 0;
   displayContactHeader();
   for (i = 0; i < MAXCONTACTS; i++) {
     if (strlen(contacts[i].numbers.cell) != 0) {
       displayContact(&contacts[i]);
       cnt++;
     }
   }
   displayContactFooter(cnt);
 }

// searchContacts:
 void searchContacts(const struct Contact contacts[], int num) {
   char cell[11];
   int index;
   printf("Enter the cell number for the contact: ");
   getTenDigitPhone(cell);
   printf("\n");
   index = findContactIndex(contacts, MAXCONTACTS, cell);
   if (index != -1) {
   displayContact(&contacts[index]);
   printf("\n");
   }
   else {
     printf("*** Contact NOT FOUND ***\n");
   }
 }

// addContact:
 void addContact(struct Contact contacts[], int num) {
   int i;
   int index, cnt = 0;
   for (i = 0; i < MAXCONTACTS; i++) {
     if (strlen(contacts[i].numbers.cell) != 0) {
       cnt++;
     }
   }
   if (cnt == MAXCONTACTS) {
     printf("*** ERROR: The contact list is full! ***\n");
   }
   else {
     for (i = 0; i < MAXCONTACTS; i++) {
       if (strlen(contacts[i].numbers.cell) == 0) {     
         index = i;
         getContact(&contacts[index]);
         printf("--- New contact added! ---\n");
         break;
       }
     }  
     
   }
 }

// updateContact:
 void updateContact(struct Contact contacts[], int num) {
   char cell[11];
   int index;
   int ch;
   printf("Enter the cell number for the contact: ");
   getTenDigitPhone(cell);
   index = findContactIndex(contacts, num, cell);
   if (index == -1) {
     printf("*** Contact NOT FOUND ***\n");
   }
   else {
     printf("\n");
     printf("Contact found:\n");
     displayContact(&contacts[index]);
     printf("\n");
     printf("Do you want to update the name? (y or n): ");
     ch = yes();
     if (ch == 1)
       getName(&contacts[index].name);
     printf("Do you want to update the address? (y or n): ");
     ch = yes();
     if (ch == 1)
       getAddress(&contacts[index].address);
     printf("Do you want to update the numbers? (y or n): ");
     ch = yes();
     if (ch == 1)
       getNumbers(&contacts[index].numbers);
     printf("--- Contact Updated! ---\n");
   }
 }

// deleteContact:
 void deleteContact(struct Contact contacts[], int num) {
   char cell[11];
   int index;
   int ch;
   printf("Enter the cell number for the contact: ");
   getTenDigitPhone(cell);
   printf("\n");
   index = findContactIndex(contacts, MAXCONTACTS, cell);
   if (index == -1) {
     printf("*** Contact NOT FOUND ***\n");
   }
   else {
     printf("Contact found:\n");
     displayContact(&contacts[index]);
     printf("\n");
     printf("CONFIRM: Delete this contact? (y or n): ");
     ch = yes();
     if (ch == 1) {
       *contacts[index].numbers.cell = 0;
       printf("--- Contact deleted! ---\n");
     }
   }
 }

// sortContacts:
 //void sortContacts(struct Contact contacts[], int num) {

 //}