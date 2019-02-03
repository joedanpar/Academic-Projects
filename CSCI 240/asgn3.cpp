/***********************************************************************
CSCI 240 - Program 2 - Spring 2008

Programmer: Joe (Dan) Parker
Section:    8
TA:         Kalpana Mangalarapu
Date Due:   8 February 2008

Purpose:    The purpose of this program is to analyze data from a 
			physics experiment.
***********************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
	{
	int		cur_pos = 0,		//current position of moving object (initial position is zero)
			temp_pos;			//new position of object during its movement
	double	time_int,			//uniform time interval
			ttl_time = 0,   	//total of all previous time intervals
			avg_vel,			//average velocity for current interval
			avg_accel,			//average acceleration for curent interval
			prev_vel = 0,   	//previous interval's velocity
			ttl_avg_vel = 0;	//average velocity for all intervals

	cout		<< "*******************************************\n"
				<< "*             Motion Analysis             *\n"
				<< "*******************************************\n";

	cout		<< "\n" 
				<< "Enter a uniform time interval in seconds: ";

	cin 		>> time_int;
	do
		{
		cout	<< "\n\n"
				<< "Enter the object's new position in whole feet (a negative value quits): ";

		cin		>> temp_pos;

		if ( temp_pos >= cur_pos )
			{
			ttl_time += time_int;
			avg_vel = ( temp_pos - cur_pos ) / time_int;
			avg_accel = ( avg_vel - prev_vel ) / time_int;
			ttl_avg_vel = temp_pos / ttl_time;
			cur_pos = temp_pos;
			prev_vel = avg_vel;
			
			cout	<< "\n\n"
					<< "Average velocity (current interval): " << setprecision(2) << fixed << avg_vel << " feet/second\n"
					<< "Average velocity (all intervals):    " << setprecision(2) << fixed << ttl_avg_vel << " feet/second\n"
					<< "Average acceleration :               " << setprecision(2) << fixed << avg_accel << " feet/second/second\n";
			}
			
		else if ( temp_pos >=0 )
		
			cout << "\ninvalid entry: " << temp_pos << " is less than the current position, " << cur_pos << ". Try again.";
		}
		while ( temp_pos >= 0 );
	}

