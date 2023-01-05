#pragma once
#include<string>
#include<functional>
#include"med.h"
#include"HeandleError.h"
#include<vector>
#include <fstream>
#include<iomanip>


using namespace std;


class medicalInstitution {
	HandleError* handler;
public:

	medicalInstitution(HandleError* handler) {
		this->handler = handler;
	}

	virtual void save(vector<medications> data) = 0;
	virtual vector<medications> read() = 0;
	virtual void deleteFromFile(int number) = 0;
	virtual void readOneItem() = 0;

protected:
	void handle(function<void()> block) {
		try {
			block();
		}
		catch (exception* error) {
			handler->handle(error);
		}
	}

};

class pharmacy :public  medicalInstitution {
	medications* Medications;
	void showmedicationsInfo() {
		cout << "Количество купленного товара: " << Medications->getProductAmount() << endl;
	}
public:
	pharmacy(HandleError* handler) : medicalInstitution(handler), Medications(NULL) {}
	pharmacy(HandleError* handler, int a) : medicalInstitution(handler), Medications(NULL) {
		handle([] {
			cout << "Вызов конструктора" << endl;
			throw new ConstructorException;
			});
	}

public:


	void save(vector<medications> data) override {
		handle([&data] {
			ofstream file;
			file.open("myFile.dat", ios::binary);
			if (!file.is_open() || !file.good() || file.bad()) throw new IOExeption();
			for (auto item : data) {
				file << item;
			}
			file.close();
			});
	}


	vector<medications> read() override {
		vector<medications> data;
		handle([&data] {
			medications item;
			ifstream file;
			int i = 0;
			file.open("myFile.dat", ios::binary);
			if (!file.is_open() || !file.good() || file.bad()) throw new IOExeption();

			cout << "---------------------------------------------------\n";
		//	cout <<setw(25) << "Названиe" << setw(10) << "Количество\n";
			cout << "---------------------------------------------------\n" << endl;
			while (file >> item)
			{
				i++;
			/*	cout.fill('-');
				cout << setw(24) << endl;
				cout.fill(' ');*/

			//	cout << i << setw(24) << item.getNmae() << setw(10) << item.getProductAmount() << "\n";
				cout << "--------------------------------------------------" << endl;
				data.push_back(item);
			}
			file.close();
			});
		return data;
	}

	void deleteFromFile(int number) {
		vector<medications> items;
		handle([&items, &number] {
			medications item;
			ifstream file;
			file.open("myFile.dat", ios::in | ios::binary);
			if (!file.is_open() || !file.good() || file.bad()) throw new IOExeption();

			while (file >> item)
			{
				items.push_back(item);
			}
			items.erase(items.begin() + (number - 1));

			file.close();
			});
		save(items);
	}

	void readOneItem() {
		medications medications;
		ifstream infile;
		handle([&medications, &infile] {
			infile.open("myFile.dat", ios::in | ios::binary);
			if (!infile.is_open() || !infile.good() || infile.bad()) throw new IOExeption();
			infile.seekg(0, ios::end);
			int endposition = infile.tellg();
			int n = endposition / sizeof(medications);
			cout << "\nВ файле " << n << " заказов";
			cout << "\nВведите номер заказа: ";
			cin >> n;
			int position = (n - 1) * sizeof(medications);
			infile.seekg(position);
			infile >> medications;
			cout << "-------------------------------------------------\n";
			cout << "        Название                     Кол-во       \n";
			cout << "--------------------------------------------------\n" << endl;
			cout << "\t" << medications.getNmae() << "\t\t\t" << medications.getProductAmount() << "\n";
			cout << "----------------------------------------------------" << endl;
			cout << endl;
			});
	}

};
