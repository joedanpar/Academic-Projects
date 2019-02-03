/***********************************************************************\
CSCI 240 - Program 1 - Spring 2008

Programmer: Joe (Dan) Parker
Section:    8
TA:         Kalpana Mangalarapu
Date Due:   January 16, 2008

Purpose:    The purpose of this program is to calculate compound 
            interest over a 4 year period. The user is prompted 
            for the initial investment amount and the annual interest
            rate for the investment.
\***********************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
double initial_investment, year_1, year_2, year_3, year_4, interest_rate, future_value;

cout << "What is your initial investment?";

cin >> initial_investment;

cout << "What is the annual interest rate?";

cin >> interest_rate;

year_1 = initial_investment + (initial_investment * interest_rate / 100);

year_2 = year_1 + (year_1 * interest_rate / 100);

year_3 = year_2 + (year_2 * interest_rate / 100);

year_4 = year_3 + (year_3 * interest_rate / 100);

future_value = year_4;

cout << "**************************************";
cout << "\n*          Investment Result         *";
cout << "\n**************************************";
cout << "\n";
cout << "\nInitial Amount = " << initial_investment;
cout << "\nInterest Rate = " << interest_rate;
cout << "\nFinal Value = " << future_value;
}

