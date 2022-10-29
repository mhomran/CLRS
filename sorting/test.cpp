#include <iostream>
#include "../sequence/array_seq.hpp"
#include "selection_sort.hpp"
#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "direct_access_array_sort.hpp"
#include "counting_sort.hpp"
#include "radix_sort.hpp"
#include "../set/set.hpp"

using namespace std;

void MyMemcpy(Pair<char> Src[], ArraySeq<Pair<char>>& Dst) {
    int i;
    for(i = 0; i < Dst.GetSize(); i++) {
        Dst.SetAt(i, Src[i]);
    }
}

int main(void) {
    int data[] = { 20, 13, 7, 15, 20, 6, 8, 1, 0 };
    int A_size = sizeof(data)/sizeof(data[0]);
    Pair<char>* A;
    ArraySeq<Pair<char>> Dst;
    int i;

    A = new Pair<char>[A_size];

    for(i = 0; i < A_size; i++) {
        A[i].SetKey(data[i]);
        A[i].SetItem(' ');
    }

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

    cout << "The direct access array sort: (Keys are NOT unique)\n";
    DirectAccessArraySort::Sort(Dst);
    Dst.Print();

    cout << "The array initially (odd):\n";
    MyMemcpy(A, Dst);
    Dst.Print();

    cout << "The counting sort:\n";
    CountingSort::Sort(Dst);
    Dst.Print();

    cout << "The array initially (odd):\n";
    MyMemcpy(A, Dst);
    Dst.Print();

    cout << "The radix sort:\n";
    RadixSort::Sort(Dst);
    Dst.Print();

    cout << "---------------------------------------\n";
    Dst.DeleteFirst(); /* delete the first item -> makes it even */

    cout << "The sequence initially (even):\n";
    MyMemcpy(&A[1], Dst);
    Dst.Print();

    cout << "The Selection sort:\n";
    SelectionSort::Sort(Dst);
    Dst.Print();

    cout << "The sequence initially (even):\n";
    MyMemcpy(&A[1], Dst);
    Dst.Print();

    cout << "The Insertion sort:\n";
    InsertionSort::Sort(Dst);
    Dst.Print();

    cout << "The array initially (even):\n";
    MyMemcpy(&A[1], Dst);
    Dst.Print();

    cout << "The Merge sort:\n";
    MergeSort::Sort(Dst, 0, Dst.GetSize()-1);
    Dst.Print();

    cout << "The array initially (even):\n";
    MyMemcpy(&A[1], Dst);
    Dst.Print();

    cout << "The direct access array sort:\n";
    DirectAccessArraySort::Sort(Dst);
    Dst.Print();

    cout << "The array initially (even):\n";
    MyMemcpy(&A[1], Dst);
    Dst.Print();

    cout << "The counting sort:\n";
    CountingSort::Sort(Dst);
    Dst.Print();

    cout << "The array initially (even):\n";
    MyMemcpy(&A[1], Dst);
    Dst.Print();

    cout << "The radix sort:\n";
    RadixSort::Sort(Dst);
    Dst.Print();

    delete[] A;
}