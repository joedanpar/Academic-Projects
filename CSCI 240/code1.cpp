#include <iostream>
#include <fstream>
using namespace std;

//-----------< read the next nonempty text line >---------------
// 1st argument: infile stream object
// 2nd argument: an allocated character array of size >= 500
// return value: 0 indicates end-of-file, 1 indicates successful 
//               read and text is saved in array buffer
//--------------------------------------------------------------
int next_nonempty_line(ifstream& inFile, char* buffer)
{
	int i;
	inFile.getline(buffer, 500);
	while ( inFile )
	{
		for (i=0; buffer[i] != '\0'; i++)
			if ( buffer[i] != '\n' && buffer[i] != ' ' && buffer[i] != '\t' )
				return 0;
		inFile.getline(buffer, 500);
	}
	return 1;     // end-of-file
}

//-----------< function prototypes >-------------
int str_len(char*);
int str_cmp(char*, char*);
char* str_upper(char*);
char* str_trim(char*);
int str_char(char*, char);

//-----------< entry point of program >----------
int main ( )
{
	char buffer1[500], buffer2[500];
	ifstream inFile1, inFile2;
	int TOTAL_NUM = 0, SIMILAR_NUM = 0;
	int num_pare1 = 0, num_pare2 = 0;
	
	inFile1.open("code1.cpp");  // open the first source code file
	inFile2.open("code2.cpp");  // open the second source code file
	if ( inFile1.fail() || inFile2.fail() )
	{
		cout << "At least one of input files does not exist\n";
		exit(1);
	}
	while ( next_nonempty_line(inFile1, buffer1) != 1 && next_nonempty_line(inFile2, buffer2) != 1 )
	{
		str_trim(buffer1);
		str_trim(buffer2);
		str_upper(buffer1);
		str_upper(buffer2);
		if ( str_cmp(buffer1, buffer2) == 0 ) {
			SIMILAR_NUM++;
			cout << "Line " << TOTAL_NUM << ": " << str_len(buffer1) << endl;
		}
		else {
			cout << "Line " << TOTAL_NUM << ": " << endl;
			cout << buffer1 << endl;
			cout << buffer2 << endl;
		}
		TOTAL_NUM++;
	   	if ( str_char(buffer1, '(') != NULL )
			num_pare1++;
		if ( str_char(buffer2, '(') != NULL )
			num_pare2++;
	}

	inFile1.close();
	inFile2.close();
	
	// report
	cout << "Number of similar lines: " << SIMILAR_NUM << endl;
	cout << "Total number of lines: " << TOTAL_NUM << endl;
	if ( (double)SIMILAR_NUM/TOTAL_NUM > 0.5 )
		cout << "Alert: very similar code!!!\n";
	cout << "Number of pairs of parenthesis in file 1: " << num_pare1 << endl;
	cout << "Number of parrs of parenthesis in file 2: " << num_pare2 << endl;
	
	return 0;
}

//----------< implementation of functions >--------
