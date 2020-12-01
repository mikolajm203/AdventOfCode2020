#include <iostream>
#include <fstream>
#include <string>
#include <list>


using namespace std;
list<int> inputHandler();
long proccessInput(list<int> input);

int main() {
	list<int> input = inputHandler();
	cout << "Output: " << proccessInput(input);
	return 0;
}

list<int> inputHandler() {
	list<int> ret;
	ifstream f;
	f.open("input.txt");
	string line;
	while (getline(f, line))
		ret.push_back(stoi(line));
	f.close();
	return ret;
}

long proccessInput(list<int> input)
{
	int current, desired;
	list<int>::iterator indicator;
	for (auto it1 = input.begin(); it1 != input.end(); it1++) {
		current = *it1;
		for (auto it2 = input.begin(); it2 != input.end(); it2++) {
			current += *it2;
			desired = 2020 - current;
			indicator = find(input.begin(), input.end(), desired);
			if (indicator != input.end())
				return ((long)(*it1) * (long)(*it2) * (long)(*indicator));
			current = *it1;
		}
	}
	return 0;
}

