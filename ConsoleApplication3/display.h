//Done by Tan Kai Yuan, Boe Chang Horn, Chan Yun Hong

#include <vector>
#include <string>
using namespace std;

//Header file
#ifndef DISPLAY_H_
#define DISPLAY_H_

//Tan Kai Yuan
/*
Programmer: Tan Kai Yuan
Name:		displayData

task:		call print table function to display data and export output to HTML,txt
data in:	output title, vector of row, vector of col, 2D vector of data

data out:	N/A
*/
void displayData(string, vector<string>, vector<string>, vector<vector<double>>);

//Boe Chang Horn
/*
Programmer: Boe Chang Horn
Name:		displayHisto

task:		call export table in text and HTML function to export histogram in HTML and text file
data in:	the title, vector of marks range in string, vector of frequency in int, the unit distribution in string for output, the unit distribution(scale)

data out:	N/A
*/
void displayHisto(string, vector<string>, vector<int>, string, int);
/*
Programmer: Boe Chang Horn
Name:		showMeanTable

task:		call print table function to displat 2 tables for above and below mean
data in:	the title, the mean, vector of ID below mean, vector of data below mean, vector of ID above mean, vector of data above mean

data out:	N/A
*/
void showMeanTable(string, double, vector<vector<double>>, vector<double>, vector<double>, vector<double>, vector<double>);
/*
Programmer: Boe Chang Horn
Name:		displayTwoTable

task:		call the showMeanTable and export HTML function to export the 2 tables in HTML and text file
data in:	the title, the mean, vector of ID below mean, vector of data below mean, vector of ID above mean, vector of data above mean

data out:	N/A
*/
void displayTwoTable(string, double, vector<vector<double>>, vector<double>, vector<double>, vector<double>, vector<double>);

//Chan Yun Hong
/*
Programmer: Chan Yun Hong
Name:		 displayPCLROutput

task:		call the PrintTableByVect, printComputationOfPC, printComputationOfLR to display table and export and export rhe displayed table and calulations in HTML and text file
data in:	the title, the mean, vector of string of row names, vector of string of column names,2D vector of data in string, 2D vector of selected data (X variable and Y variable),peason coefficient, slope, y_intercept

data out:	N/A
*/
void displayPCLROutput(string, vector<string>, vector<string>, vector<vector<string>>, vector<vector<double>>, double, double, double);


#endif