#include<iostream>
#include<string>
#include"Transactions.cpp"
#include"smartPointer.cpp"
using namespace std;
int countType = 0;

class Document
{
    string type[100];
    string doc;

public:
    Document() {

    }
    void setType(string tempType);
    void setDoc(string tempDoc);
    void getDoc();
    void editFormat(int i);
    void getType();
};
class System {
    SmartPointer<Transaction<Document>> type;
    string format;
    string document;
    Transaction<Document>* doc;
    bool sel;   

public:
    System() :format(""), type(new Transaction<Document>),doc(new  Transaction<Document>) {}
    System(string Value, SmartPointer<Transaction<Document>> obj) :
        format(Value),
        type(obj) {

    }
    void writeDoc() {
        cout << "Введите документ: " << endl;
        getchar();
        getline(cin, document);
        sel = false;
        type->beginTransactions(document, sel);
    }
    void editDoc() {
        cout << "Введите номер формата на который хотите изменить свой: " << endl;
        sel = true;
        type->getTransactions(sel);
        int choise;
        cin >> choise;
        type->getCurrentState()->editFormat(choise);
    }
    void back() {
        sel = true;
        type->showState(State::begin, sel);
        type->deleteTransactions();
        type->showState(State::middle, sel);
        countType--;
    }  void backDoc() {
        sel = false;
        type->showState(State::begin, sel);
        type->deleteTransactions();
        type->showState(State::middle, sel);
    }

    void writeFormat() {
        cout << "Введите формат документа: " << endl;
        getchar();
        getline(cin, format);
        sel = true;
        type->beginTransactions(format, sel);
    } 
    void clearBuffer() {
        sel = true;
        type->showState(State::begin,sel);
        type->commit();
        type->showState(State::middle,sel);
    }
    void print() {
        sel = true;

        cout << "Доступные форматы" << endl;
        if (format.empty()) {
            cout << "Упс, ничего нет :(" << endl;
        }
        type->getTransactions(sel);
    } void printDoc() {
        sel = false;

        doc->getTransactions(sel);
    }
};
void Document::setType(string tempType) {

    type[countType] = tempType;
    countType++;
}
void Document::getType() {
    for (int i = 0; i < countType; i++) {
        cout << i<<". ";
        cout << type[i] << endl;
    }
}
void Document::setDoc(string tempDoc) {
   doc = tempDoc;
}
void Document::getDoc() {
    cout << doc << endl;

}
void  Document::editFormat(int i) {
    int point = doc.find('.') + 1;
    string str = type[i];
    doc.replace(point, doc.size() - point,type[i]);
    cout << doc;
}


int menu()
{
    int сhoise;
    cout << "---------------------------------------------------------" << endl;
    cout << "|1 | Введите формат документат                           |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "|2 |Отменить последние добавления формата                |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "|3 |Вывод  добавленых форматов                           |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "|4 |Вывод Счетчика ссылок                                |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "|5 | Ввести название документа (C ФОРМАТОМ ЧЕРЕЗ ТОЧКУ!) |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "|6 |Форматировать документ                               |" << endl;
    cout << "---------------------------------------------------------" << endl;

   // cout << "7 Отменить последние изменения формата" << endl;
    cout << "0 Выйти" << endl;
    cin >> сhoise;
    return сhoise;
}
int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
     SmartPointer<System> SysteM = new System;
    while (true) {

        switch (menu()) {
        case 1: {
            SysteM->writeFormat();
            system("cls");
            SysteM->print();
            break;
        }
        case 2: {
            SysteM->back();
            break;
        }
        case 3: {
            system("cls");
            SysteM->print();
            break;
        }
        case 4: {
            system("cls");
            SysteM->print();
            SysteM.showCounter();
            break;
        }
        case 5: {
            SysteM->writeDoc();
           
            break;
        }
        case 6: {
            SysteM->editDoc();
           
            break;
        }  
       /* case 7: {
            SysteM->backDoc();
           
            break;
        }*/
        case 0: return 0;
        default: {
            cout << "Неправильный ввод" << endl;
        }
        }

    }
}
