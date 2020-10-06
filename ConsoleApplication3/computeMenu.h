//Done by Tan Kai Yuan

#include <vector>
#include <string>
using namespace std;

//Header file
#ifndef COMPUTEMENU_H_
#define COMPUTEMENU_H_

//compute function
char computeMenu();
void computeFunc(vector<string>, vector<vector<double>>);

//Statistics function and menu
void statMenu(vector<string>, vector<vector<double>>);

//Distinct function and menu
void distinctMenu(vector<string>, vector<vector<double>>);

//Generate Histogram
void histogramMenu(vector<string>, vector<vector<double>>);
void displayHisto(string, vector<string>, vector<int>, string, int);

//data above and below mean
void abvBlwMean(vector<string>, vector<double>, vector<vector<double>>);
void showMeanTable(string, double, vector<vector<double>>, vector<double>, vector<double>, vector<double>, vector<double>);
void displayTwoTable(string, double, vector<vector<double>>, vector<double>, vector<double>, vector<double>, vector<double>);

//Pearson correlation //LR
void pearsonAndLRMenu(vector<string>, vector<double>, vector<vector<double>>);
void PCLRPrompt(vector<string>, vector<vector<double>>, vector<string>&, vector<vector<double>>&);
vector<vector<string>> getPCLRData(vector<double>, vector<vector<double>>);
void displayPCLROutput(string, vector<string>, vector<string>, vector<vector<string>>, vector<vector<double>>, double, double, double);


#endif