#include"Header.h"
#include<queue>
#include<iomanip>

class Comparer {
public:
	bool operator()(Order& it1, Order& it2) {
		return it1.getTime() < it2.getTime();
	}
};
void menu() {
	cout << "\n" << "\n";
	cout.width(50);
	cout << "-" << cout.fill('-') << "\n";
	cout.fill(' ');
	cout << "|1| Добавить заказ                                " << setw(1) << "|\n";
	cout.width(50);
	cout << "-" << cout.fill('-') << "\n";
	cout.fill(' ');
	cout << "|2| Удалить заказ                                 " << setw(1) << "|\n";
	cout.width(50);
	cout << "-" << cout.fill('-') << "\n";
	cout.fill(' ');
	cout << "|3| Просмотреть заказы                            " << setw(1) << "|\n";
	cout.width(50);
	cout << "-" << cout.fill('-') << "\n";
	cout.fill(' ');
	cout << "|0| Выйти                                        " << setw(1) << "|\n";
	cout.width(50);
	cout << "-" << cout.fill('-') << "\n";
	cout.fill(' ');
}
int main() {
	system("chcp 1251");
	Order temp =  Order();
//	Client* cus = new Client();
	

	queue<string> food;
	stack<Order, vector<Order>> data=temp.read();
	priority_queue<Order, vector<Order>, Comparer> datas;
	while (true)
	{
		menu();
		int choise;
		cin >> choise;
		switch (choise) {
		case 1: {
string fio, nameFood, streets;
	int house, time, cost;
			cout << "Введите имя клиента: " << endl;
			rewind(stdin);

			getline(cin, fio);
			temp.person.setFio(fio);
			rewind(stdin);

			//cus->setFio(fio);
			cout << "Введите улицу доставки: " << endl;
			getline(cin, streets);
			temp.person.ad.setStreet(streets);
			cout << "Дом: " << endl;
			cin >> house;
			temp.person.ad.setHouse(house);
			cout << "Введите заказанное блюдо, если нескольно то в столбец и для окончания ввода введите 0: " << endl;
			while (true) {
				rewind(stdin);

				getline(cin, nameFood);
				if (nameFood == "0") { break; }
				else {
					food.push(nameFood);
				}

			}
			temp.food.setName(food);
			cost = rand() % 60 + 1;
			temp.food.setCost(cost);
			time = rand() % 360 + 30;
			temp.setTime(time);
			data.push(temp);
			break;
		}
		case 2: {
			priority_queue<Order, vector<Order>, Comparer> order;
			stack<Order, vector<Order>> tempData;
			string fio;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			int i = 0;
			cout << "Ведите имя клиента для удаления заказа: ";
			getline(cin, fio);
			while (data.size()>i)
			{
				Order ord = data.top();
				if (ord.person.getFio() == fio) {
					data.pop();
				}
				i++;
			}
			break;
		}
		case 3: {
			priority_queue<Order, vector<Order>, Comparer> order;
			stack<Order, vector<Order>> tempData=data;

			while (!tempData.empty()) {
				order.push(tempData.top());
				tempData.pop();
			}
			while (!order.empty())
			{
				Order ord = order.top();
				cout<<"Имя клиента: " << ord.person.getFio() << "       Адресс: " << ord.person.ad.getHouse() << "," << ord.person.ad.getStree() << endl<<"Заказанные блюда: ";
				//cout << ord.food.getName();
				queue<string> name= ord.food.getName();
				while (!name.empty()) {
					cout << name.front() << ", "; name.pop();
				}
				cout << endl<<"Стоимость :" << ord.food.getCost() << endl << "Ожидаемое время доставки :" << ord.getTime() << endl << endl;
				order.pop();
			}
			break;
		}
		
		case 0: {
			ofstream inFile;
			//C:\\Users\\tanya\\OneDrive\\Рабочий стол\\pc\\OOP1L\\PRIORY AND ORD QUEUE, STACK\\File.txt
			inFile.open("File.txt", ios::in);
			if (!inFile.is_open() || !inFile.good() || inFile.bad()) cout << "fale" << endl;
			priority_queue<Order, vector<Order>, Comparer> order;
			stack<Order, vector<Order>> tempData = data;

			while (!tempData.empty()) {
				order.push(tempData.top());
				tempData.pop();
			}
			while (!order.empty())
			{
				Order ord = order.top();
				inFile << ord.person.getFio() << endl << ord.person.ad.getHouse() << endl << ord.person.ad.getStree() << endl;
				queue<string> name = ord.food.getName();
				while (!name.empty()) {
				inFile<< name.front() << ", "; name.pop();
				}
				inFile << endl << ord.food.getCost() << endl << ord.getTime()<<endl;
				order.pop();

			}
			return 0;
		}
		}
	}
}