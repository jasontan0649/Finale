//Done by Tan Kai Yuan, Boe Chang Horn, Chan Yun Hong

#include <vector>
#include <string>
using namespace std;

//Header file
#ifndef COMPUTEMENU_H_
#define COMPUTEMENU_H_

//compute function
/*
Programmer: Boe Chang Horn
Name:		computeMenu

task:		Print Computation Menu and return selection
data in:	N/A

data out:	choice of selection
*/
char computeMenu();
/*
Programmer: Boe Chang Horn
Name:		computeFunc

task:		Call computation functions
data in:	vector of title, 2D vector of data to compute 

data out:	N/A
*/
void computeFunc(vector<string>, vector<vector<double>>);



//Statistics function and menu
/*
Programmer: Tan Kai Yuan
Name:		statMenu

task:		run statistic functions, display and export output to HTML/txt
data in:	vector of title, 2D vector to compute

data out:	choice of selection
*/
void statMenu(vector<string>, vector<vector<double>>);

//Distinct function and menu
/*
Programmer: Tan Kai Yuan
Name:		distinctMenu

task:		run distinct functions, display and export output to HTML/txt
data in:	vector of title, 2D vector to compute

data out:	choice of selection
*/
void distinctMenu(vector<string>, vector<vector<double>>);

//Generate Histogram
/*
Programmer: Boe Chang Horn
Name:		histogramMenu

task:		call histogram functions to build, display and export histogram in HTML and text
data in:	vector of title in string, 2D vector of data in double

data out:	N/A
*/
void histogramMenu(vector<string>, vector<vector<double>>);

//data above and below mean
/*
Programmer: Boe Chang Horn
Name:		abvBlwMean

task:		call the mean above/below functions to build, display and export the 2 tables in HTML and text
data in:	vector of title, vector of ID in double, 2D vector of data

data out:	N/A
*/
void abvBlwMean(vector<string>, vector<double>, vector<vector<double>>);

//Pearson correlation //LR
/*
Programmer: Chan Yun Hong
Name:		pearsonAndLRMenu

task:		call the pearson LR menu to compute and output the result
data in:	vector of title, vector of ID in double, 2D vector of data

data out:	N/A
*/
void pearsonAndLRMenu(vector<string>, vector<double>, vector<vector<double>>);

#endif