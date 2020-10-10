//Done by Chan Yun Hong

#include <vector>
using namespace std;

#ifndef LRAndPearson_H_
#define LRAndPearson_H_

/*
Programmer: Chan Yun Hong
Name:		sqVect
task:		Get a vector of the computed square of the data
data in:	vector of data

data out:	vector of  square data
*/
vector<double> sqVect(vector<double>);
/*
Programmer: Chan Yun Hong
Name:		productXY
task:		Get a vector of the computed product of two sets of double vector of data
data in:	vector of 1st data, vector of 2nd data

data out:	vector of product of data
*/
vector<double> productXY(vector<double>, vector<double>);
/*
Programmer: Chan Yun Hong
Name:		pearsonCorr
task:		Get a vector of the computed product of two sets of double vector of data
data in:	vector of Y-axis data, vector of X-axis data

data out:	Pearson Correlation coefficient
*/
double pearsonCorr(vector<double>, vector<double>);
/*
Programmer: Chan Yun Hong
Name:		slope
task:		Get the slope of linear regression line
data in:	Pearson Correlation coefficient,vector of Y-axis data, vector of X-axis data

data out:	slope of linear regression line

*/
double slope(double, vector<double>, vector<double>);
/*
Programmer: Chan Yun Hong
Name:		y_Intercept
task:		Get the y_Intercept of linear regression line
data in:slope, vector of Y-axis data, vector of X-axis data

data out:	y_Intercept of linear regression line
*/
double y_Intercept(double, vector<double>, vector<double>);
/*
Programmer: Chan Yun Hong
Name:		linearRegression
task:		Return the string of equation of linear regression

data in:slope, vector of Y-axis data, vector of X-axis data

data out:	vector of Y-axis data, vector of X-axis data, Pearson Correlation, coefficient, slope, y-intercept

*/
string linearRegression(vector<double>, vector<double>, double, double, double);

//Display Calculation On console
/*
Programmer: Chan Yun Hong
Name:		printComputationOfPC
task:		Display Calculation of Pearson Correlation coefficient  On console
data in: vector of Y-axis data, vector of X-axis data, Pearson Correlation coefficient

data out:	N/A
*/
void printComputationOfPC(vector<double>, vector<double>, double);
/*
Programmer: Chan Yun Hong
Name:		printComputationOfLR
task:		Display Calculation of Linear Regression  On console
data in: vector of Y-axis data, vector of X-axis data, Pearson Correlation coefficient, slope, y_Intercept

data out:	N/A
*/
void printComputationOfLR(vector<double>, vector<double>, double, double, double);

//Prompt
/*
Programmer: Chan Yun Hong
Name:		PCLRPrompt
task:		used as PearsonLR Menu Input Prompt to prompt user to input data
data in: vector of string title, 2D vector of data, vector of string of selected title which pass by reference,  2D vector of selected data which pass by reference

data out:	N/A
*/
void PCLRPrompt(vector<string>, vector<vector<double>>, vector<string>&, vector<vector<double>>&);
/*
Programmer: Chan Yun Hong
Name:		getPCLRData
task:		build the data needed to be displayed for statistics table
data in: vector of id, 2D vector of data

data out:	2D vector of string of data
*/
vector<vector<string>> getPCLRData(vector<double>, vector<vector<double>>);

//Export into txt file
/*
Programmer: Chan Yun Hong
Name:		exportPCLRTxt
task:		Export the displayed table and calculation into txt file
data in: string filename, string title, vector of string of rowNames, vector of string of colnames, 2d vector of s data, vector of Y-axis data, vector of X-axis data, Pearson Correlation coefficient, slope, y_Intercept

data out: N/A
*/
void exportPCLRTxt(string, string, vector<string>, vector<string>, vector<vector<string>>, vector<double>, vector<double>, double, double, double);

#endif