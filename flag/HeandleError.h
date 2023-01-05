#pragma once
#include<string>
#include"exeption.h"

class HandleError
{
public:
	virtual void handle(exception* error) = 0;
};

class HandleMedicSystemError : public HandleError {
	string IOExceptionStr = "����������� �����������";
	string ServiceUnavalibleExeptionStr = "������ ����������";
	string UnidentifiedExceptionStr = "����������� ������";

public:
	void handle(exception* error) override {
		if (typeid(*error) == typeid(IOExeption))
			cout << IOExceptionStr << endl;
		else if (typeid(*error) == typeid(ServiceUnavalibleExeption))
			cout << ServiceUnavalibleExeptionStr << endl;
		else  cout << UnidentifiedExceptionStr << endl;
	}
};