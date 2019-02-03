// This is "assign3.cc", the driver program for CSCI 241 Assignment 3, 
// Autumn, 2008.  It is the work of Harry Hutchins.

#include <iostream>
#include <string>
#include "screen.h"
#include "brush.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
// function prototype
void print_menu();

 Screen S;
 Brush B;
 bool IMFlag = true;
 bool QuitFlag = false;
 string Command;
 char NewColor;
 int NewWidth, NewHeight;
 int NewRow, NewColumn;
 char NewWord[81];

 S.clear();
 print_menu();

// This is the large loop controlling the activities.
 while (!QuitFlag)
  {
   cin >> Command;
   if (Command == "Q")
    QuitFlag = true;     
   else if (Command == "CS")
    S.clear();
   else if (Command == "DISP")
    S.print();
   else if (Command == "NI")
    IMFlag = false;
   else if (Command == "IN")
    IMFlag = true;
   else if (Command == "BP")
    {
     if (IMFlag) cout << "At what row and column should we draw?" << endl;
     cin >> NewRow >> NewColumn;
     B.draw_position(S, NewRow, NewColumn);
    }
   else if (Command == "BC")
    {
     if (IMFlag) cout << "What is the new color?" << endl;
     cin >> NewColor;
     B.set_color(NewColor);
    }
   else if (Command == "BS")
    {
     if (IMFlag) cout << "What are the new width and height?" << endl;
     cin >> NewWidth >> NewHeight;
     B.set_size(NewWidth, NewHeight);
    }
   else if (Command == "BU")
    B.draw_up(S);
   else if (Command == "BD")
    B.draw_down(S);
   else if (Command == "BL")
    B.draw_left(S);
   else if (Command == "BR")
    B.draw_right(S);
   else if (Command == "BUL")
    B.draw_up_left(S);
   else if (Command == "BUR")
    B.draw_up_right(S);
   else if (Command == "BDL")
    B.draw_down_left(S);
   else if (Command == "BDR")
    B.draw_down_right(S);
   else if (Command == "WP")
    {
     if (IMFlag) cout << "At what row and column should we write?" << endl;
     cin >> NewRow >> NewColumn;
     S.set(NewRow, NewColumn);
    }      
   else if (Command == "WD")
    {
     if (IMFlag)  cout << "What word should we write?" << endl;
     cin >> NewWord;
     S.write(NewWord);
    }
   else
    {
     cout << "Command " << Command << " not recognized." << endl;
     print_menu();
    }
   if (IMFlag) S.print();
  }  
 return 0;
}

// All this function does is print the menu on the screen.  It takes no arguments
// and returns no value.

void print_menu()
{
 cout << "Menu:  (commands available to use with the drawing program)" << endl;
 cout << endl;
 cout << "DISP  Print the screen            ";
 cout << "CS     Clear the screen " << endl;
 cout << "NI    Non-interactive mode        ";
 cout << "IN     Interactive mode " << endl;
 cout << "BU    Move up and draw            ";
 cout << "BD    Move down and draw" << endl;
 cout << "BL    Move left and draw          ";
 cout << "BR    Move right and draw" << endl;
 cout << "BUL   Move up and left and draw   ";
 cout << "BUR   Move up and right and draw" << endl;
 cout << "BDL   Move down and left and draw ";
 cout << "BDR   Move down and right and draw" << endl;
 cout << "BP    Set position and draw there" << endl;
 cout << "BC    Set the brush color (one character)" << endl;
 cout << "BS    Set the brush size (width and height)" << endl;
 cout << "WP    Set position for drawing a word" << endl;
 cout << "WD    Write a word at current position" << endl;
 cout << "Q     Quit the program"  << endl;
 cout << endl;
}

