#include <iostream>
#include "selection_sort.hpp"
using namespace std;

int main(void) {
    int A[] = {
        9,
        2,
        3,
        5,
        6,
        8,
        1,
        0
    };
    int A_size = sizeof(A)/sizeof(A[0]);
    int i;

    cout << "The array initially:\n";
    for(i = 0; i < A_size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "The selection sort:\n";
    SelectionSort::Sort(A, A_size);

    for(i = 0; i < A_size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}