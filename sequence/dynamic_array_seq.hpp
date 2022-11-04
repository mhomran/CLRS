#include <iostream>
#include <cstddef>
#include "sequence.hpp"
using namespace std;

template <class T> 
class DynamicArraySeqIter {
    
    Sequence<T>* seq;
    int i;

    public: 

    public:
    DynamicArraySeqIter() {
        seq = NULL;
        i = -1;
    }

    DynamicArraySeqIter(const DynamicArraySeqIter& A) {
        seq = A.seq;
        i = A.i;
    }

    ~DynamicArraySeqIter() {}

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
    bool operator==(DynamicArraySeqIter<T> B) {
        return this->seq == B.seq && this->i == B.i;
    }
    bool operator!=(DynamicArraySeqIter<T> B) {
        return this->seq != B.seq || this->i != B.i;
    }
};

template <class T> 
class DynamicArraySeq : public Sequence<T> {
    T* array;
    int size;
    int lower;
    int upper;
    int length;


    DynamicArraySeqIter<T> begin;
    DynamicArraySeqIter<T> end;

    void Resize(int n) {
        T* newArray;
        int i;
        if(0 == n) {
            delete[] array;
            array = NULL;
            lower = 0;
            upper = 0;
            length = 0;
        } else {
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
    }
    public:
    
    /**
     * @brief Construct a new Array Seq object
     * 
     */
    DynamicArraySeq(void) {
        array = NULL;
        size = 0;
        lower = 0;
        upper = 0;
        length = 0;
    }
    
    void DeepCopy(const DynamicArraySeq& A) {
        int i;

        length = A.length;
        if(length > 0) array = new T[length];
        else array = NULL;
        size = A.size;
        upper = A.upper;
        lower = A.lower;
        for(i = 0; i < size; i++) {
            array[i] = A.array[i];
        }
    }

    /**
     * @brief Construct a new Array Seq object
     * 
     */
    DynamicArraySeq(const DynamicArraySeq& A) {
        DeepCopy(A);
    }

    DynamicArraySeq& operator= (const DynamicArraySeq& A) {
        DeepCopy(A);
        return *this;
    }

    /**
     * @brief Destroy the Array Seq object
     * 
     */
    ~DynamicArraySeq(void) {
        if(NULL != array) delete[] array;
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
    int GetSize(void) {
        return size;
    }

    /**
     * @brief Get an iterator on the start of the sequence
     * 
     */
    virtual DynamicArraySeqIter<T> Begin(void) {
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
    virtual DynamicArraySeqIter<T> End(void) {
        if(size > 0) {
            end.SetIndex(size);
        } else {
            end.SetIndex(-1);
        }
        end.SetSeq(this);
        return end;
    }
};