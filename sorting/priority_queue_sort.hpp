#pragma once
#include "../sequence/sequence.hpp"

template <class T>
class PriorityQueue
 {
    protected:

    Sequence<T>& A;
    int n;

    virtual void Insert() {
        if(n < A.GetSize()) {
            n++;
        } else {
            /* DO NOTHING */
        }
    }
    virtual void DeleteMax() {
        if(n > 0) {
            n--;
        } else {
            /* DO NOTHING */
        }
    }

    static void Sort(PriorityQueue& pq, Sequence<T>& A) {
        int i;

        for(i = 0; i < A.GetSize(); i++) {
            pq.Insert();
        }

        for(i = 0; i < A.GetSize(); i++) {
            pq.DeleteMax();
        }
    }

    public:

    PriorityQueue (Sequence<T>& A) 
    : A{A}, n{0}
    {
    }
};

template <class T>
class PQSortedArray : public PriorityQueue<T> {

    protected:

    virtual void DeleteMax() {
        int m;
        int i;
        T temp;

        for(m = 0, i = 1; i < this->n; i++) {
            if(this->A.GetAt(i) > this->A.GetAt(m)) {
                m = i;
            } else {
                /* DO NOTHING */
            }
        }

        temp = this->A.GetAt(this->n-1);
        this->A.SetAt(this->n-1, this->A.GetAt(m));
        this->A.SetAt(m, temp);

        PriorityQueue<T>::DeleteMax();
    }
    
    public:
    PQSortedArray(Sequence<T>& A)
    : PriorityQueue<T>(A) {
    }

    static void Sort(Sequence<T>& A) {
        PQSortedArray pq(A);
        PriorityQueue<T>::Sort(pq, A);
    }
};