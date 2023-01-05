#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include<string>


using namespace std;

class medications {
	
	int productAmount;
	char name[20];

	int generateRandomId();
public:
	medications(int productAmount, char *name);
	medications();
	int getProductAmount();

	void setName(char &name);
	void setAmount(int amount);

	char* getNmae();

	friend istream& operator>>(istream& s, medications& data);
	friend ostream& operator<<(ostream& s, medications& data);
};
