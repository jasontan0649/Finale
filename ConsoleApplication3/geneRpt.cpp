//Done by Tan Kai Yuan

#include <vector>
#include <string>
#include <functional>

#include "commonf.h"

#include "statistic.h"
#include "exporthtml.h"
#include "table.h"

using namespace std;

void geneReport(vector<string>, vector<vector<double>>);

//Generate report
void geneReport(vector<string> title, vector<vector<double>> data) {
	vector<double> id = data[0]; //get ID as string vector
	data.erase(data.begin()); //remove ID from data
	title.erase(title.begin()); //remove ID from title

	vector<function<double(vector<double>)>> funcs{ minVect, maxVect, median, mean, variance, sd };
	vector<string> funcName{ "Min", "Max", "Median", "Mean", "Variance", "Standard Deviation" };
	vector<double> res;

	int idx = selVector(title);
	vector<double> selData = data[idx];

	for (auto func : funcs)
		res.push_back(func(selData));

	displayData(title[idx] + " report", funcName, { title[idx] }, transposeV({ res }));
}
