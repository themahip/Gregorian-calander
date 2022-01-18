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
 * Features     : The feature of the program is to ask for the to-do list of user and display it
 * Purpose      : The purpose of the program is for the final evaluation as a mini project of 'Comp102'
 * This program uses camel case to declate the variable
 **/




#include <stdio.h>
#include <stdlib.h>

void append(void);
void write(void);
void read(void);
void clear();


void calendar(int year); // the function is on another file mainCalendar.c

extern int year;  // this variable is in another file mainCalendar.c

/** 
 * feature1() funtion display the first feature of the program that is to-do list and display the menu of to-do list
 *  parameter: no parameters
 *  return value: null
 * */

void feature1(void)
{
  char choice, to_do;

  printf("\n\n\nDo you want to write any to-do list for tommorrow?\n");
  printf("\n press 'Y' for- yes \n press 'N' for- No \n press'S' to show the to-do list:  ");

  scanf("%s", &choice);

  switch (choice)
  {
  case 'Y':

    printf("Do you want to create a new to-do list or write in exsiting one?\n ");
    printf("\n press 'E' to add in Existing list \n Press 'N' for new one \n 'q' to quit:\t");

    scanf("%s", &to_do);

    switch (to_do)
    {
    case 'E':
      append();
      break;
    case 'N':
      write();
      calendar(year);
      break;

    case 'q':
      calendar(year);

      break;
    }
  case 'N':
    break;
  case 'S':
    read();
    break;
  }
}


/** 
 * append() funtion is used to write the to do list on the file without deleting content of the file 
 *  parameter: no parameters
 *  return value: null
 * */

void append(void)
{
  FILE *p;
  char ch;
  p = fopen("main.txt", "a+");
  printf("Write your to do list and press 'q' to quit:\t");
  while (1)
  {
    scanf("%c", &ch);
    if (ch == 'q')
    {
     clear();
      calendar(year);
      break;
    }
    fputc(ch, p);
  }

  fclose(p);
}

/** 
 * Write() funtion is used to write on the file but the previous content is deleted
 *  parameter: no parameters
 *  return value: null
 * */


void write(void)
{
  FILE *p;
  char ch;
  p = fopen("main.txt", "w");
  printf("\n\n Write your to do list and press 'q' to quit:\n\n");
  while (1)
  {
    scanf("%c", &ch);
    if (ch == 'q')
    {
    clear();
      calendar(year);
      break;
    }
    fputc(ch, p);
  }

  fclose(p);
}



/** 
 * read() funtion is used to print the content of the file
 *  parameter: no parameters
 *  return value: null
 * */



void read(void)
{
  FILE *p;
  char ch, c;
  p = fopen("main.txt", "r");

  while (ch != EOF)
  {

    ch = fgetc(p);
    printf("%c", ch);
  }
  fclose(p);
  printf("\nPress q to quit:\t");
  scanf("%s", &c);
  if (c == 'q')
  {
    clear();
    calendar(year);
  }
}
