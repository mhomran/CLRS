#include <iostream>
#include <cstddef>
#include "sequence.hpp"
using namespace std;

template <class T> 
class DynamicArraySeq : public Sequence<T> {
    T* array;
    int size;
    int lower;
    int upper;
    int length;

    void Resize(int n) {
        T* newArray;
        int i;
        if(this->lower < n && n < this->upper) {
            /* DO NOTHING */
        } else {
            this->length = n * 2;
            this->upper = this->length;
            this->lower = this->length / 4;
            newArray = new T[this->length];
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
    public:
    
    /**
     * @brief Construct a new Array Seq object
     * 
     */
    DynamicArraySeq(void) {
        array = NULL;
        size = 0;
        length = 0;
    }

    /**
     * @brief Destroy the Array Seq object
     * 
     */
    ~DynamicArraySeq(void) {
        delete[] array;
    }

    /**
     * @brief given an iterable X, build sequence from items in X
     * 
     * @param X 
     */
    virtual void Build(T X[], int size) {
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
        int i;

        Resize(size+1);
        size += 1; // update size
        
        for(i = size-1; i >= 0; i--) {
            array[i+1] = array[i];
        }
        array[0] = x;
    }

    /**
     * @brief Delete item at the beginning of the sequence
     * 
     */
    virtual void DeleteFirst(void) {
        int i;

        Resize(size-1);
        size -= 1; // update size

        for(i = 0; i < size; i++) {
            array[i] = array[i+1];
        }
    }

    /**
     * @brief Insert Item at the end of the sequence
     * 
     * @param x 
     */
    virtual void InsertLast(T x) {
        Resize(size+1);
        size += 1; // update size
        array[size-1] = x;
    }

    /**
     * @brief Delete item at the end of the sequence
     * 
     */
    virtual void DeleteLast(void) {
        Resize(size-1);
        size -= 1; // update size
    }

    /**
     * @brief Insert Item at the i index of the sequence
     * 
     * @param x 
     */
    virtual void InsertAt(int i, T x) {
        int j;
        if(i == size) {
            this->InsertLast(x);
        } else if (i < size) {
            Resize(size+1);
            size += 1; // update size

            for(j = size-1; j >= i; j--) {
                array[j+1] = array[j];
            }
            array[i] = x;
        }
    }

    /**
     * @brief Delete Item at the i index of the sequence
     * 
     * @param x 
     */
    virtual void DeleteAt(int i) {
        int j;

        Resize(size-1);
        size -= 1; // update size

        for(j = i; j < size; j++) {
            array[j] = array[j+1];
        }
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
    int GetSize(void) {
        return size;
    }
};