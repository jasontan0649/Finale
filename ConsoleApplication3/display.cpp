//Done by Tan Kai Yuan, Boe Chang Horn, Chan Yun Hong

#include <vector>
#include <string>
#include <iostream>

#include "commonf.h"

#include "exporthtml.h"
#include "table.h" 
#include "histohtml.h"
#include "histogram.h"
#include "LRAndPearsonHtml.h"
#include "LRAndPearson.h"


using namespace std;


//Boe Chang Horn
void displayHisto(string, vector<string>, vector<int>, string, int);

void showMeanTable(string, double, vector<vector<double>>, vector<double>, vector<double>, vector<double>, vector<double>);
void displayTwoTable(string, double, vector<vector<double>>, vector<double>, vector<double>, vector<double>, vector<double>);

//Chan Yun Hong
void displayPCLROutput(string, vector<string>, vector<string>, vector<vector<string>>, vector<vector<double>>, double, double, double);


void displayHisto(string title, vector<string> markRange, vector<int> freq, string starUnit, int n) {		// output histogram table

	histogramHTML(title + "\'s histogram.html", title, markRange, freq, starUnit, n);
	exportHistoTxt(title + "\'s histogram.txt", title, markRange, freq, starUnit, n);

	cout << "Data has been exported. Please press any key to continue" << endl;
	char null = getCh();
}



void showMeanTable(string title, double meanRes, vector<vector<double>> cmb, vector<double> blwID, vector<double> blwData, vector<double> abvID, vector<double> abvData) {		// show 2 tables, above & below mean in prompt
	cout << endl << "The mean is " << meanRes << endl << endl;

	PrintTableByVect("Above", {}, { "ID", title }, transposeV({ abvID, abvData }));
	cout << endl;
	PrintTableByVect("Below", {}, { "ID", title }, transposeV({ blwID, blwData }));
	cout << endl;
}

void displayTwoTable(string title, double meanRes, vector<vector<double>> cmb, vector<double> blwID, vector<double> blwData, vector<double> abvID, vector<double> abvData) {			// made just for mean, as it requires 2 tables
	// output the 2 tables in HTML (using the extra mode parameter)
	exportHTML(title + " Mean.html", title + " Above mean", {}, { "ID", title }, transposeV({ abvID, abvData }), "The mean is " + toStr(meanRes), "new");
	exportHTML(title + " Mean.html", title + " Below Mean", {}, { "ID", title }, transposeV({ blwID, blwData }), "", "last");

	ofstream dataOut;		// from here below, output in .txt
	dataOut.open(title + " Mean.txt"); 	//cout title
	dataOut << title << " mean" << endl;

	streambuf* psbuf, * backup;		// use buffer to output 2tables in .txt
	backup = cout.rdbuf();
	psbuf = dataOut.rdbuf();
	cout.rdbuf(psbuf);

	showMeanTable(title, meanRes, cmb, blwID, blwData, abvID, abvData);

	cout.rdbuf(backup);
	cout << "Data has been exported. Please press any key to continue" << endl;
	char null = getCh();
}



void displayPCLROutput(string mainTitle, vector<string>rowName, vector<string>colName, vector<vector<string>>strVect, vector<vector<double>>selData, double r, double m, double b) {
	vector<double> dataX = selData[0];
	vector<double> dataY = selData[1];

	cout << endl;
	PrintTableByVect(mainTitle, rowName, colName, strVect);
	printComputationOfPC(dataY, dataX, r);
	printComputationOfLR(dataY, dataX, r, m, b);
	cout << endl;

	exportPCLRHtml(mainTitle + "\'s PearsonCorr&LinearRegre.html", mainTitle, rowName, colName, strVect, dataY, dataX, r, m, b);
	exportPCLRTxt(mainTitle + "\'s PearsonCorr&LinearRegre.txt", mainTitle, rowName, colName, strVect, dataY, dataX, r, m, b);

	cout << "Data has been exported. Please press any key to continue" << endl;
	getCh();
}