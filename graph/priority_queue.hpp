#pragma once
#include "vertex.hpp"
#include "../sequence/dynamic_array_seq.hpp"
#include "../set/hash_table_set.hpp"

template <class T>
class PriorityQueue
 {
    DynamicArraySeq<Vertex<T>*> Q;

    void Swap(int x, int y) {
        Vertex<T>* temp;

        Q.GetAt(x)->SetIdx(y);
        Q.GetAt(y)->SetIdx(x);
        
        temp = Q.GetAt(x);
        Q.SetAt(x, Q.GetAt(y));
        Q.SetAt(y, temp);
    }

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
        if(l < Q.GetSize()) {
            res = l; 
        } else {
            res = i;
        }
        return res;
    }

    int RightOfIdx(int i) {
        int r = 2 * i + 2;
        int res;
        if(r < Q.GetSize()) {
            res = r; 
        } else {
            res = i;
        }
        return res;
    }
    
    void MinHeapifyUp(int nodeIdx) {
        int parentIdx = ParentOfIdx(nodeIdx);
        while(Q.GetAt(nodeIdx)->GetShortestDistance() < Q.GetAt(parentIdx)->GetShortestDistance()) {
            Swap(parentIdx, nodeIdx);
            nodeIdx = parentIdx;
            parentIdx = ParentOfIdx(nodeIdx);
        }
    }

    void MinHeapifyDown(int nodeIdx) {
        int leftIdx = LeftOfIdx(nodeIdx);
        int rightIdx = RightOfIdx(nodeIdx);

        while(
            Q.GetAt(nodeIdx)->GetShortestDistance() > Q.GetAt(leftIdx)->GetShortestDistance() ||
            Q.GetAt(nodeIdx)->GetShortestDistance() > Q.GetAt(rightIdx)->GetShortestDistance()
            ) {
            if(Q.GetAt(rightIdx)->GetShortestDistance() > Q.GetAt(leftIdx)->GetShortestDistance()) {
                Swap(leftIdx, nodeIdx);
                nodeIdx = leftIdx;
            } else {
                Swap(rightIdx, nodeIdx);
                nodeIdx = rightIdx;
            }
            leftIdx = LeftOfIdx(nodeIdx);
            rightIdx = RightOfIdx(nodeIdx);
        }

    }

    public:
    void Insert(Vertex<T>* x) {
        Q.InsertLast(x);
        x->SetIdx(Q.GetSize()-1);
        MinHeapifyUp(Q.GetSize()-1);
    }

    Vertex<T>* DeleteMin() {
        Vertex<T>* min = Q.GetAt(0);
        Swap(Q.GetSize()-1, 0);
        Q.DeleteLast();
        if(Q.GetSize() > 0) MinHeapifyDown(0);
        return min;
    }

    void DecreaseKey(Vertex<T>* v, int k) {
        MinHeapifyUp(v->GetIdx());
    }

    PriorityQueue (void) 
    {
    }
};