//Done by Boe Chang Horn

#include <string>
#include <vector>
using namespace std;

#ifndef HISTOGRAM_H_
#define HISTOGRAM_H_

/*
Programmer: Boe Chang Horn
Name:		calcMarksRange

task:		calculates and returns the frequency of each marks range
data in:	vector double of marks

data out:	vector int of freq
*/
vector<int> calcMarksRange(vector<double>);
/*
Programmer: Boe Chang Horn
Name:		maxFreqOfRange

task:		calculates and returns the highest frequency of marks in a vector
data in:	vector of freq

data out:	int of highest freq
*/
int maxFreqOfRange(vector<int>);
/*
Programmer: Boe Chang Horn
Name:		unitDistribution

task:		a scaling function that scales the histogram and returns a unit for distribution
data in:	vector of freq in int

data out:	int of unit distribution
*/
int unitDistribution(vector<int>);
/*
Programmer: Boe Chang Horn
Name:		unitSize

task:		a simple function that shows the unit distribution to the user
data in:	int of unit distribution

data out:	string of the unit distribution
*/
string unitSize(int);
/*
Programmer: Boe Chang Horn
Name:		outputStar

task:		forms a star sequence and store it in a vector for display
data in:	vector int of frequency, int of unit distributions

data out:	vector string of stars sequence
*/
vector<string> outputStar(vector<int>, int);
/*
Programmer: Boe Chang Horn
Name:		plotHistogram

task:		call the previous function and outputs the histogram in a table form
data in:	the title, vector of mark range in string, vector int of frequency, string of unit distribution, unit distribution

data out:	N/A
*/
void plotHistogram(string, vector<string>, vector<int>, string, int);
/*
Programmer: Boe Chang Horn
Name:		exportHistoTxt

task:		exports the histogram into a text file
data in:	filename, the title, vector string of mark range, vector int of frequency, string of unit distribution, unit distribution

data out:	N/A
*/
void exportHistoTxt(string, string, vector<string>, vector<int>, string, int);

#endif