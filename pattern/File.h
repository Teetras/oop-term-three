#pragma once
#include<fstream>
#include<vector>
#include"Document.h"
#include<string>
#include"Fabric.h"


using namespace std;

class File {
	ifstream input;
	ofstream output;
	DocumentFabric* fabric;
public:
	File() {
		fabric = new DocumentFabric;
	}
	void write(vector<Document*> data) {
		output.open("teat.txt");
		int ch=0;
		for (auto item : data) {
			if (typeid(*item) == typeid(Description)) {
				ch = 1;
			}
			else if (typeid(*item) == typeid(Format))
			{
				ch = 2;
			}
			output
				<< item->getName() << endl
				<< item->getFirst() << endl
				<< item->getSecond() << endl
				<< ch << endl;
			
		}
		output.close();
	}

	vector<Document*> read() {
		vector<Document*> data;
		string name, first;
		float second;
		int mark;
		input.open("C:\\Users\\tanya\\OneDrive\\Рабочий стол\\pc\\OOP1L\\pattern\\File.txt");
		//input.ignore();
		//getchar();
		while (!input.eof()) {
			input.ignore();
			getline(input, name, '\n');
			input.ignore();
			getline(input, first, '\n');
			input >> second;
			//input.ignore();
			input >> mark;
			if (mark == 1) {
				Document* doc = fabric->makeDocument(new DescriptionSpec(name, second, first));
				data.push_back(doc);
			}
			if (mark == 2) {
				Document* doc = fabric->makeDocument(new FormatSpec(name, second, first));
				data.push_back(doc);
			}
		}
		input.close();
		data.pop_back();
		return data;
	}
};
