//Done by Boe Chang Horn

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

#ifndef HISTOHTML_H_
#define HISTOHTML_H_

/*
Programmer: Boe Chang Horn
Name:		cssHistogram
task:		outputs the css of the histogram in HTML
data in:	ofstream variable

data out:	N/A
*/
void cssHistogram(ofstream&);
/*
Programmer: Boe Chang Horn
Name:		outputWidth
task:		calculates and outputs the width of bars for the histogram (similar to outputStar but that returns a string of star sequence)
data in:	vector int of frequency, int of unit distribution

data out:	vector int of width
*/
vector<int> outputWidth(vector<int>, int);
/*
Programmer: Boe Chang Horn
Name:		percetnWidth
task:		converts the width to percentage so it is readble by CSS
data in:	vector int of frequency, int of unit distribution

data out:	vector double of width in percentage
*/
vector<double> percentWidth(vector<int>, int);
/*
Programmer: Boe Chang Horn
Name:		csshistoBar
task:		calls the previous fucntion to build and ouput the bars of CSS in HTML
data in:	vector int of frequency, vector of string CSS class variables, unit distribution, ofstream variable

data out:	N/A
*/
void csshistoBar(vector<string>, vector<int>, vector<string>, int, ofstream&);
/*
Programmer: Boe Chang Horn
Name:		divHistoBar
task:		builds and ouputs each division of bars in HTML
data in:	vector string of CSS class variables, vector string of mark ranges, vector int width, ofstream variable

data out:	N/A
*/
void divHistoBar(vector<string>, vector<string>, vector<int>, ofstream&);
/*
Programmer: Boe Chang Horn
Name:		buildHistogram
task:		builds and ouputs the main body of histogram in HTML
data in:	title, vector string of mark range, vector int of frequency, vector string of CSS class variables, unit distribution, string of unit distibution, ofstream variable

data out:	N/A
*/
void buildHistogram(string, vector<string>, vector<int>, vector<string>, int, string, ofstream&);
/*
Programmer: Boe Chang Horn
Name:		histogramHTML
task:		the main function that calls all previous functions to buil and output the histogram in HTML
data in:	file name, title, vector string of mark range, vector int of frequency, unit distribution in string, unit distribution

data out:	N/A
*/
void histogramHTML(string, string, vector<string>, vector<int>, string, int);

#endif