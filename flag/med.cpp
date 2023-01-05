#include"med.h"

medications::medications(int productAmount, string name) {
	this->productAmount = productAmount;

	this->name = name;
}

medications::medications() {
	this->productAmount = 0;

}

int medications::generateRandomId() { return rand(); }



int medications::getProductAmount() { return productAmount; }

ostream& operator<<(ostream& file, medications& data) {
	file.write((char*)(&data), sizeof(medications));
	return file;
}

istream& operator>>(istream& file, medications& data) {
	file.read((char*)(&data), sizeof(medications));
	return file;
}

void medications::setAmount(int amount) { this->productAmount = amount; }

void medications::setName(string name) { this->name = name; }

string medications::getNmae() { return name; }