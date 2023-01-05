#include"Transaction.h"

template <class T>
Transaction<T>& Transaction<T>::operator=(const Transaction<T>& obj) {
    if (this != &obj) {//проверка на случай obj=obj
        delete currentState;
        currentState = new T(*(obj.currentState));
    }
    return *this;
}

template <class T>
void Transaction<T>::showState(State state,bool stat) {
    cout << "Состояние объекта ";
    if (!state) cout << "до начала транзакции " << endl;
    else cout << "после выполнения транзакции " << endl;
    if (prevState) {
        cout << "prevState = "; if (stat) prevState->getType(); else prevState->getDoc();
    }
    else  cout << "prevState = NULL" << endl;
    cout << "currentState = ";if (stat) currentState->getType(); else currentState->getDoc();
    
}

template <class T>
int Transaction<T>::beginTransactions(string type, bool choice) {
    delete prevState;
    prevState = currentState;
    currentState = new T(*prevState);
    if (!currentState) return 0;
    if (choice) currentState->setType(type);
    else currentState->setDoc(type);
    // currentState->getType();
    return 1;
}
//smartPointer
template <class T>
void Transaction<T>::getTransactions(bool sel) {
    if (sel) currentState->getType(); else currentState->getDoc();
}

template <class T>
void Transaction<T>::commit() {
    delete prevState;
    prevState = NULL;
}
template <class T>
void Transaction<T>::deleteTransactions() {
    if (prevState != NULL) {
        delete currentState;
        currentState = prevState;
        prevState = NULL;
        // currentState->notify();
    }
}

//template<class T>
//void Transaction<T>::addObserverToCurrentState(IObserver<string>* observer)
//{
//  currentState->addObserver(observer);
//}
