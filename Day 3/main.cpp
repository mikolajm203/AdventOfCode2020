#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string* inputHandler();
int noOfLines();
int noOfTrees(string*, int, int, int);
unsigned long processInput2(string*, int);
int main() {
	string* input = inputHandler();
	cout << input[1] << endl;
	cout << input[2] << endl;
	cout << "Task 1 output: " << noOfTrees(input, noOfLines(), 3, 1) << endl;
	cout << "Task 2 output: " << processInput2(input, noOfLines());
	return 0;
}

int noOfLines() {
	ifstream f;
	f.open("input.txt");
	string line;
	int counter = 0;
	while (getline(f, line)) {
		counter++;
	}
	f.close();
	return counter;
}

string* inputHandler()
{
	ifstream f;
	f.open("input.txt");
	string line;
	string* ret = new string[noOfLines()];
	int counter = 0;
	while (getline(f, line))
		ret[counter++] = line;
	f.close();
	return ret;
}

int noOfTrees(string* input, int noOfLines, int right, int down) {
	const int sizeOfLine = input[0].size();
	int ret = 0;
	int column = 0;
	for (int row = 0; row < noOfLines; row += down) {
		if (input[row][column % sizeOfLine] == '#')
			ret++;
		column += right;
	}
	return ret;
}

unsigned long processInput2(string* input, int noOfLines) {
	unsigned long ret = noOfTrees(input, noOfLines, 1, 1) * noOfTrees(input, noOfLines, 3, 1) *
		noOfTrees(input, noOfLines, 5, 1) * noOfTrees(input, noOfLines, 7, 1) * noOfTrees(input, noOfLines, 1, 2);
	return ret;
}
