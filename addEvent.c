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
 * Features     : The feature of the program is to ask for the special event and display on the screen
 * Purpose      : The purpose of the program is for the final evaluation as a mini project of 'Comp102'
 * This program uses camel case to declate the variable
 **/

#include <stdio.h>
#include <stdlib.h>

extern int year;
void clear();

void calendar(int year); // this function is on another file mainCalendar.c

struct event // structure to store the date month and the event
{

  int month;
  int day;
  char yourEvent[100];

} event;

/**
 * add_event() function asks the user to add event and append on the file
 * parameter: no parameter 
 * return value: null
 */
void add_event()
{
  int choice;

  FILE *fp;
  fp = fopen("event.txt", "a");

  printf("----------ADD EVENT-----------\n\n");
  printf("1. Add event\n");

  printf("2. quit\n\n");
  

  printf("choose(1/2):\t ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    printf("\n\n Enter the dd/mm(Ex: 3/4 for 3 of april):\t");
    scanf("%d/%d", &event.day, &event.month);
    printf("what is the event:\n");
    scanf(" %[^\n]s", event.yourEvent);
    fwrite(&event, sizeof(event), 1, fp);
    fclose(fp);

    clear();
    calendar(year);

    break;

  case 2:
    clear();
    calendar(year);

    break;
  }
}

/**
 * print_event() function is used to print the events stored on the file
 * parameter: no parameter 
 * return value: null
 */

void print_event()
{
  FILE *fp;
  char *months[] = {"\0", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}; // the array is used to convert the month entered by user in int format to string.

  fp = fopen("event.txt", "r");

  while (fread(&event, sizeof(event), 1, fp))
  {

    printf("        %d-%s \t     %s \n", event.day, months[event.month], event.yourEvent);
  }
  fclose(fp);
}