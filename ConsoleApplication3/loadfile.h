//Done by Tan Kai Yuan

#include <vector>
#include <fstream>
using namespace std;

#ifndef LOADFILE_H_
#define LOADFILE_H_

/*
Programmer: Tan Kai Yuan
Name:		loadFile

task:		loadFile and append data and return file name
data in:	vector of title to append, 2D vector of data to append

data out:	file name
*/
string loadFile(vector<string>&, vector<vector<double>>&);
/*
Programmer: Tan Kai Yuan
Name:		getFileName

task:		get file name from user input
data in:	N/A

data out:	file name
*/
string getFileName();
/*
Programmer: Tan Kai Yuan
Name:		getColTitleRow

task:		append data of num row,cols and title data
data in:	file object, num of cols to get, string vect of title to get, num of rows to get
data out:	true if data append successfully
*/
bool getColTitleRow(ifstream&, int&, vector<string>&, int&);
/*
Programmer: Tan Kai Yuan
Name:		getTitleRow

task:		append title data
data in:	string vect of title to get
data out:	true if data append successfully
*/
bool getTitleRow(ifstream&, vector<string>&);
/*
Programmer: Tan Kai Yuan
Name:		getData

task:		append data
data in:	2D vect of data to get
data out:	true if data append successfully
*/
bool getData(ifstream&, vector<vector<double>>&);
/*
Programmer: Tan Kai Yuan
Name:		isColRowMatch

task:		check if col and row of data were matched
data in:	2D vector of data, int row, int col
data out:	return true if the data were given in correct row and col
*/
bool isColRowMatch(vector<vector<double>>, int, int);

#endif