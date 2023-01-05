#pragma once

#include<iostream>

using namespace std;
enum State { begin, middle };
template <class T>
class Transaction {
    T* currentState;
    T* prevState;
public:
    Transaction() :prevState(NULL), currentState(new T) {}
    Transaction(const Transaction& obj) : currentState(new
        T(*(obj.currentState))), prevState(NULL) {}
    ~Transaction() {
        delete currentState; delete prevState;
    }
    Transaction& operator=(const Transaction& obj);
    void showState(State state, bool stat);
    int beginTransactions(string data, bool choise);
    void getTransactions(bool sel);
    T* getCurrentState() {
        return currentState;

    }
    void commit();
    void deleteTransactions();


};
