/***********************************************************************
CSCI 240 - Program 4 - Spring 2008

Programmer: Joe (Dan) Parker
Section:    8
TA:         Kalpana Mangalarapu
Date Due:   27 February 2008

Purpose:    The purpose of this program is to process sales information
            for a company. The company sells many products, but they
			are categorized into 4 product types: gizmos, widgets,
			doohickeys, and thingamajigs.
***********************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

#define GIZ_LO 0	  //lower bound for gizmo product numbers
#define GIZ_HI 999	  //upper bound for gizmo product numbers
#define WIDG_LO 1000  //lower bound for widget product numbers
#define WIDG_HI 1999  //upper bound for widget product numbers
#define DOO_LO 2000   //lower bound for doohickey product numbers
#define DOO_HI 2999   //upper bound for doohickey product numbers
#define THING_LO 3000 //lower bound for thingamajig product numbers
#define THING_HI 3999 //upper bound for thingamajig product numbers


int main()
	{
	int		giz_ttl = 0,			//total number of gizmos sold
			widg_ttl = 0,			//total number of widgets sold
			doo_ttl = 0,			//total number of doohickeys sold
			thing_ttl = 0,			//total number of thingamajigs sold
			pdct_num = 0,			//product number for the items sold
			num_sold = 0,			//number of items sold
			invalids = 0;			//number of invalid product numbers
	double	indiv_price = 0,	   	//individual product prices
			ttl_giz_sales = 0,   	//total gizmo sales in dollars
			ttl_widg_sales = 0,	   	//total widget sales in dollars
			ttl_doo_sales = 0,		//total doohickey sales in dollars
			ttl_thing_sales = 0;	//total thingamajig sales in dollars

	do
		{
		
		//GATHER INFORMATION ABOUT SALE
		
		cout	<< "\nEnter the product number of the item sold (a negative value quits): ";

		cin		>> pdct_num;
		
		//PROCESS SALE (DETERMINE IF PRODUCT NUMBER IS VALID, THEN PROCESS ORDER)
		
		//product numbers are within gizmo numbers
		if ( pdct_num >= GIZ_LO && pdct_num <= GIZ_HI )
			{
			cout	<< "\nEnter the number of items sold: ";
		
			cin		>> num_sold;
		
			cout	<< "\nEnter the price for one of the items: ";
		
			cin		>> indiv_price;
		
			giz_ttl += num_sold;
			ttl_giz_sales += ( indiv_price * num_sold );
			}
			
			//product numbers are within widget numbers
			else if ( pdct_num >= WIDG_LO && pdct_num <= WIDG_HI )
				{
				
				cout	<< "\nEnter the number of items sold: ";
		
				cin		>> num_sold;
		
				cout	<< "\nEnter the price for one of the items: ";
			
				cin		>> indiv_price;
				
				widg_ttl += num_sold;
				ttl_widg_sales += ( indiv_price * num_sold );
				}
				//product numbers are within doohickey numbers
				else if ( pdct_num >= DOO_LO && pdct_num <= DOO_HI )
					{
					cout	<< "\nEnter the number of items sold: ";
		
					cin		>> num_sold;
		
					cout	<< "\nEnter the price for one of the items: ";
		
					cin		>> indiv_price;
		
					doo_ttl += num_sold;
					ttl_doo_sales += ( indiv_price * num_sold );
					}
					//product numbers are within thingamajig numbers
					else if ( pdct_num >= THING_LO && pdct_num <= THING_HI )
						{
						cout	<< "\nEnter the number of items sold: ";
		
						cin		>> num_sold;
		
						cout	<< "\nEnter the price for one of the items: ";
		
						cin		>> indiv_price;
		
						thing_ttl += num_sold;
						ttl_thing_sales += ( indiv_price * num_sold );
						}
						//product numbers are too big to be a product that is sold
						else if ( pdct_num >= 4000 )
							{
							cout	<< "\nEnter the number of items sold: ";
		
							cin		>> num_sold;
		
							cout	<< "\nEnter the price for one of the items: ";
		
							cin		>> indiv_price;
			
							invalids ++;
							}
		}
		while ( pdct_num >= 0 );
		
		cout << "\n\n"
		     << "***** Product Sales Summary *****"
			 << "\n\n"
			 << "Gizmo Count:            " << setw(11) << setprecision(2) << fixed << right << giz_ttl
			 << "\n"
			 << "Gizmo Sales Total:      " << setw(11) << setprecision(2) << fixed <<  right << ttl_giz_sales
			 << "\n\n"
			 << "Widget Count:           " << setw(11) << setprecision(2) << fixed <<  right << widg_ttl
			 << "\n"
			 << "Widget Sales Total:     " << setw(11) << setprecision(2) << fixed <<  right << ttl_widg_sales
			 << "\n\n"
			 << "Doohickey Count:        " << setw(11) << setprecision(2) << fixed <<  right << doo_ttl
			 << "\n"
			 << "Doohickey Sales Total:  " << setw(11) << setprecision(2) << fixed <<  right << ttl_doo_sales
			 << "\n\n"
			 << "Thingamajig Count:      " << setw(11) << setprecision(2) << fixed <<  right << thing_ttl
			 << "\n"
			 << "Thingamajig Sales Total:" << setw(11) << setprecision(2) << fixed <<  right << ttl_thing_sales
			 << "\n\n"
			 << "Invalid Sales:          " << setw(11) << right << invalids;
	}

