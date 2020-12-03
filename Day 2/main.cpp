#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <list>


using namespace std;

struct password {
	int lower;
	int upper;
	char key;
	string pass;
};

list<password> inputHandler();
password stopas(string str);
int processInput1(list<password>);
int processInput2(list<password>);
int main() {
	list<password> passwords = inputHandler();
	cout << "Task 1 output: " << processInput1(passwords) << endl;
	cout << "Task 2 output: " << processInput2(passwords);
	return 0;
}

list<password> inputHandler()
{
	list<password> ret;
	ifstream f;
	f.open("input.txt");
	string line;
	while (getline(f, line)) {
		ret.push_back(stopas(line));
	}
	return ret;
}

password stopas(string str)
{
	password ret;
	char* line = new char[1000];
	strcpy(line, str.c_str());
	char* tok = strtok(line, "-: ");
	ret.lower = atoi(tok);
	tok = strtok(NULL, "-: ");
	ret.upper = atoi(tok);
	tok = strtok(NULL, "-: ");
	ret.key = tok[0];
	tok = strtok(NULL, "-: ");
	ret.pass = tok;
	return ret;
}

int processInput1(list<password> passwords) {
	int ret = 0;
	int noOfKeys;
	for (auto it = passwords.begin(); it != passwords.end(); it++) {
		noOfKeys = 0;
		for (int i = 0; i < it->pass.size(); i++) {
			if (it->pass[i] == it->key)
				noOfKeys++;
		}
		if (noOfKeys >= it->lower && noOfKeys <= it->upper)
			ret++;
	}
	return ret;
}

int processInput2(list<password> passwords) {
	int ret = 0;
	int noOfCorrect = 0;
	for (auto it = passwords.begin(); it != passwords.end(); it++) {
		noOfCorrect = 0;
		if (it->pass[it->lower - 1] == it->key)
			noOfCorrect++;
		if (it->pass[it->upper - 1] == it->key)
			noOfCorrect++;
		if (noOfCorrect == 1)
			ret++;
	}
	return ret;
}
