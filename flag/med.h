#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include<string>


using namespace std;

class medications {

	int productAmount;
	string name;

	int generateRandomId();
public:
	medications(int productAmount, string name);
	medications();
	int getId();
	int getProductAmount();

	void setName(string name);
	void setAmount(int amount);

	string getNmae();

	friend istream& operator>>(istream& s, medications& data);
	friend ostream& operator<<(ostream& s, medications& data);
};
