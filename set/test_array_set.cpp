#include <iostream>
#include "set_from_seq.hpp"
#include "../sequence/linked_list_seq.hpp"
using namespace std;

int main(void) { 
    SetFromSeq<int, LinkedListSeq<Pair<int>>>* A = new SetFromSeq<int, LinkedListSeq<Pair<int>>>();
    int i;
    Pair<int>* X;
    Pair<int> x;
    int Keys[] = { 9, 2, 3, 7, 5, 6, 8, 1, 0 };
    int Keys_size = sizeof(Keys)/sizeof(Keys[0]);

    X = new Pair<int>[Keys_size];

    for(i = 0; i < Keys_size; i++) {
        X[i].SetKey(Keys[i]);
        X[i].SetItem(700);
    }

    cout << "Testing Build(X, Keys_size):\n";
    A->Build(X, Keys_size);
    A->Print();
    
    cout << "Testing Find(4):\n";
    cout << A->Find(4) << endl;

    cout << "Testing Find(30):\n";
    cout << A->Find(30) << endl;

    cout << "Testing Find(3):\n";
    cout << A->Find(3) << endl;

    cout << "Testing FindNext(3):\n";
    cout << A->FindNext(3) << endl;

    cout << "Testing FindNext(30):\n";
    cout << A->FindNext(30) << endl;

    cout << "Testing FindPrev(3):\n";
    cout << A->FindPrev(3) << endl;

    cout << "Testing FindPrev(30):\n";
    cout << A->FindPrev(30) << endl;
 
    cout << "Testing FindMin():\n";
    cout << A->FindMin() << endl;

    cout << "Testing FindMax():\n";
    cout << A->FindMax() << endl;

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
}