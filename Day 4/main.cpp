#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <map>


using namespace std;
string* inputHandler();
int noOfPassports();
int proccessInput1(string*, int);
int proccessInput2(string*, int);
int main() {
	string* input = inputHandler();
	cout << "Task 1 output: " << proccessInput1(input, noOfPassports()) << endl;
	cout << "Task 2 output: " << proccessInput2(input, noOfPassports()) << endl;
	delete[] input;
	return 0;
}

string* inputHandler()
{
	ifstream f;
	f.open("input.txt");
	string line = "";
	string* passports = new string[noOfPassports()];
	int i = 0;
	while (getline(f, line)) {
		if (line != "") {
			passports[i] = passports[i] + line + " ";
		}
		else
			i++;
	}
	f.close();
	return passports;
}

int noOfPassports() {
	ifstream f;
	f.open("input.txt");
	int ret = 0;
	string line;
	while (getline(f, line)) {
		if (line == "")
			ret++;
	}
	ret++;
	return ret;
}

int proccessInput1(string* input, int size)
{
	int ret = 0;
	for (int i = 0; i < size; i++) {
		if (input[i].find("byr:") != string::npos)
			if (input[i].find("iyr:") != string::npos)
				if (input[i].find("eyr:") != string::npos)
					if (input[i].find("hgt:") != string::npos)
						if (input[i].find("hcl:") != string::npos)
							if (input[i].find("ecl:") != string::npos)
								if (input[i].find("pid:") != string::npos)
									ret++;
	}
	return ret;
}

int proccessInput2(string* input, int size) {
	int ret = 0;
	char* buffer = new char[1000];
	char* key;
	char* value;
	for (int i = 0; i < size; i++) {
		map<string, string> passport;
		passport["byr"] = "";
		passport["iyr"] = "";
		passport["hgt"] = "";
		passport["hcl"] = "";
		passport["ecl"] = "";
		passport["pid"] = "";
		passport["cid"] = "";
		strcpy(buffer, input[i].c_str());
		key = strtok(buffer, ": ");
		value = strtok(NULL, ": ");
		passport[key] = value;
		while (true){
			key = strtok(NULL, ": ");
			value = strtok(NULL, ": ");
			if (key == NULL)
				break;
			passport[key] = value;
		}
		// byr
		if (passport["byr"] == "")
			continue;
		if (stoi(passport["byr"]) < 1920 || stoi(passport["byr"]) > 2002)
			continue;
		// iyr
		if (passport["iyr"] == "")
			continue;
		if (stoi(passport["iyr"]) < 2010 || stoi(passport["iyr"]) > 2020)
			continue;
		//eyr
		if (passport["eyr"] == "")
			continue;
		if (stoi(passport["eyr"]) < 2020 || stoi(passport["eyr"]) > 2030)
			continue;
		// hgt
		if (passport["hgt"] == "")
			continue;
		if (!isalpha(passport["hgt"][passport["hgt"].length() - 1]))
			continue;
		int height = stoi(passport["hgt"].substr(0, passport["hgt"].length() - 2));
		if (passport["hgt"][passport["hgt"].length() - 1] == 'm') {
			if (height < 150 || height > 193)
				continue;
		}
		else if (passport["hgt"][passport["hgt"].length() - 1] == 'n') {
			if (height < 59 || height > 76)
				continue;
		}
		//hcl
		if (passport["hcl"] == "")
			continue;
		if (passport["hcl"][0] != '#' || passport["hcl"].length() != 7)
			continue;
		for (int i = 1; i < 7; i++) {
			if (!isalnum(passport["hcl"][i]))
				continue;
		}
		//ecl
		if (passport["ecl"] == "")
			continue;
		if (passport["ecl"] != "amb" && passport["ecl"] != "blu" && passport["ecl"] != "brn" && passport["ecl"] != "gry" &&
			passport["ecl"] != "grn" && passport["ecl"] != "hzl" && passport["ecl"] != "oth")
			continue;
		//pid
		if (passport["pid"] == "")
			continue;
		if (passport["pid"].length() != 9)
			continue;
		for (int i = 0; i < 9; i++)
			if (!isdigit(passport["pid"][i]))
				continue;
		ret++;
	}
	delete[] buffer;
	return ret;
}
