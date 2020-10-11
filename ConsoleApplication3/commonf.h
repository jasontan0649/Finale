//Done by Tan Kai Yuan, Boe Chang Horn, Chan Yun Hong

#include <vector>
using namespace std;

//Header file
#ifndef COMMONF_H_
#define COMMONF_H_

/*
Programmer: Tan Kai Yuan
Name:		strUpper

task:		convert string to upper
data in:	string to convert

data out:	return uppercase string
*/
string strUpper(string);

/*
Programmer: Tan Kai Yuan
Name:		strLower

task:		convert string to lower
data in:	string to convert

data out:	return lowercase string
*/
string strLower(string);

/*
Programmer: Tan Kai Yuan
Name:		isNum

task:		Check string is a number
data in:	string to check

data out:	true if string is number else false
*/
bool isNum(string);
/*
Programmer: Tan Kai Yuan
Name:		round

task:		round number
data in:	number to round, decimal place

data out:	rounded number of decimal place
*/
double round(double, int);

/*
Programmer: Tan Kai Yuan
Name:		strRepeat

task:		repeat string n times
data in:	string to repeat, n times

data out:	repeated string with n times
*/
string strRepeat(string, int);
/*
Programmer: Tan Kai Yuan
Name:		toStr

task:		convert double to string with precision
data in:	number to convert, precision
data out:	string of number
*/
string toStr(double, int pre = -1); //custom build to string function

//Chan Yun Hong
/*
Programmer: Chan Yun Hong
Name:		spaceNeeded

task:		return space
data in:	integer

data out:	return string of spaces
*/
string spaceNeeded(int);

/*
Programmer: Chan Yun Hong
Name:		center

task:		center the string in a given space
data in:	number of space available, string

data out:	centered string
*/
string center(int, string);

/*
Programmer: Chan Yun Hong
Name:		ljust

task:		left justify the string in a given space
data in:	number of space available, string

data out:	left justified string
*/
string ljust(int, string);

/*
Programmer: Chan Yun Hong
Name:		 rjust

task:		right justify the string in a given space
data in:	number of space available, string

data out:	right justified string
*/
string rjust(int, string);

//finf max size(length) in vector
/*
Programmer: Chan Yun Hong
Name:		 findMaxInVect

task:		find max size(length) in vector
data in:	vector in string

data out:	integer of max size among the elements in vector
*/
int findMaxInVect(vector<string>);

//vector double to string
/*
Programmer: Chan Yun Hong
Name:		vectDoubleString

task:		convert double vector to string vector
data in:	vector in string

data out:	vector in double
*/
vector<string> vectDoubleString(vector<double>);



//transpose vector
/*
Programmer: Tan Kai Yuan
Name:		transposeV

task:		transpose 2D double vector
data in:	vector to transpose

data out:	transposed vector
*/
vector<vector<double>> transposeV(vector<vector<double>>);
/*
Programmer: Tan Kai Yuan
Name:		transposeV

task:		transpose 2D string vector
data in:	vector to transpose

data out:	transposed vector
*/
vector<vector<string>> transposeV(vector<vector<string>>);

//sort by column
/*
Programmer: Tan Kai Yuan
Name:		sortByCol

task:		sort 2D vector specific column
data in:	vector to sort, the position

data out:	sorted vector
*/
void sortByCol(vector<vector<double>>&, int);
/*
Programmer: Tan Kai Yuan
Name:		sortByRow

task:		sort 2D vector specific row
data in:	vector to sort, the position

data out:	sorted vector
*/
void sortByRow(vector<vector<double>>&, int);

//system function
/*
Programmer: Tan Kai Yuan
Name:		clrScr

task:		clear console
data in:	N/A

data out:	N/A
*/
void clrScr();
/*
Programmer: Tan Kai Yuan
Name:		getCh

task:		call _getch() function
data in:	N/A

data out:	_getch() value
*/
char getCh();

//Menu function
/*
Programmer: Boe Chang Horn
Name:		getChoice

task:		get input from certain input range, loop while not desire range
data in:	lower limit char, upper limit char

data out:	input char
*/
char getChoice(char, char);
/*
Programmer: Boe Chang Horn
Name:		selVector

task:		select from a string vector
data in:	string vector, extra option
data out:	index of the selected vector element
*/
int selVector(vector<string>, string extra = "null");

#endif