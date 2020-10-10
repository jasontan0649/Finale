//Done by Chan Yun Hong

#include <vector>
using namespace std;

#ifndef LRAndPearsonHtml_H_
#define LRAndPearsonHtml_H_

//Export into HTML File
/*
Programmer: Chan Yun Hong
Name:		exportPCLRHtml

task:		exports calculations of Pearson Coefficient and linear Regression, statistics table in HTML format
data in:	filename of choice, the title chosen, vector element of first column, vector element of the first row(th in HTML format), 2D vector of data in string, extra string, mode of function

data out:	N/A
*/
void exportPCLRHtml(string, string, vector<string>, vector<string>, vector<vector<string>>, vector<double>, vector<double>, double, double, double);
/*
Programmer: Chan Yun Hong
Name:		PCHtml

task:		exports calculations of Pearson Coefficient  in HTML format
data in:	filename of choice, the title chosen, vector element of first column, vector element of the first row(th in HTML format), 2D vector of data in string, extra string, mode of function

data out:	N/A
*/
void PCHtml(vector<double>, vector<double>, double, ofstream&);
/*
Programmer: Chan Yun Hong
Name:		LRHtml

task:		exports calculations of Linear Regression  in HTML format
data in:	filename of choice, the title chosen, vector element of first column, vector element of the first row(th in HTML format), 2D vector of data in string, extra string, mode of function

data out:	N/A
*/
void LRHtml(vector<double>, vector<double>, double, double, double, ofstream&);

#endif