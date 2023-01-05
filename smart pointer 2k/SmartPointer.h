#pragma once
#include<iostream>
#include<Windows.h>
#include"string"

template<class T>
struct Status {
	T* ptr;
	int counter;
};

using namespace std;

template<class T>
class SmartPointer
{
	Status<T>* smartPtr;
public:
	SmartPointer(T* ptr);
	~SmartPointer();
	SmartPointer(const SmartPointer& obj);
	void operator=(const SmartPointer& obj);
	T* operator->()const;
	void showCounter();
};

