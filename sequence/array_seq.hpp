#pragma once

#include <iostream>
#include <cstddef>
#include "sequence.hpp"
using namespace std;

template <class T> 
class ArraySeqIter {
    
    Sequence<T>* seq;
    int i;

    public: 

    public:
    ArraySeqIter() {}
    ~ArraySeqIter() {}

    void SetSeq(Sequence<T>* seq) {
        this->seq = seq;
    }
    void SetIndex(int i) {
        this->i = i;
    }

    T operator*(void) {
        return seq->GetAt(i);
    }
    void operator++(void) {
        i++;
    }
    void operator++(int) {
        i++;
    }
    bool operator==(ArraySeqIter<T> B) {
        return this->seq == B.seq && this->i == B.i;
    }
    bool operator!=(ArraySeqIter<T> B) {
        return this->seq != B.seq || this->i != B.i;
    }
};

template <class T> 
class ArraySeq : public Sequence<T> {
    T* array;
    int size;

    ArraySeqIter<T> begin;
    ArraySeqIter<T> end;

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
        for(i = 0; i < size; i++) {
            newArray[i] = array[i+1];
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
        for(i = 0; i < size; i++) {
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
        for(auto i = Begin(); i != End(); i++) {
            cout << *i << " ";
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

    /**
     * @brief Get an iterator on the start of the sequence
     * 
     */
    virtual ArraySeqIter<T> Begin(void) {
        if(size > 0) {
            begin.SetIndex(0);
        } else {
            begin.SetIndex(-1);
        }
        begin.SetSeq(this);
        return begin;        
    }

    /**
     * @brief Returns an iterator referring to the past-the-end 
     * element in the sequence container.
     * 
     */
    virtual ArraySeqIter<T> End(void) {
        if(size > 0) {
            end.SetIndex(size);
        } else {
            end.SetIndex(-1);
        }
        end.SetSeq(this);
        return end;
    }
};