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

//data above and below mean
void abvBlwMean(vector<string>, vector<double>, vector<vector<double>>);

//Pearson correlation //LR
void pearsonAndLRMenu(vector<string>, vector<double>, vector<vector<double>>);

#endif