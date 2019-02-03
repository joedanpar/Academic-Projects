/************************************************************
* CSCI 241                                       Autumn, 2008
* Name: Joe Daniel Parker
* Assignment 1
* Due Date: 09/11/2008
* Purpose: find the coefficients of the line that best fits
*          the points given.
************************************************************/

#include <iostream>
#include <iomanip>
#define ENDGROUP -777.00
#define ENDFILE -999.00

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;

//Prototypes
int EndGroup(float X, float Y);
int AllDone(float X, float Y);
void PrintPoint(int N, float X, float Y);
void GroupSummary(float Slope, float YInt);

// start of program.
int main()
    {
    float X = 0,
          Y = 0,
          sumX = 0,
          sumY = 0,
          sumX2 = 0,
          sumY2 = 0,
          sumXY = 0,
          MeanX = 0,
          MeanY = 0,
          Slope = 0,
          YInt = 0;
    int   N = 0;
    
    do
      {
      do
        {
        cin >> X;
        cin >> Y;
        // this checks to see whether or not BOTH files, and BOTH files only, are either -777.00 or -999.00
        // if only one of them are, then it will still run the loop.
        if ( ( X != ENDGROUP && Y != ENDGROUP && X != ENDFILE && Y != ENDFILE ) ||
           ( X != ENDGROUP && Y == ENDGROUP ) ||
           ( X == ENDGROUP && Y != ENDGROUP ) ||
           ( X != ENDFILE && Y == ENDFILE ) ||
           ( X == ENDFILE && Y != ENDFILE ) )
           {
           sumX += X;
           sumY += Y;
           sumX2 += X*X;
           sumY2 += Y*Y;
           sumXY += X*Y;
           N++;
           PrintPoint( N, X, Y );
           }
        }
      while ( !EndGroup( X, Y ) );
    
      MeanX = sumX / N;
      MeanY = sumY / N;
      Slope = ( sumXY - MeanY * sumX ) / ( sumX2 - MeanX * sumX );
      YInt  = MeanY - Slope * MeanX;
      GroupSummary(Slope, YInt);
      if ( YInt != ENDFILE )  // I know that the last group is the only group whose Y-intercept is at -999.00,
                              // so if it's not that group, print the line
        cout << "_____________________________________" << endl << endl;
        
      // clear out the values for the next group.
      N = 0;
      sumX = 0;
      sumY = 0;
      sumX2 = 0;
      sumY2 = 0;
      sumXY = 0;
      }
    while ( !AllDone(X,Y) );
    return 0;
    }
    
// checks to see if both the X and Y values are at -777.00, if they are, return a 1, if not, return a 0.
int EndGroup ( float x, float y )
    {
    if ( x == ENDGROUP && y == ENDGROUP )
       return 1;
    else
       return 0;
    }
    
// checks to see if both the X and Y values are at -999.00, if they are, return a 1, if not, return a 0.
int AllDone ( float x, float y )
    {
    if ( x == ENDFILE && y == ENDFILE )
       return 1;
    else
       return 0;
    }
    
// Print the point being processed at the time.
void PrintPoint ( int n, float x, float y )
    {
    cout << "Point " << n << ": X = " << setprecision(2) << fixed << x << " and Y = " << y << "." << endl;
    }

// Print out the average slope and the y-intercept for the group of points given.
void GroupSummary ( float Slope, float YInt )
    {
    cout << endl << "Slope = " << setprecision(2) << fixed << Slope << endl;
    cout << "Y-Intercept = " << setprecision(2) << fixed << YInt << endl;
    }
