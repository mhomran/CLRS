#pragma once
#include "../sequence/sequence.hpp"

template <class T>
class PriorityQueue
 {
    protected:

    Sequence<T>& A;
    int n;

    void Swap(int x, int y) {
        T temp;

        temp = this->A.GetAt(x);
        this->A.SetAt(x, this->A.GetAt(y));
        this->A.SetAt(y, temp);
    }

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
class PQArray : public PriorityQueue<T> {

    protected:


    virtual void DeleteMax() {
        int m;
        int i;

        for(m = 0, i = 1; i < this->n; i++) {
            if(this->A.GetAt(i) > this->A.GetAt(m)) {
                m = i;
            } else {
                /* DO NOTHING */
            }
        }

        PriorityQueue<T>::Swap(this->n-1, m);

        PriorityQueue<T>::DeleteMax();
    }
    
    public:
    PQArray(Sequence<T>& A)
    : PriorityQueue<T>(A) {
    }

    static void Sort(Sequence<T>& A) {
        PQArray pq(A);
        PriorityQueue<T>::Sort(pq, A);
    }
};

template <class T>
class PQSortedArray : public PriorityQueue<T> {

    protected:

    void Insert() {
        T tobeInserted = this->A.GetAt(this->n);
        int i;
        i = this->n - 1;
        while(i >= 0 && this->A.GetAt(i) > tobeInserted) {
            this->A.SetAt(i+1, this->A.GetAt(i));
            i--;
        }
        this->A.SetAt(i+1, tobeInserted);

        PriorityQueue<T>::Insert();
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

template <class T>
class PQHeap : public PriorityQueue<T> {
    private:
    int ParentOfIdx(int i) {
        int p = (i - 1) / 2;
        int res;
        if(p >= 0) {
            res = p; 
        } else {
            res = i;
        }
        return res;
    }
    int LeftOfIdx(int i) {
        int l = 2 * i + 1;
        int res;
        if(l < this->n) {
            res = l; 
        } else {
            res = i;
        }
        return res;
    }
    int RightOfIdx(int i) {
        int r = 2 * i + 2;
        int res;
        if(r < this->n) {
            res = r; 
        } else {
            res = i;
        }
        return res;
    }
    
    void MaxHeapifyUp(int nodeIdx) {
        int parentIdx = ParentOfIdx(nodeIdx);
        while(this->A.GetAt(nodeIdx) > this->A.GetAt(parentIdx)) {
            PriorityQueue<T>::Swap(parentIdx, nodeIdx);
            nodeIdx = parentIdx;
            parentIdx = ParentOfIdx(nodeIdx);
        }
    }

    void MaxHeapifyDown(int nodeIdx) {
        int leftIdx = LeftOfIdx(nodeIdx);
        int rightIdx = RightOfIdx(nodeIdx);

        while(
            this->A.GetAt(nodeIdx) < this->A.GetAt(leftIdx) ||
            this->A.GetAt(nodeIdx) < this->A.GetAt(rightIdx)
            ) {
            if(this->A.GetAt(rightIdx) < this->A.GetAt(leftIdx)) {
                PriorityQueue<T>::Swap(leftIdx, nodeIdx);
                nodeIdx = leftIdx;
            } else {
                PriorityQueue<T>::Swap(rightIdx, nodeIdx);
                nodeIdx = rightIdx;
            }
            leftIdx = LeftOfIdx(nodeIdx);
            rightIdx = RightOfIdx(nodeIdx);
        }

    }

    void Swap(int x, int y) {
        T z = x;
        x = y;
        y = z;
    }

    protected:

    void Insert() {
        PriorityQueue<T>::Insert();
        MaxHeapifyUp(this->n-1);
    }

    void DeleteMax() {
        PriorityQueue<T>::DeleteMax();
        PriorityQueue<T>::Swap(this->n, 0);
        MaxHeapifyDown(0);
    }

    public:

    PQHeap(Sequence<T>& A)
    : PriorityQueue<T>(A) {
    }

    static void Sort(Sequence<T>& A) {
        PQHeap pq(A);
        PriorityQueue<T>::Sort(pq, A);
    }
};