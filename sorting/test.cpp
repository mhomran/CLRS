#include <iostream>
#include "../sequence/array_seq.hpp"
#include "selection_sort.hpp"
#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "direct_access_array_sort.hpp"

using namespace std;

void MyMemcpy(int Src[], ArraySeq<int>& Dst) {
    int i;
    for(i = 0; i < Dst.GetSize(); i++) {
        Dst.SetAt(i, Src[i]);
    }
}

int main(void) {
    int A[] = { 9, 2, 3, 7, 5, 6, 8, 1, 0 };
    int A_size = sizeof(A)/sizeof(A[0]);

    ArraySeq<int> Dst;

    Dst.Build(A, A_size);

    cout << "The array initially (odd):\n";
    MyMemcpy(A, Dst);
    Dst.Print();

    cout << "The Selection sort:\n";
    SelectionSort::Sort(Dst);
    Dst.Print();

    cout << "The sequence initially (odd):\n";
    MyMemcpy(A, Dst);
    Dst.Print();

    cout << "The Insertion sort:\n";
    InsertionSort::Sort(Dst);
    Dst.Print();

    cout << "The array initially (odd):\n";
    MyMemcpy(A, Dst);
    Dst.Print();

    cout << "The Merge sort:\n";
    MergeSort::Sort(Dst, 0, A_size-1);
    Dst.Print();

    cout << "The array initially (odd):\n";
    MyMemcpy(A, Dst);
    Dst.Print();

    cout << "The direct access array sort:\n";
    DirectAccessArraySort::Sort(Dst);
    Dst.Print();

    Dst.DeleteFirst(); /* delete the first item -> makes it even */

    cout << "The sequence initially (even):\n";
    MyMemcpy(A, Dst);
    Dst.Print();

    cout << "The Selection sort:\n";
    SelectionSort::Sort(Dst);
    Dst.Print();

    cout << "The sequence initially (even):\n";
    MyMemcpy(A, Dst);
    Dst.Print();

    cout << "The Insertion sort:\n";
    InsertionSort::Sort(Dst);
    Dst.Print();

    cout << "The array initially (even):\n";
    MyMemcpy(A, Dst);
    Dst.Print();

    cout << "The Merge sort:\n";
    MergeSort::Sort(Dst, 0, Dst.GetSize()-1);
    Dst.Print();

    cout << "The array initially (even):\n";
    MyMemcpy(A, Dst);
    Dst.Print();

    cout << "The direct access array sort:\n";
    DirectAccessArraySort::Sort(Dst);
    Dst.Print();
}