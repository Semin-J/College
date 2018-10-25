 //--------------------------------------------------
// Name: Semin-J          
// Student Number: 
// Email:         
// Section:        
// Workshop: WS04 at_home
//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

// Place your code below
#include <stdio.h>
int main(void) {
  int day;
  int index;
  int high[10];
  int low[10];
  int highest;
  int highest_day;
  int lowest_day;
  int lowest;
  int pick_day = 0;
  int temp_sum;
  double average;
  printf("---=== IPC Temperature Calculator V2.0 ===---\n");
  printf("Please enter the number of days, between 3 and 10, inclusive: ");
  scanf("%d", &day);
  printf("\n");

  if (day < 3 || day > 10) {
    while (day < 3 || day > 10) {
      printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
      scanf("%d", &day);
      printf("\n");
    }
  }

  for (index = 0; index < day; index++) {
    printf("Day %d - High: ", index + 1);
    scanf("%d", &high[index]);
    printf("Day %d - Low: ", index + 1);
    scanf("%d", &low[index]);
    if (high[index] > high[index - 1]) {
      highest = high[index];
      highest_day = day;
    }
    if (low[index] < low[index - 1]) {
      lowest = low[index];
      lowest_day = day;
    }
  }
  
  printf("\n");
  printf("Day  Hi  Low\n");
  for (index = 0; index < day; index++) {
    printf("%-5d%-5d%-2d\n", index + 1, high[index], low[index]);
  }
  printf("\n");
  printf("The highest temperature was %d, on day %d\n", highest, highest_day);
  printf("The lowest temperature was %d, on day %d\n", lowest, lowest_day);
  printf("\n");

  do {
    printf("Enter a number between 1 and %d to see the average temperature ", day);
    printf("for the entered number of days, enter a negative number to exit: ");
    scanf("%d", &pick_day);
    printf("\n");

    
    while (pick_day > day && pick_day >= 1) {
        printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", day);
        scanf("%d", &pick_day);
        printf("\n");
      }

    temp_sum = 0;
    for (index = 0; index < pick_day; index++) {
      temp_sum += high[index];
      temp_sum += low[index];
    }

    average = (double)temp_sum / (pick_day * 2);
    printf("The average temperature up to day %d is: %.2lf\n", pick_day, average);
    printf("\n");


  } while (pick_day > 0);


  
  printf("Goodbye!\n");


  return 0;
}
