#include <iostream>
#include "sorted_array_set.hpp"
using namespace std;

int main(void) {
    SortedArraySet* A = new SortedArraySet();
    int i;
    int X[7];
    for(i = 0; i < 7; i++) {
        X[i] = i + 1;
    }

    cout << "Testing Build(X, 7):\n";
    A->Build(X, 7);
    A->Print();

    delete A;
}