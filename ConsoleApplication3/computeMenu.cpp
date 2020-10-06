//Done by Tan Kai Yuan

#include <vector>
#include <string>
#include <functional>
#include <iostream>

//common function
#include "commonf.h"

//Display Data Function
#include "display.h"

//maths function
#include "statistic.h"
#include "distinct.h"
#include "LRAndPearson.h"
#include "histogram.h"


using namespace std;

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


char computeMenu() {  //print compute menu and get user input
	cout << "============ COMPUTATION MENU ==============" << endl << endl;
	cout << "1. Compute Statistics                       " << endl;
	cout << "2. Show Distinct Number                     " << endl;
	cout << "3. Generate Histogram                       " << endl;
	cout << "4. Data Above and Below Mean                " << endl;
	cout << "5. Pearson Correlation and Linear Regression" << endl;
	cout << "6. Back                                     " << endl << endl;

	return getChoice('1', '6'); //get user input
}

void computeFunc(vector<string> title, vector<vector<double>> data) {
	vector<double> id = data[0]; //get ID as string vector
	data.erase(data.begin()); //remove ID from data
	title.erase(title.begin()); //remove ID from title

	char c = computeMenu(); //get input option
	clrScr();

	switch (c) { //call input option base on requirement
	case '1': statMenu(title, data); break;
	case '2': distinctMenu(title, data); break;
	case '3': histogramMenu(title, data); break;
	case '4': abvBlwMean(title, id, data); break;
	case '5': pearsonAndLRMenu(title, id, data); break;
	case '7': return;
	}
}

//Statistics function and menu
void statMenu(vector<string> title, vector<vector<double>> data) {
	vector<vector<double>> res, tmp; //temporary vector
	vector<string> selTitle, selFuncName;
	vector<function<double(vector<double>)>> func{ minVect, maxVect, median, mean, variance, sd };
	vector<string> funcName{ "Min", "Max", "Median", "Mean", "Variance", "Standard Deviation" };
	vector<function<double(vector<double>)>> selFunc;

	int i = selVector(title, "All"); //get title selection
	if (i == title.size()) {
		tmp = data; //compute all data
		selTitle = title;
	}
	else {
		tmp.push_back(data[i]); //compute specific data
		selTitle.push_back(title[i]);
	}

	int j = selVector(funcName, "All"); //get compute selection
	if (j == funcName.size()) {
		selFunc = func; //run all compute function
		selFuncName = funcName;
	}
	else {
		selFunc.push_back(func[j]); //compute specific function
		selFuncName.push_back(funcName[j]);
	}

	for (int i = 0; i < selFunc.size(); i++) { // run computation function
		res.emplace_back();
		for (int j = 0; j < tmp.size(); j++)
			res.back().push_back(selFunc[i](tmp[j]));
	}
	//display result
	displayData("Compute Statistics", selFuncName, selTitle, res);
}

void distinctMenu(vector<string> title, vector<vector<double>> data) {
	int i = selVector(title);
	vector<double> tmp{ data[i] };
	string selTitle = title[i];

	vector<double> res;
	vector<int> count;
	distinctNum(tmp, res, count);

	vector<double> doubleCount(count.begin(), count.end());

	displayData("Distinct Number: " + selTitle, {}, { "Number", "Count" }, transposeV({ res, doubleCount }));
}

// AboveBelow Mean Calculation function ============================
void abvBlwMean(vector<string> title, vector<double> id, vector<vector<double>> data) {
	cout << "Data Above and Below Mean " << endl;

	int choice = selVector(title); //get selected title
	double meanRes = mean(data[choice]); //get mean result for selected title
	vector<vector<double>> cmb{ id, data[choice] }; //combine id and selected title

	sortByRow(cmb, 1); //sort by the data of title

	int n = -1; //index to iterate
	while (cmb[1][++n] < meanRes); //find boundary

	vector<double> blwID(cmb[0].begin(), cmb[0].begin() + n);		// extract the ID above & below boundary to new vectors
	vector<double> blwData(cmb[1].begin(), cmb[1].begin() + n);	// same with data (marks)
	vector<double> abvID(cmb[0].begin() + n, cmb[0].end());
	vector<double> abvData(cmb[1].begin() + n, cmb[1].end());

	showMeanTable(title[choice], meanRes, cmb, blwID, blwData, abvID, abvData);
	displayTwoTable(title[choice], meanRes, cmb, blwID, blwData, abvID, abvData);
}
// ================================================================


void histogramMenu(vector<string> title, vector<vector<double>> data) {
	cout << "Generate Histogram" << endl;

	int choice = selVector(title);
	vector<string> markRange = { "0 - <10", "10 - <20", "20 - <30", "30 - <40", "40 - <50", "50 - <60", "60 - <70", "70 - <80", "80 - <90", "90 - 100" };
	vector<int> freq = calcMarksRange({ data[choice] });
	int n = unitDistribution(freq);					// flexible unit
	string starUnit = unitSize(n);       	  // flexible unit in string

	plotHistogram(title[choice], markRange, freq, starUnit, n);			// prompt
	cout << endl;

	displayHisto(title[choice], markRange, freq, starUnit, n);			//HTML and txt
}



void pearsonAndLRMenu(vector<string> title, vector<double> id, vector<vector<double>> data) {
	//Input Prompt
	vector<string> selTitle;
	vector<vector<double>> selData;
	PCLRPrompt(title, data, selTitle, selData);
	//Declare arguments
	vector<double> dataX = selData[0];
	vector<double> dataY = selData[1];
	double r = pearsonCorr(dataY, dataX);
	double m = slope(r, dataY, dataX);
	double b = y_Intercept(m, dataY, dataX);
	string mainTitle = selTitle[0] + "(X)" + " vs " + selTitle[1] + "(Y)";
	vector <string> rowName(id.size() + 1, "");
	rowName.back() = "Total";
	vector <string> colName = { "ID","X","Y","XY","X**2","Y**2" };
	vector<vector<string>> strVect = getPCLRData(id, selData);
	//Display Table
	
	displayPCLROutput(mainTitle, rowName, colName, strVect, selData, r, m, b);
}

