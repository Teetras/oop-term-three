#include"Document.h"
#include<Windows.h>
#include<memory>
#include<vector>
#include"PaperWork.h"
#include"File.h"
#include<algorithm>

using namespace std;

int menu() {
	cout <<endl<< "-----------------------------------------------" << endl;
	cout << "| 1. ��������                                  |" << endl;
	cout << "| 2. �������� �����                            |" << endl;
	cout << "| 3. �������� ������ ���������� ���������������|" << endl;
	cout << "| 4. ������� ������                            |" << endl;
	cout << "| 5. ����� ������                              |" << endl;
	cout << "| 6. �����                                     |" << endl;
	cout << "-----------------------------------------------" << endl;

	int ch;
	cin >> ch;
	return ch;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	File* file = new File;
	vector<Document*> docs = file->read();
	DocumentFabric* fabric = new DocumentFabric;


	while (true) {
		switch (menu()) {
		case 1: {
			int counter = 0;
			cout << endl;
			cout << "�����" << "\t" << setw(35) << "��������������" << "\t" << setw(10) << "���-�� �������/���������" << "\t" << setw(8) << "������� ��������/������" << endl;
			for (auto item : docs) {

				item->getSpecification(counter);
				counter++;
			}
			cout << endl;
			break;
		}
		case 2: {
			cout << "�������� �������: " << endl;
			cout << "1. �������" << endl;
			cout << "2. ������� � �����������" << endl;
			cout << "3. ����������� �������" << endl;
			cout << "4. ����������� �����������" << endl;
			int ch;
			cin >> ch;
			switch (ch)
			{
			case 1: {
				Document* doc = fabric->makeDocument(Documents::Descriptionn);
				doc->setSpecification();
				docs.push_back(doc);
				break;
			}
			case 2: {
				string name, adress;
				float square;
				cout << "������� �������� �����: " << endl;
				getchar();
				getline(cin, name);
				cout << "������� ��������: " << endl;
				getchar();
				getline(cin, adress);
				cout << "������� ���������� �������: " << endl;
				cin >> square;
				DocumentSpec* spec = new DescriptionSpec(name, square, adress);
				Document* doc = fabric->makeDocument(spec);
				docs.push_back(doc);
				break;
			}
			case 3: {
				PaperWork* pap = new MakingRentContract;
				Document* docc = pap->makeDoc();
				docc->setSpecification();
				docs.push_back(docc);
				break;
			}
			case 4: {
				unique_ptr<Document> p(new Description);
				p->setSpecification();
				unique_ptr<Document> b = p->clone();
				docs.push_back(b.get());
				break;
			}
			default: cout << "�������� ����" << endl; break;
			}
			file->write(docs);
			break;
		}
		case 3: {
			cout << "�������� �������: " << endl;
			cout << "1. �������" << endl;
			cout << "2. ������� � �����������" << endl;
			cout << "3. ����������� �������" << endl;
			cout << "4. ����������� �����������" << endl;
			int ch;
			cin >> ch;
			switch (ch)
			{
			case 1: {
				Document* doc = fabric->makeDocument(Documents::Formatt);
				doc->setSpecification();
				docs.push_back(doc);
				break;
			}
			case 2: {
				string name, occupation;
				float salary;
				cout << "������� �������� ������: " << endl;
				getchar();
				getline(cin, name);
				cout << "������� ������: " << endl;
				getchar();
				getline(cin, occupation);
				cout << "������� ���������: " << endl;
				cin >> salary;
				DocumentSpec* spec = new FormatSpec(name, salary, occupation);
				Document* doc = fabric->makeDocument(spec);
				docs.push_back(doc);
				break;
			}
			case 3: {
				PaperWork* pap = new MakingEmpoloymentContract;
				Document* docc = pap->makeDoc();
				docc->setSpecification();
				docs.push_back(docc);
				break;
			}
			case 4: {
				unique_ptr<Document> p(new Format);
				p->setSpecification();
				unique_ptr<Document> b = p->clone();
				docs.push_back(b.get());
				break;
			}
			default: cout << "�������� ����" << endl; break;
			}
			file->write(docs);
			break;
		}
		case 4: {
			cout << "������� ����� ��������� ������: " << endl;
			int numb;
			cin >> numb;
			docs.erase(docs.begin() + numb);
			file->write(docs);
			break;
		}
		case 5: {
			cout << "������� �������� ������ ��� ������: " << endl;
			string name;
			getchar();
			getline(cin, name);

			vector<Document*> temp;
			copy_if(docs.begin(), docs.end(), back_inserter(temp), [&name](Document* doc) {
				return doc->getName() == name;
				});
			if (temp.empty()) {
				cout << "��� ������" << endl;
			}
			else {
				for (auto item : temp) {

					item->getSpecification(0);

				}
			}
			break;
		}
		case 6: {
			file->write(docs);
			return 0;
			break;
		}
		default: cout << "�������� ����" << endl; break;
		}
	}

}
