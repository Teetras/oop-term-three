#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include <windows.h>

using namespace std;
int type=0;

struct Animals
{
    string species, amount, price;
  
};

class PetStore
{
public:
    PetStore()
    {
        name = "Garfild";
        adres = "Minsk,vul. Burd, dom 169";
        cout << "There are no animals in this pet store yet" << endl;

    }
    PetStore(string some_name, string some_adres)
    {
        name = some_name;
        adres = some_adres;
        set_all();
    }
    PetStore(PetStore& store) {
        name = store.name;
        adres = store.adres;
        for (int i = 0; i < type; i++) {
            animals[i].species = store.animals[i].species;
            animals[i].amount = store.animals[i].amount;
            animals[i].price = store.animals[i].price;
        }
    }
    void set_all();
    void get_all();
    void fileWrite();
    ~PetStore() {
        get_all();
    };
    string name;
    string adres;
    Animals animals[100];

};
void PetStore::set_all()
{

    cout << "vvedite colichestvo type animals:" << endl;
    type = 0;

    if ((!(cin >> type)))
    {
        do {
        cout << "ERROR. vvedite cgislo" << endl;
       cin.clear();
        while (cin.get() != '\n');
        cin >> type;
        } while (!cin);
    }
    for (int i = 0; i < type; i++)
    {
        cout << "vvedite name animal:" << endl;
        getchar();
        getline(cin, PetStore::animals[i].species);

        cout << "vvedite amount animals:" << endl;

        getline(cin, PetStore::animals[i].amount);
        cout << "vvedite price animals:" << endl;
        getchar();
        getline(cin, PetStore::animals[i].price);
     

    }
    fileWrite();
}

void PetStore::get_all()
{
    cout << "Name: " << PetStore::name << "\n";
    cout << "Adres: " << PetStore::adres << "\n";
    for (int i = 0; i < type; i++) {
        cout << PetStore::animals[i].species << endl;
        cout << PetStore::animals[i].amount << endl;
        cout << PetStore::animals[i].price << endl;
    }
}
void PetStore::fileWrite()
{
    ofstream f;
    f.open("ZooStore.txt");
    if (!f.is_open())
    {
        cout << "Error with creation of file" << endl;
    }
    else
    {
        f << PetStore::name << endl;
        f << PetStore::adres << endl;
        for (int i = 0; i < type; i++)
        {
            f << PetStore::animals[i].species << " ";
            f << PetStore::animals[i].amount << " ";
            f << PetStore::animals[i].price << endl;
        }
    }
}
int main()
{
    // system("color F3");
    string some_name;
    string some_adres;

    cout << "vvedite name petStore:";
    cin >> some_name;
    cout << "vvedite adres petStore:";
    getchar();
    getline(cin, some_adres);
    if (!cin)
    {
        PetStore* store1 = new PetStore();
    }

    PetStore* store2 = new PetStore(some_name, some_adres);
    cout << "\n";
    cout << "data saveda" << endl;
    PetStore* store3 = new PetStore(*store2);
    /*cout << "\n" << "Store2" << "\n";
    store2->get_all();*/
    cout << endl;
    cout << "\n" << "Danni Store2 skopirovani u Store3" << "\n";

    delete store2;
}