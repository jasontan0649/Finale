//Done by Tan Kai Yuan

#include <vector>
#include <fstream>
using namespace std;

#ifndef STATISTIC_H_
#define STATISTIC_H_

/*
Programmer: Tan Kai Yuan
Name:		minVect

task:		return minimum element of data
data in:	vector of data
data out:	minimum element
*/
double minVect(vector<double>);
/*
Programmer: Tan Kai Yuan
Name:		maxVect

task:		return maximum element of data
data in:	vector of data
data out:	maximum element
*/
double maxVect(vector<double>);
/*
Programmer: Tan Kai Yuan
Name:		median

task:		return median of data
data in:	vector of data
data out:	median val
*/
double median(vector<double>);
/*
Programmer: Tan Kai Yuan
Name:		mean

task:		return mean of data
data in:	vector of data
data out:	mean val
*/
double mean(vector<double>);
/*
Programmer: Tan Kai Yuan
Name:		variance

task:		return variance of data
data in:	vector of data
data out:	variance val
*/
double variance(vector<double>);
/*
Programmer: Tan Kai Yuan
Name:		sd

task:		return standard deviation of data
data in:	vector of data
data out:	standard deviation 
*/
double sd(vector<double>);
/*
Programmer: Tan Kai Yuan
Name:		sum

task:		return sum of data
data in:	vector of data
data out:	sum
*/
double sum(vector<double>);
/*
Programmer: Tan Kai Yuan
Name:		sort

task:		sort vector
data in:	vector to sort
data out:	N/A
*/
void sort(vector<double>&);

#endif