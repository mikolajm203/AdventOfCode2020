#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


using namespace std;
vector<string> inputHandler1();
vector<vector<string>> inputHandler2();
int proccessInput1(vector<string>);
int proccessInput2(vector<vector<string>>);
int main() {
	vector<string> input1 = inputHandler1();
	vector<vector<string>> input2 = inputHandler2();
	cout << "Task 1 output: " << proccessInput1(input1) << endl;
	cout << "Task 2 output: " << proccessInput2(input2) << endl;
	return 0;
}

vector<string> inputHandler1()
{
	ifstream f;
	vector<string> ret;
	string buf = "";
	string line;
	f.open("input.txt");
	while (getline(f, line)) {
		if (line != "")
			buf += line;
		else {
			ret.push_back(buf);
			buf = "";
		}
	}
	ret.push_back(buf);
	f.close();
	return ret;
}
vector<vector<string>> inputHandler2()
{
	ifstream f;
	vector<vector<string>> ret;
	vector<string> buf;
	string line;
	f.open("input.txt");
	while (getline(f, line)) {
		if (line != "") {
			buf.push_back(line);
		}
		else {
			ret.push_back(buf);
			buf.clear();
		}
	}
	ret.push_back(buf);
	f.close();
	return ret;
}

int proccessInput1(vector<string> input){
	int sum = 0;
	map<char, bool> answers;
	for (auto it = input.begin(); it != input.end(); it++) {
		for (char c = 'a'; c <= 'z'; c++) {
			answers[c] = false;
		}
		string tmp = *it;
		for (int i = 0; i < tmp.length(); i++) {
			if (!answers[tmp[i]]) {
				answers[tmp[i]] = true;
				sum++;
			}
		}
	}
	return sum;
}

int proccessInput2(vector<vector<string>> input) {
	int sum = 0;
	map<char, bool> letters;
	int toAdd = 26;
	for (auto it1 = input.begin(); it1 != input.end(); it1++) {
		for (char c = 'a'; c <= 'z'; c++) {
			letters[c] = true;
		}
		for (auto it2 = it1->begin(); it2 != it1->end(); it2++) {
			string tmp = *it2;
			for (char c = 'a'; c <= 'z'; c++) {
				if (tmp.find(c) == string::npos && letters[c]) {
					letters[c] = false;
					toAdd--;
				}
			}
		}
		sum += toAdd;
		toAdd = 26;
	}
	return sum;
}
