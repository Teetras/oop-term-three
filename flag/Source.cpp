#include<iostream>
#include<cstdlib>
#include"exeption.h"
#include"pharmacy.h"
#include<conio.h>
#include"med.h"
#include <fstream>
#include<Windows.h>
#include<vector>
using namespace std;

int menu()
{
	int k;
	cout << endl << "----------------------------------------" << endl;
	cout << "|1| ������ �����������                  |" << endl;
	cout << "----------------------------------------" << endl;
	cout << "|2| �������� ������                     |" << endl;
	cout << "----------------------------------------" << endl;
	cout << "|3| ������� ������                      |" << endl;
	cout << "----------------------------------------" << endl;
	cout << "|4| ������ ���� �������                 |" << endl;
	cout << "----------------------------------------" << endl;
	cout << "|5| �����                               |" << endl;
	cout << "----------------------------------------" << endl;
	cin >> k;
	return k;
}



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "rus");
	int amount;
	string name;

	HandleError* handler = new HandleMedicSystemError();
	medicalInstitution* shop = new pharmacy(handler);

	medications* Med = new medications(0, "");
	vector<medications> vec = shop->read();



	while (true) {
		switch (menu())
		{
		case 1: {
			system("cls");
			cout << "������� �������� ���������: ";
			getchar();
			getline(cin, name);
			cout << "������� ���������� ���������: ";
			cin >> amount;
			vec.push_back(medications(amount, name));
			shop->save(vec);
			break;
		}
		case 2: {
			shop->read();
			break;
		}
		case 3: {
			int n;
			cout << "������� ����� ���������� ������: " << endl;
			cin >> n;
			if (n > vec.size()) {
				cout << "������������ �����" << endl;
				system("pause");
				break;
			}
			shop->deleteFromFile(n);
			break;
		}
		case 4: {
			shop->readOneItem();
			break;
		}
		case 5: {
			return 0;
		}
		default:
			break;
		}
	}

}