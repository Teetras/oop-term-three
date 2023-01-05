#pragma once
#include <iostream>
#include<iomanip>
#include<fstream>
#include <sstream>


using namespace std;

class Flight {
	string nameFlight;
	map<string, vector<string>> report;

public:
	Flight(){}
	Flight(string name){ 
		this->nameFlight = name;
	}

	void setNameFlight(string name) {
		this->nameFlight = name;
	}
	string getNameFlight() { return nameFlight; }
	void show(map<string, vector<string>> curr) {
		 cout<< "Название   Время:\n";
		for (auto it = curr.begin(); it != curr.end(); it++)
		{
			cout << it->first << ":";
			bool isFirstItem = true;
			for (auto item : it->second) {
				if (isFirstItem) {
					cout << item << "\n";
					isFirstItem = false;
				}
				else {
					cout.width(it->first.length() + 11);
					cout.setf(ios::right);
					cout << item << endl;
				}

			}
		}
	}
	map<string, vector<string>> read(string name) {
		vector<string> data;

		ifstream inFile;
		inFile.open(name, ios::out);
		if (!inFile.is_open() || !inFile.good() || inFile.bad()) cout << "fale" << endl;
		string key, value, token;
		while (inFile >> key >> value)
		{
			istringstream iss(value);
			while (getline(iss, token, ','))
			{
				data.push_back(token);
			}
			report.insert(pair < string, vector<string>>(key, data));

		}
		inFile.close();
		return report;
	}
	map<string, vector<string>> edit(map<string, vector<string>> curr, string str) {
		for (auto it = curr.begin(); it != curr.end(); it++) {
			if (it->first == str) {
				cout << "" << endl;
				string str1;
				cin >> str1;
				setNameFlight(str1);
				curr.insert(pair < string, vector<string>>(getNameFlight(), it->second));
				curr.erase(str);

				break;
			}
		}
		return curr;
	}
};

class FlinghtDate{
	string dat;

public:
	FlinghtDate(){}
	FlinghtDate(string date) {
		this->dat = date;

	}
	string getDate() {return  dat; }
	
	void setDate(string date) { this->dat = date; }
	
};