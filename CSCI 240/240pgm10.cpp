/******************************************************************************
CSCI 240 - Program 10 - Spring 2008

Name:
Z-Number:
Section:
TA:

Purpose:
******************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

//-----------< function prototypes >-------------

int next_nonempty_line( ifstream &, char * );

int str_len( char * );
int str_cmp( char *, char * );
char* str_upper( char * );
char* str_trim( char * );
char* str_char( char *, char );


//-----------< entry point of program >----------

int main ( )
{
char buffer1[500], buffer2[500];
	
ifstream inFile1, inFile2;
	
int total_num = 0, similar_num = 0;
int num_pare1 = 0, num_pare2 = 0;
	
inFile1.open("code1.cpp");  // open the first source code file
inFile2.open("code2.cpp");  // open the second source code file
	
if ( inFile1.fail() || inFile2.fail() )
  {
  cout << "At least one of input files does not exist\n";
  exit(1);
  }


//While there are non-empty lines in the files

while ( next_nonempty_line(inFile1, buffer1) != 1 && next_nonempty_line(inFile2, buffer2) != 1 )
  {
  
  //Remove the whitespace characters from the strings
  
  str_trim(buffer1);
  str_trim(buffer2);
		

  //Change all of the lowercase characters to uppercase

  str_upper(buffer1);
  str_upper(buffer2);
		
  
  //If the two strings are equal, increment the counter for the number of
  //similar lines and display the length of the strings.
  //Otherwise, display the two strings.

  if ( str_cmp(buffer1, buffer2) == 0 )
    {
    similar_num++;
    cout << "Line " << total_num << ": " << str_len(buffer1) << endl;
    }
  else
    {
    cout << "Line " << total_num << ": " << endl;
    cout << buffer1 << endl;
    cout << buffer2 << endl;
    }


  //Increment the total number of lines count
  
  total_num++;
	   	
  
  //Count the number of opening parenthesis
  
  if ( str_char(buffer1, '(') != NULL ) // look for the character '('
    num_pare1++;
		
  if ( str_char(buffer2, '(') != NULL ) // look for the character '('
    num_pare2++;
  }//end of while loop
	

//Close the input files
inFile1.close();
inFile2.close();
	
	
//Display the summary information

cout << endl << endl << "Number of similar lines: " << similar_num << endl << endl;
cout << "Total number of lines: " << total_num << endl << endl;

if ( (double)similar_num/total_num > 0.5 )
  cout << "Alert: very similar code!!!" << endl << endl;
	
cout << "Number of pairs of parenthesis in file 1: " << num_pare1 << endl;
cout << "Number of parrs of parenthesis in file 2: " << num_pare2 << endl;
	
system("pause");
return 0;
}//end of main


//-----------< read the next nonempty text line >---------------
// 1st argument: ifstream object
// 2nd argument: an allocated character array of size >= 500
// return value: 0 indicates end-of-file, 1 indicates successful 
//               read and text is saved in array buffer
//--------------------------------------------------------------

int next_nonempty_line(ifstream& inFile, char* buffer)
{
int i;

//Read a line from the file

inFile.getline(buffer, 500);
	

//While there is data in the file

while ( inFile )
  {

  //Determine if the string is non-empty. If it is, return 0.

  for (i=0; buffer[i] != '\0'; i++)
    if ( buffer[i] != '\n' && buffer[i] != ' ' && buffer[i] != '\t' )
      return 0;
  
  //Get another line from the file because the other one was empty

  inFile.getline(buffer, 500);
  }

return 1;     // end-of-file has been reached
}


//----------< implement your functions below this line >--------
