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
	cout << "|1| Купить медикаменты                  |" << endl;
	cout << "----------------------------------------" << endl;
	cout << "|2| Показать записи                     |" << endl;
	cout << "----------------------------------------" << endl;
	cout << "|3| Удалить запись                      |" << endl;
	cout << "----------------------------------------" << endl;
	cout << "|4| читать один элемент                 |" << endl;
	cout << "----------------------------------------" << endl;
	cout << "|5| Выйти                               |" << endl;
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
			cout << "Введите название препарата: ";
			getchar();
			getline(cin, name);
			cout << "Введите количество препарата: ";
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
			cout << "Введите номер удаляемого товара: " << endl;
			cin >> n;
			if (n > vec.size()) {
				cout << "Неправильное число" << endl;
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