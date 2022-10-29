#include <iostream>
#include "hash_table_set.hpp"

using namespace std;

int main(void) { 
    HashTableSet<int>* A;
    int i;
    Pair<int>* X;
    Pair<int> x;
    Pair<int> found;
    int Keys[] = { 9, 2, 3, 7, 5, 6, 8, 1, 0 };
    int Keys_size = sizeof(Keys)/sizeof(Keys[0]);

    A = new HashTableSet<int>();
    X = new Pair<int>[Keys_size];

    for(i = 0; i < Keys_size; i++) {
        X[i].SetKey(Keys[i]);
        X[i].SetItem(700);
    }

    cout << "Testing Build(X, Keys_size):\n";
    A->Build(X, Keys_size);
    A->Print();
    
    cout << "Testing Find(4):\n";
    found = A->Find(4);
    if(-1 == found.GetKey()) {
        cout << "Key error: 4" << endl;
    } else {
        cout << found << endl;
    }

    cout << "Testing Find(30):\n";
    found = A->Find(30);
    if(-1 == found.GetKey()) {
        cout << "Key error: 30" << endl;
    } else {
        cout << found << endl;
    }

    cout << "Testing Find(3):\n";
    found = A->Find(3);
    if(-1 == found.GetKey()) {
        cout << "Key error: 3" << endl;
    } else {
        cout << found << endl;
    }

    cout << "Testing FindNext(3):\n";
    found = A->FindNext(3);
    if(-1 == found.GetKey()) {
        cout << "Key error: 3" << endl;
    } else {
        cout << found << endl;
    }

    cout << "Testing FindNext(30):\n";
    found = A->FindNext(30);
    if(-1 == found.GetKey()) {
        cout << "Key error: 30" << endl;
    } else {
        cout << found << endl;
    }

    cout << "Testing FindPrev(3):\n";
    found = A->FindPrev(3);
    if(-1 == found.GetKey()) {
        cout << "Key error: 3" << endl;
    } else {
        cout << found << endl;
    }

    cout << "Testing FindPrev(30):\n";
    found = A->FindPrev(30);
    if(-1 == found.GetKey()) {
        cout << "Key error: 30" << endl;
    } else {
        cout << found << endl;
    }
 
    cout << "Testing FindMin():\n";
    found = A->FindMin();
    if(-1 == found.GetKey()) {
        cout << "No minimum" << endl;
    } else {
        cout << found << endl;
    }

    cout << "Testing FindMax():\n";
    found = A->FindMax();
    if(-1 == found.GetKey()) {
        cout << "No maximum" << endl;
    } else {
        cout << found << endl;
    }

    x.SetKey(3);
    x.SetItem(500);
    cout << "Testing Insert(x) x is (3, 500):\n";
    A->Insert(x);
    A->Print();

    x.SetKey(4);
    x.SetItem(700);
    cout << "Testing Insert(x) x is (4, 700):\n";
    A->Insert(x);
    A->Print();

    cout << "Testing Delete(3):\n";
    A->Delete(3);
    A->Print();

    delete A;
    delete[] X;
}