#include <iostream>
#include "linked_list_seq.hpp"
using namespace std;

int main() {
    LinkedListSeq<int>* A = new LinkedListSeq<int>();
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
    cout << "testing InsertAt(0, 10):\n";
    A->InsertAt(0, 10);
    A->Print();
    cout << "testing InsertAt(9, 9) (no item @ 9):\n";
    A->InsertAt(9, 9);
    A->Print();
    cout << "testing InsertAt(1, 20):\n";
    A->InsertAt(1, 20);
    A->Print();

    cout << "testing DeleteAt(3):\n";
    A->DeleteAt(3);
    A->Print();
    cout << "testing DeleteAt(0):\n";
    A->DeleteAt(0);
    A->Print();
    cout << "testing DeleteAt(7):\n";
    A->DeleteAt(7);
    A->Print();
    cout << "testing DeleteAt(7) (out of range):\n";
    A->DeleteAt(7);
    A->Print();
    

    delete A;
}