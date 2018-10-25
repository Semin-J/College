/*
Name: Semin-J
Student number:
Email:
Workshop: WS05
Section:
Date: Jun 14th, 2018
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 4	

struct Employee {
  int id;
  int age;
  double salary;
};

/* main program */
int main(void) {
  int option = 0;
  int index = 0;
  int check_id;
  int check_index;
  int remove_id;
  int remove_index;
  struct Employee emp[SIZE] = { {0} };
  printf("---=== EMPLOYEE DATA ===---\n\n");
  do {
    printf("1. Display Employee Information\n");
    printf("2. Add Employee\n");
    printf("3. Update Employee Salary\n");
    printf("4. Remove Employee\n");
    printf("0. Exit\n\n");
    printf("Please select from the above options: ");
    scanf("%d", &option);
    printf("\n");

    switch (option) {
    case 0:	
      printf("Exiting Employee Data Program. Good Bye!!!\n");
      break;

    case 1:
      printf("EMP ID  EMP AGE EMP SALARY\n");
      printf("======  ======= ==========\n");
      for (int i = 0; i < index + 1; i++) {
        if(emp[i].id != 0) {
        printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
        }
      }
      printf("\n");
      break;

    case 2:	
      printf("Adding Employee\n");
      printf("===============\n");
      if (index < SIZE) {
        printf("Enter Employee ID: ");
        scanf("%d", &emp[index].id);
        printf("Enter Employee Age: ");
        scanf("%d", &emp[index].age);
        printf("Enter Employee Salary: ");
        scanf("%lf", &emp[index].salary);
        printf("\n");
        index++;
      }
      else {
        printf("ERROR!!! Maximum Number of Employees Reached\n\n");
      }
      break;

    case 3:
      printf("Update Employee Salary\n");
      printf("======================\n");
      printf("Enter Employee ID: ");
      scanf("%d", &check_id);
      check_index = 0;
      do {
        if (check_id == emp[check_index].id) {
        printf("The current salary is %.2lf\n", emp[check_index].salary);
        printf("Enter Employee New Salary: ");
        scanf("%lf", &emp[check_index].salary);
        printf("\n");
        check_index = SIZE;
        }
        else {
        check_index++;
        }
      
      } while (check_index < SIZE);
      break;

    case 4:
      printf("Remove Employee\n");
      printf("===============\n");
      printf("Enter Employee ID: ");
      scanf("%d", &remove_id);
	  int remove_i = -1;
      remove_index = 0;
      do {
        if (remove_id == emp[remove_index].id) {
          emp[remove_index].id = 0;
          emp[remove_index].age = 0;
          emp[remove_index].salary = 0;
		  remove_i = remove_index;
		  break;
        }
        else {
          remove_index++;
        }
      } while (remove_index < SIZE);
     
	  if (remove_i != -1 && remove_i < SIZE - 1) {
		  for (int i = remove_i + 1; i < SIZE; i++) {
			  //emp[i - 1].id = emp[i].id;
			  //emp[i - 1].age = emp[i].age;
			  //emp[i - 1].salary = emp[i].salary;
        emp[i - 1] = emp[i];
		  }
	  }

      printf("Employee %d will be removed\n\n", remove_id);
      index--;
      break;

    default:
      printf("ERROR: Incorrect Option: Try Again\n\n");
    }

  } while (option != 0);

  return 0;
}
