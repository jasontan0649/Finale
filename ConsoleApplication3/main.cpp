//Done by Tan Kai Yuan


#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

//common function
#include "commonf.h" 

//readFile
#include "loadfile.h"

//Computation functions
#include "computeMenu.h"

using namespace std;

char mainMenu();
void sortByColMenu(vector<string>, vector<vector<double>>&);

//open file
string openFile(vector<string>&, vector<vector<double>>&, vector<vector<double>>&);



//Menu Function
char mainMenu() { //print main menu and get user input
	cout << "=========== MAIN MENU ===========  " << endl << endl;
	cout << "1. Load another file               " << endl;
	cout << "2. Display and Export data         " << endl;
	cout << "3. Computation                     " << endl;
	cout << "4. Sort data by column             " << endl;
	cout << "5. Generate Report                 " << endl;
	cout << "6. EXIT                            " << endl << endl;

	return getChoice('1', '6'); //get user input
}


void sortByColMenu(vector<string> colName, vector<vector<double>>& data) {
	cout << "Choose a column : " << endl << endl;
	int i = selVector(colName, "Back"); //get user input from colName

	if (i == colName.size())
		return; //user pick back

	sortByCol(data, i); // sort the data with selected column

	cout << endl << "The data is sorted by " << colName[i] << endl;
	cout << "Which order would you like to sort the data in ?" << endl << endl;
	cout << "1. Ascending " << endl;
	cout << "2. Decending " << endl << endl;

	if (getChoice('1', '2') == '2') //reverse the vector if descending
		reverse(data.begin(), data.end());

	clrScr();
	displayData("Data Output", {}, colName, data);
}

int main() {
	//initialize variable
	vector<string> title;
	vector<vector<double>> data;
	vector<vector<double>> dataTp;

	cout << "Welcome to Bossku's system" << endl;
	string fileName = openFile(title, data, dataTp);

	while (1) {
		clrScr();
		cout << "You had loaded " << fileName << endl;
		char c = mainMenu();
		clrScr();

		switch (c) {
		case '1': openFile(title, data, dataTp); break;
		case '2': displayData("Data Output", {}, title, data); break;
		case '3': computeFunc(title, dataTp); break; //havent code
		case '4': sortByColMenu(title, data); break;
		case '5': cout << "Generate Report"; break;
		case '6': return 0;
		}
	}
	return 0;
}

//open file
string openFile(vector<string>& title, vector<vector<double>>& data, vector<vector<double>>& dataTp) {
	string fileName = loadFile(title, data);
	dataTp = transposeV(data);
	return fileName;
}

