//Done by Tan Kai Yuan, Boe Chang Horn, Chan Yun Hong

#include <vector>
#include <string>
using namespace std;

//Header file
#ifndef DISPLAY_H_
#define DISPLAY_H_

//Boe Chang Horn
void displayHisto(string, vector<string>, vector<int>, string, int);

void showMeanTable(string, double, vector<vector<double>>, vector<double>, vector<double>, vector<double>, vector<double>);
void displayTwoTable(string, double, vector<vector<double>>, vector<double>, vector<double>, vector<double>, vector<double>);

//Chan Yun Hong
void displayPCLROutput(string, vector<string>, vector<string>, vector<vector<string>>, vector<vector<double>>, double, double, double);


#endif