//Done by Chan Yun Hong

#include <vector>
#include <fstream>
using namespace std;

#ifndef TABLE_H_
#define TABLE_H_

//algorithm to generate table
/*
Programmer: Chan Yun Hong
Name:		convertDVectToSVect
task:		convert 2D double vector to 2D string vector

data in:	2D double vector data

data out:	2D string vector data
*/
vector<vector<string>> convertDVectToSVect(vector<vector<double>>);
/*
Programmer: Chan Yun Hong
Name:		findMaxBetweenTwoNums
task:		Get the maximum between two integers
data in:	 two integers

data out:	maximum between two integers

*/
double findMaxBetweenTwoNums(int, int);
/*
Programmer: Chan Yun Hong
Name:		joinVect
task:		Join string vector by delimiters
data in:	 string vector, string delimiter

data out:	 string
*/
string joinVect(vector<string>, string);
/*
Programmer: Chan Yun Hong
Name:		getColMaxLength
task:		Get the maximum length between column names and column data
data in:	 string vector, string delimiter

data out:	 string vector of column names, 2D data in string

*/
vector<int> getColMaxLength(vector<string>, vector<vector<string>>);
/*
Programmer: Chan Yun Hong
Name:		getHeader
task:		Get the headers of the table
data in:	 string vector of column names, boolean value of the existence of row names,int vector of maximum lengths of column,integer of maximum length of row


data out:	 string vector of header

*/
vector<string> getHeader(vector<string>, bool, vector<int>, int);
/*
Programmer: Chan Yun Hong
Name:		getBorder
task:		Get the headers of the table
data in:	 string vector of column names, boolean value of the existence of row names,int vector of maximum lengths of column,integer of maximum length of row

data out:	 string vector of header

*/
string getBorder(vector<string>);


//function to export txt
/*
Programmer: Chan Yun Hong
Name:		exportTxt
task:		Export table into text file
data in:	 filename, title of table, string vector of row names, string vector of column names, double vector of 2D data, mode in string

data out:	 N/A

*/
void exportTxt(string, string, vector<string>, vector<string>, vector<vector<double>>, string mode = "new");
/*
Programmer: Chan Yun Hong
Name:		exportTxt
task:		Export table into text file
data in:	 filename, title of table, string vector of row names, string vector of column names, string vector of 2D data, mode in string

data out:	 N/A

*/
void exportTxt(string, string, vector<string>, vector<string>, vector<vector<string>>, string mode = "new");


//function to display Table
/*
Programmer: Chan Yun Hong
Name:		PrintTableByVect
task:		Display whole table of data from beginning to the end
data in:	 title of table, string vector of row names, string vector of column names,double vector of 2D data

data out:	 N/A

*/
void PrintTableByVect(string, vector<string>, vector<string>, vector<vector<double>>);
/*
Programmer: Chan Yun Hong
Name:		PrintTableByVect
task:		Display whole table of data from beginning to the end
data in:	 title of table, string vector of row names, string vector of column names,string vector of 2D data

data out:	 N/A

*/
void PrintTableByVect(string, vector<string>, vector<string>, vector<vector<string>>);
/*
Programmer: Chan Yun Hong
Name:		printHeader
task:		Display the header of table
data in:	 header in string, border in string

data out:	 N/A

*/
void printHeader(string, string);
/*
Programmer: Chan Yun Hong
Name:		printTableData
task:		Display the data of the table
data in:	 boolean value of the existence of row names, integer of maximum length of row, string vector of row name, int vector of maximum lengths of column, string vector of 2D data, border in string

data out:	 N/A

*/
void printTableData(bool, int, vector<string>, vector<int>, vector<vector<string>>, string);

#endif