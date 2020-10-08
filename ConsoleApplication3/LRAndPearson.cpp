//Done by Chan Yun Hong

#include <iostream>
#include <vector> 
#include <cmath>

#include "statistic.h"
#include "commonf.h"
//export data and table
#include "table.h" //display and output text file
using namespace std;

vector<double> sqVect(vector<double>);
vector<double> productXY(vector<double>, vector<double>);
double pearsonCorr(vector<double>, vector<double>);
double slope(double, vector<double>, vector<double>);
double y_Intercept(double, vector<double>, vector<double>);
string linearRegression(vector<double>, vector<double>, double, double, double);

//Display Calculation On console
void printComputationOfPC(vector<double>, vector<double>, double);
void printComputationOfLR(vector<double>, vector<double>, double, double, double);

//Prompt
void PCLRPrompt(vector<string>, vector<vector<double>>, vector<string>&, vector<vector<double>>&);
vector<vector<string>> getPCLRData(vector<double>, vector<vector<double>>);

//Export into txt file
void exportPCLRTxt(string, string, vector<string>, vector<string>, vector<vector<string>>, vector<double>, vector<double>, double, double, double);


vector<double> sqVect(vector<double> arr)
{
	vector<double> squares;
	for (double n : arr) {
		squares.push_back(n * n);
	}
	return squares;
}

vector<double> productXY(vector<double> arr1, vector<double> arr2) {
	vector<double> products;
	int size = arr1.size();
	for (int i = 0; i < size; i++) {
		products.push_back(arr1[i] * arr2[i]);
	}
	return products;
}

double pearsonCorr(vector<double> arrY, vector<double>  arrX) {
	int numOfData = arrY.size();
	double sumArrY = sum(arrY);
	double sumArrX = sum(arrX);

	double numerator = numOfData * sum(productXY(arrY, arrX)) - sumArrY * sumArrX;
	double denoY = numOfData * sum(sqVect(arrY)) - sumArrY * sumArrY;
	double denoX = numOfData * sum(sqVect(arrX)) - sumArrX * sumArrX;
	return (numerator) / sqrt(denoY * denoX);
}

//need to ask user to determine which one y which one x
double slope(double r, vector<double> arrY, vector<double> arrX) {
	return r * (sd(arrY) / sd(arrX));
}

double y_Intercept(double m, vector<double> arrY, vector<double> arrX) {
	return mean(arrY) - m * (mean(arrX));
}

string linearRegression(vector<double> arrY, vector<double> arrX, double r, double m, double b) {

	char sign = '-';
	if (b > 0)
		sign = '+';

	return "y = " + toStr(m) + "x " + sign + " " + toStr(abs(b));
}

//Display Calculation On console
void printComputationOfPC(vector<double> arrY, vector<double>  arrX, double r) {
	int numOfData = arrY.size();
	double sumArrY = sum(arrY);
	double sumArrX = sum(arrX);

	cout << "1. Pearson\u0027s Correlation" << endl << endl;
	cout << "   r = (" << toStr(numOfData) << "*" << toStr(sum(productXY(arrY, arrX))) << " - " << toStr(sumArrY) << "*" << toStr(sumArrX) << ")/ sqrt((" << toStr(numOfData) << "*" << toStr(sum(sqVect(arrY))) << " - " << toStr(sumArrY) << "*" << toStr(sumArrY) << ") * (" << toStr(numOfData) << "*" << toStr(sum(sqVect(arrX))) << " - " << toStr(sumArrX) << "*" << toStr(sumArrX) << "))" << endl;
	cout << "     = " << toStr(r) << endl << endl;

}
void printComputationOfLR(vector<double> arrY, vector<double>  arrX, double r, double m, double b) {

	cout << "2. Linear Regression" << endl << endl;
	cout << "   m = " << toStr(r) << " * " << "(" << toStr(sd(arrY)) << "/" << toStr(sd(arrX)) << ")" << endl;
	cout << "     = " << toStr(m) << endl << endl;
	cout << "   b = " << toStr(mean(arrY)) << " - (" << toStr(m) << "*" << toStr(mean(arrX)) << ")" << endl;
	cout << "     = " << toStr(b) << endl << endl;
	cout << "   " << linearRegression(arrY, arrX, r, m, b) << endl << endl;
}

//PearsonLR Menu Input Prompt
void PCLRPrompt(vector<string> title, vector<vector<double>> data, vector<string>& selTitle, vector<vector<double>>& selData) {
	string prompt = "XY";
	cout << "Pearson Correlation and Linear Regression" << endl;
	for (int i = 0; i < 2; i++) { //get user input
		//Ask user to determine whether which one Y Or X
		cout << endl << "Please pick for " << prompt[i] << " axis\n" << endl;

		int n = selVector(title);
		selTitle.push_back(title[n]);
		selData.push_back(data[n]);

		//remove select data
		title.erase(title.begin() + n);
		data.erase(data.begin() + n);
	}
	return;
}

vector<vector<string>> getPCLRData(vector<double> id, vector<vector<double>> selData) {
	// Append data into 2d vector and then transpose it to be able to display properly
	vector<double> dataX = selData[0];
	vector<double> dataY = selData[1];
	vector<double> realProductXY = productXY(dataX, dataY);
	vector<double> sqVectX = sqVect(dataX);
	vector<double> sqVectY = sqVect(dataY);

	vector<vector<double>> finalData{ id,dataX,dataY,realProductXY,sqVectX,sqVectY };
	finalData = transposeV(finalData);
	// Append the data at last row
	finalData.push_back({ sum(dataX),sum(dataY),sum(realProductXY),sum(sqVectX),sum(sqVectY) });

	vector<vector<string>> strVect = convertDVectToSVect(finalData);
	//Insert blank space
	strVect.back().insert(strVect.back().begin(), "");

	strVect.back().resize(6);

	return strVect;
}

//Export into txt file and html file
void exportPCLRTxt(string fileName, string title, vector<string> rowNames, vector<string> colNames, vector<vector<string>> strData, vector<double> arrY, vector<double> arrX, double r, double m, double b) {
	ofstream dataOut;

	dataOut.open(fileName);

	streambuf* psbuf, * backup;
	backup = cout.rdbuf();
	psbuf = dataOut.rdbuf();
	cout.rdbuf(psbuf);

	PrintTableByVect(title, rowNames, colNames, strData);
	printComputationOfPC(arrY, arrX, r);
	printComputationOfLR(arrY, arrX, r, m, b);

	cout.rdbuf(backup);

	dataOut.close();
}

