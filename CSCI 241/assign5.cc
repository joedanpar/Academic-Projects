//This is "assign5.cc", the driver program for Assignment 5 of CSCI 241 in Autumn, 2008.
//It is the work of Harry Hutchins and is not adequately documented yet.

#include <iostream>

#include "set.h"

using std::cout;
using std::endl;
using std::boolalpha;
using std::noboolalpha;

int main()
{
 //Test of basic constructor and Size
 Set A;
 cout << "Test 1:  basic constructor and Size" << endl;
 cout << "Set A is of size " << A.Size() << endl << endl;
 
 //Test of operators +, = and <<
 Set B;
 B = A + 23;
 B = B + 45;
 B = B + 78;
 cout << "Test 2:  operators +, = and <<" << endl;
 cout << "Set B is of size " << B.Size() << endl;
 cout << "B contains " << B << endl << endl;
 
 //Test of copy constructor
 Set C(B);
 cout << "Test 3:  copy constructor" << endl;
 cout << "Set C should be a copy of B.  It is of size " << B.Size() << endl;
 cout << "C contains " << C << endl << endl;
 
 //Test of operator ==
 cout << "Test 4a:  equality operator" << endl;
 cout << "B and C should be equal" << endl; 
 cout << boolalpha << "The expression B == C is " << (B == C) << endl << noboolalpha << endl;
 
 //Second test of operator == 
 cout << "Test 4b:  equality operator" << endl;
 cout << "A and B should not be equal." << endl;
 cout << boolalpha << "The expression A == B is " << (A == B) << endl << noboolalpha << endl;
 
 //Test of operator <
 cout << "Test 5:  containment" << endl;
 Set D;
 D = D + 12;
 D = D + 91;
 Set E;
 E = E + 12;
 cout << "Set D contains " << D << " and Set E contains " << E << endl;
 cout << "E is contained in D and D is not contained in D." << endl;
 cout << boolalpha << "The expression D < E is " << (D < E) << endl << noboolalpha;
 cout << boolalpha << "The expression E < D is " << (E < D) << endl << noboolalpha << endl;
 
 //Test of operator +
 cout << "Test 6: union" << endl;
 Set F;
 F = B + E;
 cout << "Set B contains " << B << " and Set E contains " << E << endl;
 cout << "Set F is the union of B and E and contains " << F << endl << endl;
 
 //Test of operator ^
 cout << "Test 7a: intersection" << endl;
 Set G;
 G = D ^ F;
 cout << "Set D contains " << D << " and Set F contains " << F << endl;
 cout << "Set G is the intersection of D and F and contains " << G << endl << endl;
 
 //Test of operator ^
 cout << "Test 7b: intersection" << endl;
 Set H;
 H = B ^ B;
 cout << "Set B contains " << B << endl;
 cout << "Set H is the intersection of B and B and contains " << H << endl << endl;
 
 //Test of operator -
 cout << "Test 8a:  operator -" << endl;
 Set I;
 I = B - 45;
 cout << "Set B contains" << B << endl;
 cout << "Set I is B with 45 removed and I contains " << I << endl << endl;
 
 //Test of operator -
 cout << "Test 8b:  operator -" << endl;
 Set J;
 J = F - 56;
 cout << "Set F contains" << F << endl;
 cout << "Set J is F with 56 removed and J contains " << J << endl << endl;
 
 //Test of operator - and IsEmpty
 cout << "Test 8c:  operator -" << endl;
 Set K;
 K = D - D;
 cout << "Set D contains " << D << endl;
 cout << "Set K is D - D and K contains " << K << endl;
 cout << "For Set K, IsEmpty returns " << boolalpha << K.IsEmpty() << noboolalpha << endl << endl;
 
 //Test of operator []
 cout << "Test 9:  operator []" << endl;
 Set L;
 L = L + 15;
 L = L + 30;
 L = L + 45;
 L = L + 60;
 cout << "Set L is of size " << L.Size() << " and L contains" << L << endl;
 cout << "L[1] is " << L[1] << endl;
 cout << "We will change L[1] to 75." << endl;
 L[1] = 75;
 cout << "L[1] is now " << L[1] << endl << endl; 
 
 cout << "That is all for now." << endl;
 
 return 0; 
}


