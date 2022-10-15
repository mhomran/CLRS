#include <iostream>
#include "dynamic_array_seq.hpp"
using namespace std;

int main() {
    DynamicArraySeq* A = new DynamicArraySeq();
    int i;
    int X[7];
    for(i = 0; i < 7; i++) {
        X[i] = i + 1;
    }
    
    cout << "Testing Build(X, 7):\n";
    A->Build(X, 7);
    A->Print();

    cout << "Testing SetAt(5, 50):\n";
    A->SetAt(5, 50);
    A->Print();
    
    cout << "Testing GetAt(5):\n";
    cout << A->GetAt(5) << endl;

    cout << "testing InsertFirst and Print:\n";
    A->InsertFirst(20);
    A->Print();

    cout << "testing DeleteFirst:\n";
    A->DeleteFirst();
    A->Print();

    cout << "testing InsertLast:\n";
    A->InsertLast(50);
    A->Print();
    
    cout << "testing DeleteLast:\n";
    A->DeleteLast();
    A->Print();
    
    cout << "testing InsertAt(3, 20):\n";
    A->InsertAt(3, 20);
    A->Print();

    cout << "testing DeleteAt(3):\n";
    A->DeleteAt(3);
    A->Print();

    delete A;
}