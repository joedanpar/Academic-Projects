/******************************************************************************
CSCI 240 - Program 12 - Spring 2008

Name: Joe Dan Parker
Z-Number: 158012
Section: 8
TA: Kalpana Mangalarapu

Purpose: To display the information, to set values, and to apply
         payments/purchases to the account.
******************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

//-----------< function prototypes >-------------

class CreditAccount
{
private:
char   AccNum[20],
       LastName[21],
	   FirstName[21];
int    ExpireMon,
       ExpireYear;
double CredLimit,
       CurrBal;
	   
public:
CreditAccount( char[], char[], char[], int, int, double, double);
void showAccount();
void setAcctNum( char[] );
void setName( char[], char[] );
void setExpiration( int, int );
void setLimit( double );
void changeBalance( double );

};


//-----------< entry point of program >----------

int main ( )
{
CreditAccount acc1 = CreditAccount( "1213-4320-6538-4738", "Parker", "Joe", 1, 2009, 2000.00, 500.00 ),
              acc2 = CreditAccount( "1234-5678-9012-3456", "Smith", "John", 6, 2007, 1000.00, 750.00 );
	
acc1.showAccount();

// Change the account holder's name to "Dan Parker", from "Joe Parker"
acc1.setName("Dan", "");
acc1.showAccount();

// Hypothetical change to owner of account
acc1.setName("John", "Smith");
acc1.showAccount();

// Hypothetical loss off current card, needs to get a new number.
acc1.setAcctNum("1234-5678-9012-3456");
acc1.showAccount();

// Hypothetical extension of credit expiration date.
acc1.setExpiration(5, 2011);
acc1.showAccount();

// Invalid entry of extension for credit expiration date.
acc1.setExpiration(1, 2007);
acc1.showAccount();

// Changes to account balance.
acc1.changeBalance(500);
acc1.changeBalance(500);
acc1.changeBalance(-2500);
acc1.changeBalance(4000);
acc1.changeBalance(-1500);
}

CreditAccount::CreditAccount( char acctNum[], char lastName[], char firstName[], int expMonth, int expYear, double creditLimit, double balance)
{
setAcctNum(acctNum);
setName(firstName, lastName);
setExpiration(expMonth, expYear);
setLimit(creditLimit);
CurrBal = balance;
}

void CreditAccount::showAccount()
{
cout << "ACCOUNT INFORMATION" << endl;
cout << "Account Number: " << AccNum << endl;
cout << "Expiration Date: " << ExpireMon << '/' << ExpireYear << endl;
cout << "Name: " << LastName << ", " << FirstName <<endl;
cout << "Credit Limit: $" << CredLimit << endl;
cout << "Current Balance: $" << CurrBal << endl << endl;
}

void CreditAccount::setAcctNum( char newAcctNum[] )
{
int i;

for (i = 0; i < 20; i++)
  {
  AccNum[i] = newAcctNum[i];
  }
}

void CreditAccount::setName( char newFirst[], char newLast[] )
{
int i;

if (newFirst != "")
  {
  for (i = 0; i < 20; i++)
    {
    FirstName[i] = newFirst[i];
    }
  }
if (newLast != "")
  {
  for (i = 0; i < 20; i++)
    {
    LastName[i] = newLast[i];
    }
  }
}

void CreditAccount::setExpiration( int newMonth, int newYear )
{
if ((newMonth > 0 && newMonth < 13) && newYear > 2008)
  {
  ExpireMon = newMonth;
  ExpireYear = newYear;
  }
else
  {
  cout << "ERROR: This account has an invalid expiration date." << endl;
  }
}

void CreditAccount::setLimit( double newCreditLimit )
{
if (newCreditLimit > 0.0)
  CredLimit = newCreditLimit;
else
  {
  cout << "ERROR: This account has an invalid credit limit." << endl;
  }
}

void CreditAccount::changeBalance( double balanceChange )
{
CurrBal += balanceChange;

if (CurrBal < 0.0)
  {
  cout << "NOTICE: This account has been overpaid, and has been credited the account" << endl;
  }
if (CurrBal > CredLimit)
  {
  CurrBal += 25.00;
  cout << "NOTICE: This account has been overdrawn, and has been charged the $25.00 fee." << endl;
  }
}

