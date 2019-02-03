/***********************************************************************\
 *CSCI 240 - Program 2 - Spring 2008								   *
 *																	   *
 *Programmer: Joe (Dan) Parker										   *
 *Section:    8														   *
 *TA:         Kalpana Mangalarapu									   *
 *Date Due:   1 February 2008										   *
 *																	   *
 *Purpose:    The purpose of this program is to calculate the course   *
 *	  	  	  average for a student in CSCI 240 after a few weeks of   *
 *	  	  	  the semester have passed.								   *
\***********************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
	{
	int		ttl_pgm_pts,	//total program points earned
			max_pgm_pts,	//maximum program points possible
			ttl_qz_pts,		//total quiz points earned
			num_qz,			//number of quizes taken
			sum_lw_qz,		//sum of two lowest quiz scores
			ttl_tst_pts,	//total test points earned
			max_tst_pts;	//maximum test points possible
	double	pgm_avg,		//program average
			qz_avg,			//quiz average
			ovr_tst_avg,	//overall test average
			crs_avg;		//course average

	cout		<< "*******************************************\n"
				<< "* Student Average Calculator for CSCI 240 *\n"
				<< "*******************************************\n";

	cout		<< "What is the total points earned for programs?";

	cin			>> ttl_pgm_pts;

	cout		<< "What is the maximum amount of points possible for programs?";

	cin			>> max_pgm_pts;

	cout		<< "What is the total points earned for quizzes?";

	cin			>> ttl_qz_pts;

	cout		<< "What is the number of quizzes taken?";

	cin			>> num_qz;
	
	cout		<< "What is the sum of the two lowest quiz scores?";

	cin			>> sum_lw_qz;

	cout		<< "What is the total amount of points earned for tests?";

	cin			>> ttl_tst_pts;
	
	cout		<< "What is the maximum amount of points possible for tests?";

	cin			>> max_tst_pts;
	
	pgm_avg		= ( (double) ttl_pgm_pts / max_pgm_pts ) * 100;
	qz_avg		= ( (double) ttl_qz_pts - sum_lw_qz ) / ( ( num_qz - 2 ) * 10 ) * 100 ;
	ovr_tst_avg	= ( (double) ttl_tst_pts + qz_avg ) / ( max_tst_pts + 100 ) * 100;
	crs_avg		= ( pgm_avg * .40 ) + ( ovr_tst_avg * .60 );

	cout << "**************************************\n"
			"*           Course Average           *\n"
			"**************************************\n\n"
			"Total Program Points Earned = " << setw(5) << setprecision(2) << right << ttl_pgm_pts << "\n"
			"Maximum Program Points Possible = " << setw(5) << setprecision(2) << right << max_pgm_pts << "\n"
			"Total Quiz Points Earned = " << setw(5) << setprecision(2) << right << ttl_qz_pts << "\n"
			"Number of Quizzes Taken = " << setw(5) << setprecision(2) << right << num_qz << "\n"
			"Sum of Two Lowest Quiz Scores = " << setw(5) << setprecision(2) << right << sum_lw_qz << "\n"
			"Total Test Points Earned = " << setw(5) << setprecision(2) << right << ttl_tst_pts << "\n"
			"Maximum Test Points Possible = " << setw(5) << setprecision(2) << right << max_tst_pts << "\n"
			"Program Average = " << setw(5) << setprecision(2) << right << pgm_avg << "\n"
			"Quiz Average = " << setw(5) << setprecision(2) << right << qz_avg << "\n"
			"Overall Test Average = " << setw(5) << setprecision(2) << right << ovr_tst_avg << "\n"
			"Course Average = " << setw(5) << setprecision(2) << right << crs_avg << "\n";
	}

