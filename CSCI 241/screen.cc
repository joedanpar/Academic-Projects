/************************************************************
* CSCI 241                                       Autumn, 2008
* Name: Joe Daniel Parker
* Assignment 3
* Due Date: 09/23/2008
* Purpose: Implement the screen.h header file to manipulate
           the drawing screen
************************************************************/

#include <iostream>
#include <iomanip>
#include "screen.h"

/* Namespaces used */
using std::cout;
using std::endl;

/* The constructor */
Screen::Screen()
  {
  clear();
  }
  
/* This function resets the drawing area to a blank slate by setting each element in the array to a space */
const void Screen::clear()
  {
  for (cur_row = 0; cur_row < MAX_ROW; cur_row++)
    {
      for (cur_col = 0; cur_col < MAX_COL; cur_col++)
        {
        array[cur_row][cur_col] = ' ';
        }
    }
  cur_row = 0;
  cur_col = 0;
  }
  
/* This function prints the drawing area to the screen, cell by cell */
const void Screen::print()
  {
  cout << endl;
  for (cur_row = 0; cur_row < MAX_ROW; cur_row++)
    {
      for (cur_col = 0; cur_col < MAX_COL; cur_col++)
        {
        cout << array[cur_row][cur_col];
        }
    cout << endl;
    }
  }

/* This function takes two integers and sets the current position on the drawing pad to those integers */
const void Screen::set(int set_row, int set_col)
  {
  cur_row = set_row;
  cur_col = set_col;
  }
  
/* this function determines if the integers passed into it are within the bounds of the drawing pad, and if they are, color in that cell */
const void Screen::plot(int set_row, int set_col, char input)
  {
  if (0 <= set_row && set_row < MAX_ROW)
    {
    if (0 <= set_col && set_col < MAX_COL)
      {
      set(set_row, set_col);
      array [cur_row][cur_col] = input;
      }
    }
  }
  
/* This function takes a C-style string and displays it at the current position on the drawing pad */
const void Screen::write(char* input)
  {
  //while (*input != '\0')
    //{
    while (*input != '\n' || *input != '\0')
      {
      array [cur_row][cur_col] = *input;
      cur_col++;
      input++;
      }
    //cur_col = 0;
    //cur_row++;
    //input++;
    //}
  print();
  }
