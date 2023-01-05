#pragma once
#include<string>
#include"Specs.h"
#include<memory>
#include<iomanip>

using namespace std;



class Document {
protected:
	string name;
public:
	virtual void getSpecification(int numb) = 0;
	virtual void setSpecification() {
		cout << "Введите характеристики добовляемого: " << endl;
		getchar();
		getline(cin, name);
	}
	virtual unique_ptr<Document> clone() = 0;
	string getName() { return name; }
	virtual string getFirst() = 0;
	virtual float getSecond() = 0;
};



class Description   : public Document {
	float numberOfPages ;
	string description ;
public:
	unique_ptr<Document> clone() { return  unique_ptr<Document>(new Description  (*this)); }
	Description  (DescriptionSpec* spec) {
		this->numberOfPages  = spec->numberOfPages;
		this->description  = spec->description ;
		this->name = spec->name;
	}
	Description  () {}
	void setSpecification() {
		Document::setSpecification();
		cout << "Введите количество страний : " << endl;
		cin >> numberOfPages ;
		cout << "Введите краткое описание книги, например жанр : " << endl;
		getchar();
		getline(cin, description );
	}

	void getSpecification(int numb)override {
		cout << numb << "\t" << setw(35) << name << "\t" << setw(8) << numberOfPages <<" м^2" << "\t" << setw(10) << description  << endl;
	}

	string getFirst() { return description ; };
	float getSecond() { return numberOfPages ; }
};

class Format  : public Document {
	float cost;
	string format ;
public:
	unique_ptr<Document> clone() { return  unique_ptr<Document>(new Format (*this)); }
	Format () {}
	Format (FormatSpec* form) {
		this->cost = form->cost;
		this->format  = form->format;
		this->name = form->name;
	}
	void setSpecification() {
		Document::setSpecification();
		cout << "Введите стоимость: " << endl;
		cin >> cost;
		cout << "Введите формат : " << endl;
		getchar();
		getline(cin, format );
	}

	void getSpecification(int numb)override {
		cout<< numb << "\t" <<setw(35) << name << "\t" <<setw(8) << cost<< "\t" << setw(10) << format  << endl;
	}
	string getFirst() { return format ; };
	float getSecond() { return cost; }
};

