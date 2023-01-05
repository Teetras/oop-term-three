#pragma once
#include"Documents.h"
#include<string>
#include<iostream>

using namespace std;

class DocumentSpec {
public:
	string name;
	virtual Documents docType() = 0;
};

class DescriptionSpec : public DocumentSpec {
public:
	DescriptionSpec(string name, float numberOfPages, string description) {
		this->numberOfPages = numberOfPages;
		this->description = description;
		this->name = name;
	}
	Documents docType() { return Descriptionn; }
	float numberOfPages;
	string description;
};


class FormatSpec : public DocumentSpec {
public:
  FormatSpec(string name, float cost, string format) {
		this->cost = cost;
		this->format = format;
		this->name = name;
	}
	Documents docType() { return Formatt; }
	float cost;
	string format;
};
