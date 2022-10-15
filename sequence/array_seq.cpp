#include <iostream>
#include "array_seq.hpp"
using namespace std;


/**
 * @brief Construct a new Array Sequence object
 * 
 */
ArraySeq::ArraySeq(void) {
    array = NULL;
    size = 0;
}

/**
 * @brief given an iterable X, build sequence from items in X
 * 
 * @param X 
 */
void ArraySeq::Build(int X[], int size) {
    int i;
    array = new int[size];
    this->size = size;
    for(i = 0; i < size; i++) {
        array[i] = X[i];
    }
}

/**
 * @brief Get the item at i
 * 
 * @param i 
 * @return int 
 */
int ArraySeq::GetAt(int i) {
    return array[i];
}

/**
 * @brief Set the item x at i
 * 
 * @param i 
 * @return int 
 */
void ArraySeq::SetAt(int i, int x) {
    array[i] = x;
}

/**
 * @brief Insert Item at the beginning of the array
 * 
 * @param x 
 */
void ArraySeq::InsertFirst(int x) {
    int* newArray;
    int i;

    size += 1; // update size

    newArray = new int[size];
    newArray[0] = x;
    for(i = 1; i < size; i++) {
        newArray[i] = array[i-1];
    }

    delete[] array;
    array = newArray; // update the new array
}

/**
 * @brief Delete item at the beginning of the array
 * 
 */
void ArraySeq::DeleteFirst(void) {
    int* newArray;
    int i;

    size -= 1; // update size

    newArray = new int[size];
    for(i = 1; i < size; i++) {
        newArray[i-1] = array[i];
    }

    delete[] array;
    array = newArray; // update the new array
}

/**
 * @brief Insert Item at the end of the array
 * 
 * @param x 
 */
void ArraySeq::InsertLast(int x) {
    int* newArray;
    int i;

    size += 1; // update size

    newArray = new int[size];
    for(i = 0; i < size-1; i++) {
        newArray[i] = array[i];
    }
    newArray[size-1] = x;

    delete[] array;
    array = newArray; // update the new array
}

/**
 * @brief Delete item at the end of the array
 * 
 */
void ArraySeq::DeleteLast(void) {
    int* newArray;
    int i;

    size -= 1; // update size

    newArray = new int[size];
    for(i = 0; i < size-1; i++) {
        newArray[i] = array[i];
    }

    delete[] array;
    array = newArray; // update the new array
}

/**
 * @brief Insert Item at the i index of the array
 * 
 * @param x 
 */
void ArraySeq::InsertAt(int i, int x) {
    int* newArray;
    int j;

    size += 1; // update size

    newArray = new int[size];
    for(j = 0; j < i; j++) {
        newArray[j] = array[j];
    }
    newArray[i] = x;
    for(j = i+1; j < size; j++) {
        newArray[j] = array[j-1];
    }

    delete[] array;
    array = newArray; // update the new array
}

/**
 * @brief Delete Item at the i index of the array
 * 
 * @param x 
 */
void ArraySeq::DeleteAt(int i) {
    int* newArray;
    int j;

    size -= 1; // update size

    newArray = new int[size];
    for(j = 0; j < i; j++) {
        newArray[j] = array[j];
    }
    for(j = i+1; j < size; j++) {
        newArray[j-1] = array[j];
    }

    delete[] array;
    array = newArray; // update the new array
}

/**
 * @brief print the array
 * 
 */
void ArraySeq::Print(void) {
    int i;
    for(i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

/**
 * @brief Destroy the Sequence object
 * 
 */
ArraySeq::~ArraySeq() {
    delete[] array;
}

