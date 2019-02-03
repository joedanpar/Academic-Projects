/******************************************************************************
CSCI 240 - Program 11b - Spring 2008

Name: Joe Dan Parker
Z-Number: 158012
Section: 8
TA: Kalpana Mangalarapu

Purpose: To read the file of structs written by program 11a.  It will read the
         structs and store them into an array of CreditAccount structs.
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


//------------< function prototypes >------------

int buildArray(CreditAccount[]);
void displayAccount(CreditAccount);
void displayAllAccounts(CreditAccount[], int );
void sortByNumber(CreditAccount[], int);

//-----------< entry point of program >----------

int main ( )
{	 
int numAccs = 0;

CreditAccount AccountArray[20];

numAccs = buildArray(AccountArray);

cout << "***UNSORTED ACCOUNTS***" << endl << endl;

displayAllAccounts(AccountArray, numAccs);

sortByNumber(AccountArray,numAccs);
}

//---------< Extra Functions >------------
int buildArray(CreditAccount accountArray[])
{
int i;
ifstream inFile;

inFile.open("accounts");  // open the source code file
	
if ( inFile.fail() )
  {
  cout << "there is no valid input file\n";
  exit(1);
  }
i = 0;
do
  {
  inFile >> accountArray[i].AccNum;
  inFile >> accountArray[i].LastName;
  inFile >> accountArray[i].FirstName;
  inFile >> accountArray[i].ExpireMon;
  inFile >> accountArray[i].ExpireYear;
  inFile >> accountArray[i].CredLimit;
  inFile >> accountArray[i].CurrBal;
  i++;
  }
while ( inFile );
  
//Close the input files
inFile.close();
return i;
}

void displayAccount(CreditAccount account)
{
cout << "Account Number: " << account.AccNum << endl;
cout << "Expiration Date: " << account.ExpireMon << '/' << account.ExpireYear << endl;
cout << "Name: " << account.LastName << ", " << account.FirstName <<endl;
cout << "Credit Limit: $" << account.CredLimit << endl;
cout << "Current Balance: $" << account.CurrBal << endl;

}

void displayAllAccounts(CreditAccount accountArray[], int numAccounts)
{
int i;

for ( i = 0; i < numAccounts - 1; i++)
 {
 displayAccount(accountArray[i]);
 cout << endl;
 }
}

void sortByNumber(CreditAccount accountArray[], int numAccounts)
{
CreditAccount temp;
int i, j;
int min;

for (i = 0; i < numAccounts -1; i++)
  {
  min = i;
  for (j = i+1; j < numAccounts -1; j++)
    {
    if (strcmp(accountArray[j].AccNum, accountArray[min].AccNum) < 0)
      min = j;
    }
  temp = accountArray[i];
  accountArray[i] = accountArray[min];
  accountArray[min] = temp;
  }
  
cout << "***SORTED ACCOUNTS***" << endl << endl;
displayAllAccounts(accountArray, numAccounts);
}

