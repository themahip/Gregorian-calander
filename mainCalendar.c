/**
 * Author       :Mahip Adhikari
 * University   :Kathmandu University 
 * Faculty      :Computer Engineering 
 * Source Language : The language used in this program is 'C'
 * 
 * 
 * 
 * 
 * Discription  : This program display the Gregorian calendar of any desired year
 * Features     : The features of the program is it display the calendar of any year of gregorian calendar. It also has the feature to add to-do list and add special event for any particular year
 * Purpose      : The purpose of the program is for the final evaluation as a mini project of 'Comp102'
 * 
 * 
 * 
 * This program uses camel case to declate the variable
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/** 
  * 
  * Declearing the function.
  */

void feature1(void);

int get_1st_weekday(int year);
void current_date(void);
void features(); 
void calendar(int year);
void special_event(void); // the program is on another file addEvent.c
void add_event(); // the program is on another file addEvent.c
void print_event(); // the program is on another file addEvent.c
int year;

/**
 * front_page() function shows first view of the program which clears the screen and ask user to enter the desire year
 * parameter: no parameter
 * return value: null
 */
void clear(){
    #ifdef _WIN32 //identifying the os of user and clearing the screen accordingly
    system("cls");
    #else
    system ("clear");
    #endif
  }  

  
void front_page()
{
  clear();
  current_date();
  printf("\nEnter your desired year:");
  scanf("%d", &year);
  calendar(year);
}

int main() // main function
{
  front_page();
}
void calendar(int year)
{
  clear();
  int month, day, daysInMonth, weekDay = 0, startingDay; // declaration

  char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; // Array of the month used in
  int monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};                                                                           // array of no of days in month

  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) // algorithm to find the leap year
    monthDay[1] = 29;

  startingDay = get_1st_weekday(year);

  for (month = 0; month < 12; month++)
  {

    daysInMonth = monthDay[month];
    printf("\n\n--------------%s-------------\n", months[month]);
    printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

    for (weekDay = 0; weekDay < startingDay; weekDay++)
      printf("     ");

    for (day = 1; day <= daysInMonth; day++)
    {
      printf("%5d", day);

      if (++weekDay > 6)
      {
        printf("\n");

        weekDay = 0;
      }
      startingDay = weekDay;
    }
  }
  special_event();

  features();
}

/**
 * this function uses the algorithm to find the 1st week day of any desired year having argument year
 * parameter : year entered by the user
 * return: it returns the first weekday of the year as a integer
 */

int get_1st_weekday(int year)
{
int d;
  int firstDay;
  d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
  return firstDay; 
}

/**
 * current_date() function is used to display the current date and time of the function
 * parameter: no parameters
 * return value: null
 * 
 *  */
void current_date(void)
{
  time_t t;
  time(&t);
  printf("\n\nToday is %s\n", ctime(&t));
}

/** 
 * features() function display the feature availabe in the program and it returns the value choosen by the user
 *  parameter: no parameters
 * return value: null
 * 
 * */
void features()
{
  int choose_features;
  printf("\n\n-------Features--------\n\n");
  printf("1. To-DO list\n");
  printf("2. Add the special day of the year\n");
  printf("3. Reload the program.\n");
  printf("press(1/2/3) and press enter:\n");

  scanf("%d", &choose_features);

  if (choose_features == 1)
  {
    feature1();
  }

  else if (choose_features == 2)
  {
    add_event();
  }
  else if (choose_features == 3)
  {
    front_page();
  }
  else
  {
    clear();
    calendar(year);
  }
}

/**
 * special_event() function shows some default event like new year and christmas day and user can add any other events
 * parameter: no parameters
 * return value: null
 * */

void special_event(void)
{
  int choose_features;
  printf("\n\n**************Special Events*************\n\n");
  printf("       Date            Event\n\n");
  printf("       1-jan         New Year\n");
  printf("       25-dec        Christmas Day\n");

  print_event();

  printf("\n\n*********************************************\n");
}
