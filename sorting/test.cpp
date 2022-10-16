#include <iostream>
#include "selection_sort.hpp"
#include "insertion_sort.hpp"
#include "merge_sort.hpp"
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
        7,
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
        7,
        5,
        6,
        8,
        1,
        0
    };

    int X[] = {
        9,
        2,
        3,
        7,
        5,
        6,
        8,
        1,
        0,
        4
    };
    int Y[] = {
        9,
        2,
        3,
        7,
        5,
        6,
        8,
        1,
        0,
        4
    };
    int A_size = sizeof(A)/sizeof(A[0]);
    int X_size = sizeof(X)/sizeof(X[0]);

    cout << "The array initially (odd):\n";
    MyMemcpy(B, A, A_size);
    PrintArray(A, A_size);

    cout << "The Selection sort:\n";
    SelectionSort::Sort(A, A_size);
    PrintArray(A, A_size);

    cout << "The array initially (odd):\n";
    MyMemcpy(B, A, A_size);
    PrintArray(A, A_size);

    cout << "The Insertion sort:\n";
    InsertionSort::Sort(A, A_size);
    PrintArray(A, A_size);

    cout << "The array initially (odd):\n";
    MyMemcpy(B, A, A_size);
    PrintArray(A, A_size);

    cout << "The Merge sort:\n";
    MergeSort::Sort(A, 0, A_size-1);
    PrintArray(A, A_size);

    cout << "The array initially (even):\n";
    MyMemcpy(Y, X, X_size);
    PrintArray(X, X_size);

    cout << "The Selection sort:\n";
    SelectionSort::Sort(X, X_size);
    PrintArray(X, X_size);

    cout << "The array initially (even):\n";
    MyMemcpy(Y, X, X_size);
    PrintArray(X, X_size);

    cout << "The Insertion sort:\n";
    InsertionSort::Sort(X, X_size);
    PrintArray(X, X_size);

    cout << "The array initially (even):\n";
    MyMemcpy(Y, X, X_size);
    PrintArray(X, X_size);

    cout << "The Merge sort:\n";
    MergeSort::Sort(X, 0, X_size-1);
    PrintArray(X, X_size);

}