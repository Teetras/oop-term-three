#pragma once
#include<string>
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<fstream>
#include <sstream>
#include<limits>

using namespace std;

class Client{
	string fio;
public:
	class Address {
		int house;
		string street;
	public:
		Address(int house, string streets) {
			this->house = house;
			this->street = streets;
		}
		Address(){}
		void setHouse(int numbr) { this->house = numbr; }
		int getHouse() { return house; }
		string getStree() { return street; }
		void setStreet(string str) { this->street = str; }
	};
	Address ad;
	Client(string fio, int house, string streets ):ad(house,streets) {
		this->fio = fio;
	}
	Client():ad() {}
	void setFio(string str) { this->fio = str; }
	string getFio() { return fio; }
};

class Order {
	int time;
	
public:
	
class Food  {
	queue<string> name;
	int cost;
public:
	Food(){}
	Food(queue<string> nameFood, int cost) {
		this->name = nameFood;
		this->cost = cost;
	}
	queue<string> getName() { return name; }
	void setName(queue<string> nameFood) {
		while (!nameFood.empty())
		{
			name.push(nameFood.front()); nameFood.pop();
		}
	}
	void setCost(int cost) {
		this->cost = cost;
	}
	int getCost() { return cost; }
};
Order():food(),person() {}
Order(string fio,
	queue<string> nameFood
	, string streets,
	int house,int time,int cost):
	food(nameFood,cost),
	person(fio,house,streets) {
	this->time = time;
}
Food food;
Client person;

	int getTime() { return time; }
	void setTime(int t) { this->time = t; }
	stack<Order, vector<Order>> read() {
		ifstream inFile;
		stack<Order, vector<Order>> data;

		inFile.open("C:\\Users\\tanya\\OneDrive\\Рабочий стол\\pc\\OOP1L\\PRIORY AND ORD QUEUE\\File., STACK", ios::out);
		
		string fio, nameFood, streets, token;
		int house, time, cost;
		if (!inFile.is_open() || !inFile.good() || inFile.bad()) cout << "fale" << endl;
		while (getline(inFile, fio)) {
			inFile >> house;
			inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
			queue<string> tempFood;

			getline(inFile, streets);
			//inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			getline(inFile, nameFood);
			istringstream iss(nameFood);

			while (getline(iss, token, ','))
			{
				tempFood.push(token);

			}
			inFile >> cost;
			inFile >> time;
			setTime(time);
			data.push(Order(fio, tempFood,streets,house,time,cost));
			inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	
		}return data;
	}
};


