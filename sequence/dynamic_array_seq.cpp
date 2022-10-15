#include <iostream>
#include "dynamic_array_seq.hpp"
using namespace std;


/**
 * @brief 
 * 
 * @param n the new size
 */
void DynamicArraySeq::Resize(int n) {
    int* newArray;
    int i;
    if(this->lower < n && n < this->upper) {
        /* DO NOTHING */
    } else {
        this->length = n * 2;
        this->upper = this->length;
        this->lower = this->length / 4;
        newArray = new int[this->length];
        if(array != NULL) {
            for(i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
        } else {
            /* DO NOTHING */
        }
        array = newArray;
    }
}

DynamicArraySeq::DynamicArraySeq() {
    array = NULL;
    size = 0;
    length = 0;
}
/**
 * @brief given an iterable X, build sequence from items in X
 * 
 * @param X 
 */
void DynamicArraySeq::Build(int X[], int size) {
    int i;
    this->Resize(size);
    this->size = size;
    for(i = 0; i < size; i++) {
        this->array[i] = X[i];
    }
}

/**
 * @brief Get the item at i
 * 
 * @param i 
 * @return int 
 */
int DynamicArraySeq::GetAt(int i) {
    return array[i];
}

/**
 * @brief Set the item x at i
 * 
 * @param i 
 * @return int 
 */
void DynamicArraySeq::SetAt(int i, int x) {
    array[i] = x;
}

/**
 * @brief Insert Item at the beginning of the array
 * 
 * @param x 
 */
void DynamicArraySeq::InsertFirst(int x) {
    int i;

    Resize(size+1);
    size += 1; // update size
    
    for(i = size-1; i >= 0; i--) {
        array[i+1] = array[i];
    }
    array[0] = x;
}

/**
 * @brief Delete item at the beginning of the array
 * 
 */
void DynamicArraySeq::DeleteFirst(void) {
    int i;

    Resize(size-1);
    size -= 1; // update size

    for(i = 0; i < size; i++) {
        array[i] = array[i+1];
    }
}

/**
 * @brief Insert Item at the end of the array
 * 
 * @param x 
 */
void DynamicArraySeq::InsertLast(int x) {
    Resize(size+1);
    size += 1; // update size
    array[size-1] = x;
}

/**
 * @brief Delete item at the end of the array
 * 
 */
void DynamicArraySeq::DeleteLast(void) {
    Resize(size-1);
    size -= 1; // update size
}

/**
 * @brief Insert Item at the i index of the array
 * 
 * @param x 
 */
void DynamicArraySeq::InsertAt(int i, int x) {
    int j;
    Resize(size+1);
    size += 1; // update size

    for(j = size-1; j >= i; j--) {
        array[j+1] = array[j];
    }
    array[i] = x;
}

/**
 * @brief Delete Item at the i index of the array
 * 
 * @param x 
 */
void DynamicArraySeq::DeleteAt(int i) {
    int j;

    Resize(size-1);
    size -= 1; // update size

    for(j = i; j < size; j++) {
        array[j] = array[j+1];
    }
}

/**
 * @brief print the array
 * 
 */
void DynamicArraySeq::Print(void) {
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
DynamicArraySeq::~DynamicArraySeq() {
    delete[] array;
}

