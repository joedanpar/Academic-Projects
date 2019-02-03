/******************************************************************************
CSCI 240 - Program 11a - Spring 2008

Name: Joe Dan Parker
Z-Number: 158012
Section: 8
TA: Kalpana Mangalarapu

Purpose: To read input, fill in a structure, and write the structure to disk
         repeatedly until there is no more input.
******************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

//-----------< function prototypes >-------------

struct CreditAccount
{
char   AccNum[20],
       LastName[21],
	   FirstName[21];
int    ExpireMon,
       ExpireYear;
double CredLimit,
       CurrBal;
};


//-----------< entry point of program >----------

int main ( )
{
CreditAccount acc;
	
ifstream inFile;

ofstream outFile;

/*int total_num = 0, similar_num = 0;
int num_pare1 = 0, num_pare2 = 0;*/
	
inFile.open("accountinfo.txt");  // open the source code file
outFile.open("accounts");  // open the output file
	
if ( inFile.fail() || outFile.fail() )
  {
  cout << "At least one of the files does not exist\n";
  exit(1);
  }


//While there are non-empty lines in the files

while ( inFile )
  {
  inFile >> acc.AccNum;
  inFile >> acc.LastName;
  inFile >> acc.FirstName;
  inFile >> acc.ExpireMon;
  inFile >> acc.ExpireYear;
  inFile >> acc.CredLimit;
  inFile >> acc.CurrBal;
  
  outFile << acc.AccNum << '\n';
  outFile << acc.LastName << '\n';
  outFile << acc.FirstName << '\n';
  outFile << acc.ExpireMon << '\n';
  outFile << acc.ExpireYear << '\n';
  outFile << acc.CredLimit << '\n';
  outFile << acc.CurrBal << '\n';
  
  cout << acc.AccNum << endl;
  cout << acc.LastName << endl;
  cout << acc.FirstName << endl;
  cout << acc.ExpireMon << endl;
  cout << acc.ExpireYear << endl;
  cout << acc.CredLimit << endl;
  cout << acc.CurrBal << endl << endl;
  }
  
//Close the input files
inFile.close();
outFile.close();
}

