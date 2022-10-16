#pragma once

#include <iostream>
#include <cstddef>
#include "sequence.hpp"
using namespace std;

template <class T> 
class ArraySeq : public Sequence<T> {
    T* array;
    int size;

    public:
    
    /**
     * @brief Construct a new Array Seq object
     * 
     */
    ArraySeq(void) {
        array = NULL;
        size = 0;
    }

    /**
     * @brief Destroy the Array Seq object
     * 
     */
    ~ArraySeq(void) {
        delete[] array;
    }

    /**
     * @brief given an iterable X, build sequence from items in X
     * 
     * @param X 
     */
    virtual void Build(T X[], int size) {
        int i;
        array = new T[size];
        this->size = size;
        for(i = 0; i < size; i++) {
            array[i] = X[i];
        }
    }

    /**
     * @brief Get the item at i
     * 
     * @param i 
     * @return T 
     */
    virtual T GetAt(int i){
        return array[i];
    }

    /**
     * @brief Set the item x at i
     * 
     * @param i 
     * @return int 
     */
    virtual void SetAt(int i, T x) {
        array[i] = x;
    }

    /**
     * @brief Insert Item at the beginning of the sequence
     * 
     * @param x 
     */
    virtual void InsertFirst(T x) {
        T* newArray;
        int i;

        size += 1; // update size

        newArray = new T[size];
        newArray[0] = x;
        for(i = 1; i < size; i++) {
            newArray[i] = array[i-1];
        }

        delete[] array;
        array = newArray; // update the new array
    }

    /**
     * @brief Delete item at the beginning of the sequence
     * 
     */
    virtual void DeleteFirst(void) {
        T* newArray;
        int i;

        size -= 1; // update size

        newArray = new T[size];
        for(i = 1; i < size; i++) {
            newArray[i-1] = array[i];
        }

        delete[] array;
        array = newArray; // update the new array
    }

    /**
     * @brief Insert Item at the end of the sequence
     * 
     * @param x 
     */
    virtual void InsertLast(T x) {
        T* newArray;
        int i;

        size += 1; // update size

        newArray = new T[size];
        for(i = 0; i < size-1; i++) {
            newArray[i] = array[i];
        }
        newArray[size-1] = x;

        delete[] array;
        array = newArray; // update the new array
    }

    /**
     * @brief Delete item at the end of the sequence
     * 
     */
    virtual void DeleteLast(void) {
        T* newArray;
        int i;

        size -= 1; // update size

        newArray = new T[size];
        for(i = 0; i < size-1; i++) {
            newArray[i] = array[i];
        }

        delete[] array;
        array = newArray; // update the new array
    }

    /**
     * @brief Insert Item at the i index of the sequence
     * 
     * @param x 
     */
    virtual void InsertAt(int i, T x) {
        T* newArray;
        int j;
        if(i == size) {
            this->InsertLast(x);
        } else if(i < size) {
            size += 1; // update size

            newArray = new T[size];
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
    }

    /**
     * @brief Delete Item at the i index of the sequence
     * 
     * @param x 
     */
    virtual void DeleteAt(int i) {
        T* newArray;
        int j;

        size -= 1; // update size

        newArray = new T[size];
        for(j = 0; j < i; j++) {
            newArray[j] = array[j];
        }
        for(j = i; j < size; j++) {
            newArray[j] = array[j+1];
        }

        delete[] array;
        array = newArray; // update the new array
    }

    /**
     * @brief print the sequence
     * 
     */
    virtual void Print(void) {
        int i;
        for(i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    /**
     * @brief Get the Size object
     * 
     * @return int 
     */
    virtual int GetSize(void) {
        return size;
    }
};