#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>


using namespace std;
vector<string> inputHandler();
int noOfPassports();
int maxID(vector<string>);
int proccessInput2(vector<string>);
int main() {
	vector<string> input = inputHandler();
	cout << "Task 1 output: " << maxID(input) << endl;
	cout << "Task 2 output: " << proccessInput2(input) << endl;
	return 0;
}

vector<string> inputHandler()
{
	ifstream f;
	vector<string> ret;
	string line;
	f.open("input.txt");
	while (getline(f, line)) {
		ret.push_back(line);
	}
	f.close();
	return ret;
}

int maxID(vector<string> input)
{
	int maxID = 0;
	string rowCode;
	string columnCode;
	int minRow, maxRow;
	int minCol, maxCol;
	int half;
	int ID;
	for (auto it = input.begin(); it != input.end(); it++) {
		rowCode = it->substr(0, 7);
		columnCode = it->substr(7, 3);
		minRow = 0;
		maxRow = 127;
		half = 64;
		for (int i = 0; i < 7; i++) {	//determining row
			if (rowCode[i] == 'F')
				maxRow -= half;
			else
				minRow += half;
			half /= 2;
		}
		minCol = 0;
		maxCol = 7;
		half = 4;
		for (int i = 0; i < 3; i++) {	// determining column
			if (columnCode[i] == 'R')
				maxCol -= half;
			else
				minCol += half;
			half /= 2;
		}
		ID = minRow * 8 + minCol;
		if (ID > maxID)
			maxID = ID;
	}
	return maxID;
}

int proccessInput2(vector<string> input) {

	string rowCode;
	string columnCode;
	int minRow, maxRow;
	int minCol, maxCol;
	int half;
	int ID;
	list<int> IDs;
	for (auto it = input.begin(); it != input.end(); it++) {
		rowCode = it->substr(0, 7);
		columnCode = it->substr(7, 3);
		minRow = 0;
		maxRow = 127;
		half = 64;
		for (int i = 0; i < 7; i++) {	//determining row
			if (rowCode[i] == 'F')
				maxRow -= half;
			else
				minRow += half;
			half /= 2;
		}
		minCol = 0;
		maxCol = 7;
		half = 4;
		for (int i = 0; i < 3; i++) {	// determining column
			if (columnCode[i] == 'L')
				maxCol -= half;
			else
				minCol += half;
			half /= 2;
		}
		ID = minRow * 8 + minCol;
		IDs.push_back(ID);
	}
	IDs.sort();
	auto tmp = IDs.begin();
	int prev = *tmp;
	tmp++;
	bool isFound = false;
	for (tmp; tmp != IDs.end(); tmp++){
		if (prev + 1 != *tmp)
			return prev + 1;
		prev = *tmp;
	}
	return 0;
}
