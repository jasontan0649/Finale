//Done by Boe Chang Horn

#include <vector>
#include <fstream>
#include <string>
using namespace std;

#ifndef EXPORTHTML_H_
#define EXPORTHTML_H_

//function to export HTML
/*
Programmer: Boe Chang Horn
Name:		exportHTML

task:		exports table in HTML format
data in:	filename of choice, the title chosen, vector element of first column, vector element of the first row(th in HTML format), 2D vector of data in double, extra string, mode of function

data out:	N/A
*/
void exportHTML(string, string, vector<string>, vector<string>, vector<vector<double>>, string extra = "", string mode = "once");
/*
Programmer: Boe Chang Horn
Name:		exportHTML(funciton overloaded)

task:		exports table in HTML format
data in:	filename of choice, the title chosen, vector element of first column, vector element of the first row(th in HTML format), 2D vector of data in string, extra string, mode of function

data out:	N/A
*/
void exportHTML(string, string, vector<string>, vector<string>, vector<vector<string>>, string extra = "", string mode = "once");

/*
Programmer: Boe Chang Horn
Name:		titleHTML

task:		build and exports title in HTML format
data in:	the tile in string, ofstream variable

data out:	N/A
*/
void titleHTML(string, ofstream&);
/*
Programmer: Boe Chang Horn
Name:		tableHTML

task:		build and exports the table in HTML format
data in:	vector of first row, vector of first col, 2D vector of data in string, ofstream variable

data out:	N/A
*/
void tableHTML(vector<string>, vector<string>, vector<vector<string>>, ofstream&);
/*
Programmer: Boe Chang Horn
Name:		thTable

task:		build and exports the first row of the table <th> in HTML format
data in:	vector of the first row, ofstream variable

data out:	N/A
*/
void thTable(vector<string>, ofstream&);
/*
Programmer: Boe Chang Horn
Name:		tdTable

task:		builds and exports the main body of table in HTML format
data in:	2D vector of data in string, ofstream variable

data out:	N/A
*/
void tdTable(vector<vector<string>>, vector<string>, ofstream&);
/*
Programmer: Boe Chang Horn
Name:		cssHTML

task:		exports the css for table in HTML format
data in:	ofstream variable

data out:	N/A
*/
void cssHTML(ofstream&);

#endif