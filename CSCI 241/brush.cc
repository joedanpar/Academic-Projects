/************************************************************
* CSCI 241                                       Autumn, 2008
* Name: Joe Daniel Parker
* Assignment 3
* Due Date: 09/23/2008
* Purpose: This is the implementation for the brush header
           for the drawing program.
************************************************************/

//#include <iostream>
//#include <iomanip>
#include "screen.h"
#include "brush.h"

/* Namespaces used */
//using std::cout;
//using std::endl;

/* This is the constructor for the brush */
Brush::Brush()
  {
  row_pos = 0;
  col_pos = 0;
  width = 1;
  height = 1;
  color = '.';
  }
  
/* This function draws on the screen at a given position with a given width and height. */
const void Brush::draw(Screen& S)
  {
  int row,
      col;
  for (row = row_pos; row < row_pos + height; row++)
    {
    for (col = col_pos; col < col_pos + width; col++)
      {
      S.plot(row, col, color);
      }
    }
  }
  
/* This function takes a character and sets it to be the brush's color. */
const void Brush::set_color(char& c)
  {
  color = c;
  }
  
/* This function takes two integers and sets them to be the brush's new width and height, respectively */
const void Brush::set_size(int& x, int& y)
  {
  width = x;
  height = y;
  }
  
/* This function takes a temporary position and sets it to the drawing pad position, and draws at that point */
const void Brush::draw_position(Screen& S, int& temp_row, int& temp_col)
  {
  row_pos = temp_row;
  col_pos = temp_col;
  S.plot(row_pos, col_pos, color);
  }
  
/* This function sets the current position to one spot to its left, and draws at that point */
const void Brush::draw_left(Screen& S)
  {
  col_pos -=1;
  draw(S);
  }
  
/* This function sets the current position to one spot to its right, and draws at that point */
const void Brush::draw_right(Screen& S)
  {
  col_pos +=1;
  draw(S);
  }
  
/* This function sets the current position to one spot above it, and draws at that point */
const void Brush::draw_up(Screen& S)
  {
  row_pos -=1;
  draw(S);
  }
  
/* This function sets the current position to one spot below it, and draws at that point */
const void Brush::draw_down(Screen& S)
  {
  row_pos +=1;
  draw(S);
  }
  
/* This function sets the current position to one spot up and to its left, and draws at that point */
const void Brush::draw_up_left(Screen& S)
  {
  row_pos -=1;
  col_pos -=1;
  draw(S);
  }
  
/* This function sets the current position to one spot up and to its right, and draws at that point */
const void Brush::draw_up_right(Screen& S)
  {
  row_pos -=1;
  col_pos +=1;
  draw(S);
  }
  
/* This function sets the current position to one spot down and to its left, and draws at that point */
const void Brush::draw_down_left(Screen& S)
  {
  row_pos +=1;
  col_pos -=1;
  draw(S);
  }
  
/* This function sets the current position to one spot down and to its right, and draws at that point */
const void Brush::draw_down_right(Screen& S)
  {
  row_pos +=1;
  col_pos +=1;
  draw(S);
  }
