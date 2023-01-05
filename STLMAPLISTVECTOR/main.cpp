//vector, map бронирование авиабилетов
//объекты классов по предметной области, указанной в
//таблице(класс должен содержать функционал по предметной области).Для
//контейнера реализовать добавление, удаление, редактирование, вывод
//содержимого контейнера на экран и в файл, поиск и сортировку элементов.
//Необходимо создать удобное пользовательское меню.
#include<iostream>
#include<map>
#include <sstream>
#include<string>
#include<vector>
#include"Avia.h"
#include<iomanip>
#include<fstream>



using namespace std;
void menu() {
	cout << "\n" << "\n";
	cout.width(50);
	cout << "-" << cout.fill('-') << "\n";
	cout.fill(' ');
	cout << "|1| Добавить рейс                                " << setw(1) << "|\n";
	cout.width(50);
	cout << "-" << cout.fill('-') << "\n";
	cout.fill(' ');
	cout << "|2| Удалить рейс                                 " << setw(1) << "|\n";
	cout.width(50);
	cout << "-" << cout.fill('-') << "\n";
	cout.fill(' ');
	cout << "|3| Редактировать маршрут пути                   " << setw(1) << "|\n";
	cout.width(50);
	cout << "-" << cout.fill('-') << "\n";
	cout.fill(' ');
	cout << "|0| Выйти                                        " << setw(1) << "|\n";
	cout.width(50);
	cout << "-" << cout.fill('-') << "\n";
	cout.fill(' ');
}
int main(int argc,char *str[]) {
	system("chcp 1251");
	system("cls");

	FlinghtDate date[40];
	Flight nameFl;
	string nameFlight;
//	int month, year;D:\\OOP1L\\map\\myFile.txt"
	int i=0;
	map<string, vector<string>> report = nameFl.read(str);
	nameFl.show(report);
	while (true){
		menu();
		int choise;
		cin >> choise;
		switch (choise)
		{
		case 1: {
			vector<string> data;
			i = 0;
			cout << "Введите название рейса в формате: город-город" << endl;
			rewind(stdin);

			getline(cin, nameFlight);
			nameFl.setNameFlight(nameFlight);
			cout << "Введите дату Рейса" << endl;
			while (i < 40) {
				string str;
				rewind(stdin);
				getline(cin, str);
				date[i].setDate(str); 
				data.push_back(date[i].getDate());
				 i++;
				cout << "Ввести еще? 1-да, 0-нет." << endl;
					int ch;
					cin >> ch;
					if(ch==1){}
					else {
						report.insert(pair < string, vector<string>>(nameFl.getNameFlight(), data));
						nameFl.show(report);

						break;	
					}
			}
			break;

		}
		case 2: {
			cout << endl;
			nameFl.show(report);
			cout << "Введите название рейса , который хотите удалить." << endl;
			string str;
			getchar();
			getline(cin, str);
			map<string, vector<string>>::iterator mapPtr;
			mapPtr = report.find(str);
			if (mapPtr!=report.end()) {
				report.erase(str);
			}
			else cout << "Такого рейса нет.\n";break;
		}
		case 3: {
			nameFl.show(report);
			cout<<endl << "Введите название рейса , который хотите изменить." << endl;
			string str;
			getchar();
			getline(cin, str);
			report=nameFl.edit(report, str);
			nameFl.show(report);
			break;

		}
		
		case 0: {
			ofstream inFile;
			inFile.open("D:\\OOP1L\\map\\myFile.txt", ios::app);
			if (!inFile.is_open() || !inFile.good() || inFile.bad()) cout<<"fale"<<endl;
			for (auto it = report.begin(); it != report.end(); it++) {
				inFile << it->first << "\n";

				for (auto item : it->second) {
					inFile << item << ",";
				}
			}
			inFile.close();
			return 0;
			}
		default:
			break;
		}; }
}