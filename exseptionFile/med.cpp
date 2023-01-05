#include"med.h"
#include<cstring>

medications::medications(int productAmount, char *name) {
	this->productAmount = productAmount;

	strcpy_s(this->name, name);
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

void medications::setName(char &name) { *this->name = name; }

char* medications::getNmae() { return name;}