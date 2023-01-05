/*������� ����� ������� �� ���� ����� ����, ����� �� �������
����� ����� Library (����������). ������������� ����������� ������ ����� �� ������-����
��������, ���������� ���� � ����������, �������� ���� �� ���. �������� ���������, ���������������
������ � ���� �������. � ����� �������� ����������� ����� ����� �
������� (������� ��� ���� � ��� ������) �� ���� ����������. ������� �����
��� ������ ���������� ������ � ����. ������� ������ ������� � �����
������.*/
#include<iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;

int i = 0;
bool searching = false;
class BookAccountant
{
public:
    virtual void putData() = 0;
    virtual void getData() = 0;
   virtual void writeFile() = 0;
  virtual  void search(int del) = 0;
};

class Library: public BookAccountant {
protected:
    string name;
    string author;
public:

    void putData()  {
        cout << "H������� �����: " << name << endl;
        cout << "A����� " << author << endl;

    }
     void getData() {
        cout << "������� �������� �����: ";
        cin.ignore(32767, '\n');
        getline(cin, name, '\n');
        cout << "������� ������: ";
        //cin.ignore(32767, '\n');
        getline(cin, author, '\n');
        
    }
     void writeFile()
     {
         ofstream f;
         f.open("source0.txt", ios::app);
         if (!f.is_open())
         {
             cout << "Error with creation of file" << endl;
         }
         else
         {
             f << name << endl << author<< endl;
         }
         f.close();
        
     }
   /* void readFile()
    {
        ifstream f;
        f.open("source0.txt", ios::in);
        if (!f.is_open())
        {
            cout << "Error with creation of file" << endl;
        }
        else
        {
            if (f.eof()) f >> name>> author ;
        }
        f.close();
    }*/
};

class Book :public Library {
protected:
    int yearOfPublic, numberPag;

public:
    void putData()  {
        Library::putData();
        cout << "K��������� ������� �����:";
        cout << numberPag << endl;
        cout << "��� �������: "<< yearOfPublic <<endl;

    }
    void getData() {
    Library::getData();
        cout << "������� ���������� ������� �����:";
        if ((!(cin >> numberPag)))
        {
            do {
                cout << "ERROR. vvedite cgislo" << endl;
                cin.clear();
                while (cin.get() != '\n');
                cin >> numberPag;
            } while (!cin);
        }
        cout << "��� �������: ";
        if ((!(cin >> yearOfPublic)))
        {
            do {
                cout << "ERROR. vvedite cgislo" << endl;
                cin.clear();
                while (cin.get() != '\n');
                cin >> yearOfPublic;
            } while (!cin);
        }
     
    }
    void writeFile()
    {
        ofstream f;
        f.open("source0.txt", ios::app);
        if (!f.is_open())
        {
            cout << "Error with creation of file" << endl;
        }
        else
        {
            f << yearOfPublic << endl << numberPag << endl;
        }
        f.close();
    Library:: writeFile();
    }
  /*  void readFile()
    {
        ifstream f;
        f.open("source0.txt", ios::in);
        if (!f.is_open())
        {
            cout << "Error with creation of file" << endl;
        }
        else
        {
            if (f.eof()) f >> yearOfPublic >> numberPag;
        }
        f.close();
        Library::readFile();
    }*/
};
class BookState : public Book
{
protected:
    int number;
    string availability;
public:
    void getData()  {
    Book::getData();
        cout << "������� ����� ����� � ����������: ";
        if ((!(cin >> number)))
        {
            do {
                cout << "ERROR. vvedite cgislo" << endl;
                cin.clear();
                while (cin.get() != '\n');
                cin >> number;
            } while (!cin);
        }
        cout << "������� �����, ���� ����� ���� ������ ������� ���� ������.����� - '� �������':" << endl;
        cin.ignore(32767, '\n');
        getline(cin, availability, '\n');
       
    }
    void putData ()   {
        Book::putData();
        cout << "H���� ����� � ����������: "<<number<<endl;
        cout << "���� ������ �����: "<<availability<<endl;
    }
    void writeFile()
    {
        ofstream f;
        f.open("source0.txt", ios::app);
        if (!f.is_open())
        {
            cout << "Error with creation of file" << endl;
        }
        else
        {
            f << number << endl << availability << endl;
        }
        f.close();
       Book:: writeFile();
    }
  /*  void readFile()
    {
        ifstream f;
        f.open("source0.txt", ios::in);
        if (!f.is_open())
        {
            cout << "Error with creation of file" << endl;
        }
        else
        {
            if (f.eof()) { f >> number >> availability;i++; }
            
        }
        f.close();
        Book::readFile();
    }*/
    void search(int del)
    {
	    if(number==del)
	    {
            searching = true;
	    }
    }
};
int main() {
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    int choise;
  
    BookAccountant* n1[100];
    BookState n2[100];
 
    do {
        cout << "1. �������� �����" << endl;
        cout << "2. ��������" << endl;
        cout << "3. ������� �����" << endl;
        cout << "4. �������� � ����" << endl;
        cout << "0. �����" << endl;
        cin >> choise;
        switch (choise) {
        case 1:
        {
            n2[i].getData();
            n1[i] = &n2[i];
            i++;
            break;}
        case 2:
        { for (int j = 0; j < i; j++)
        {
            n1[j]->putData();
        }
        break;
        }
        case 3: {
            int del;
            cout << "������� ����� �����, ������� ������ �������";
            cin >> del;
        		for (int j = 0; j < i; j++)
                {
                    searching = false;
                    n1[j]->search(del);
                    if(searching)
                    {
                    	i--;
                      for (int k = j;k < i;k++) {
                        n1[j] = n1[j + 1];
                      }
                       
                    }
                }
        } break;
        case 4: { for (int j = 0; j < i; j++)
        {
            n1[j]->writeFile();
        };}
            ; break;
        case 5:; break;
        case 0:return 0;
        }

        } while (true);
    
}