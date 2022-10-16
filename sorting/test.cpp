#include <iostream>
#include "selection_sort.hpp"
#include "insertion_sort.hpp"
using namespace std;

void MyMemcpy(int src[], int dst[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        dst[i] = src[i];
    }
}

void PrintArray(int A[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

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
    int B[] = {
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

    cout << "The array initially:\n";
    MyMemcpy(B, A, A_size);
    PrintArray(A, A_size);

    cout << "The selection sort :\n";
    SelectionSort::Sort(A, A_size);
    PrintArray(A, A_size);

    cout << "The array initially:\n";
    MyMemcpy(B, A, A_size);
    PrintArray(A, A_size);

    cout << "The Insertion sort:\n";
    InsertionSort::Sort(A, A_size);
    PrintArray(A, A_size);

}