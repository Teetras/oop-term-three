#include<iostream>
#include<cstdlib>
#include"exeptoin.h"
#include"pharmacy.h"
#include<conio.h>
#include"med.h"
#include <fstream>
#include<Windows.h>
#include<vector>
#include<stdio.h>
using namespace std;

int menu()
{
	int k;
	cout.setf(ios::left);
	cout << "\n" << "\n";
	cout.width(50);
	cout << "-" << cout.fill('-') << "\n";
	cout.fill(' ');
	cout << setw(49) << "|1| Купить медикаменты" << setw(1) << "|\n";
	cout.width(50);
	cout << "-" << cout.fill('-') << "\n";
	cout.fill(' ');
	cout << setw(49) << "|2| Показать записи" << setw(1) << "|\n";
	cout.width(50);
	cout << "-" << cout.fill('-') << "\n";
	cout.fill(' ');
	cout << setw(49) << "|3| Удалить запись" << setw(1) << "|\n";
	cout.width(50);
	cout << "-" << cout.fill('-') << "\n";
	cout.fill(' ');
	cout << setw(49) << "|4| читать один элемент" << setw(1) << "|\n";
	cout.width(50);
	cout << "-" << cout.fill('-') << "\n";
	cout.fill(' ');
	cout << setw(49) << "|5| Выйти" << setw(1) << "|\n";
	cout.width(50);
	cout << "-" << cout.fill('-') << "\n";
	cout.fill(' ');

	cin >> k;
	return k;
}



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "rus");
	int amount;
	char name[20];

	HandleError* handler = new HandleMedicSystemError();
	medicalInstitution* shop = new pharmacy(handler);

	medications* Med = new medications();
	vector<medications> vec = shop->read();



	while (true) {
		switch (menu())
		{
		case 1: {

			system("cls");	
			cout << "Введите название препарата: ";
			getchar();
			gets_s(name);
			getchar();
			while (true) {
				cout << "Введите количество препарата: ";
				cin >> amount;
				if (cin.good() && !cin.bad() && !cin.fail()) break;
				cin.clear();
				cin.ignore(10, '\n');
				cout << "Не вводите буквы и прочие символы, только цифры!" << endl;
			}
			
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