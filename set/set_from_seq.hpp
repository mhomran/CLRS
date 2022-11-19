#pragma once
#include <climits>
#include "set.hpp"
#include "../sequence/array_seq.hpp"
#include "../sorting/merge_sort.hpp"

template <class T, class S>
class SetFromSeq {
    S array;

    int Abs(int a) {
        if (a > 0) return a;
        else return -a;
    }

    int LinearSearch(int k) {
        int res;
        int i;

        res = -1;

        for(i = 0; i < array.GetSize(); i++) {
            if(array.GetAt(i).GetKey() == k) {
                res = i;
                break;
            }
        }
        return res;
    }

    public:
    /**
     * @brief Destroy the Set object
     * 
     */
    virtual ~SetFromSeq() {};

    /**
     * @brief given an iterable X, build set from items in X
     * 
     * @param X 
     * @param size 
     */
    virtual void Build(Pair<T> X[], int size) {
        array.Build(X, size);
    }

    /**
     * @brief return the stored item with key k
     * 
     * @param k 
     */
    virtual Pair<T> Find(int k) {
        Pair<T> res;
        int i;
        
        i = LinearSearch(k);
        if(-1 != i) {
            res = array.GetAt(i);
        } else {
            res.SetKey(-1);
        }
        return res;
    }

    /**
     * @brief add x to set (replace item with key x.key if one already exists) 
     * 
     * @param x
     */
    virtual void Insert(Pair<T> x) {
        int i;

        i = LinearSearch(x.GetKey());
        if (-1 != i) {
            array.SetAt(i, x);
        } else {
            array.InsertLast(x);
        }
    }

    /**
     * @brief remove and return the stored item with key k
     * 
     * @param k 
     */
    virtual void Delete(int k) {
        int i;
        i = LinearSearch(k);
        if(-1 != i) {
            array.DeleteAt(i);
        } 
    }

    /**
     * @brief return the stored item with smallest key
     * 
     */
    virtual Pair<T> FindMin(void) {
        Pair<T> res;
        int resI;
        int i;
        int minKey;

        resI = -1;
        minKey = INT_MAX;
        for(i = 0; i < array.GetSize(); i++) {
            if(array.GetAt(i).GetKey() < minKey) {
                resI = i;
                minKey = array.GetAt(i).GetKey();
            }
        }

        if(-1 != resI) {
            res = array.GetAt(resI);
        } else {
            res.SetKey(-1);
        }
        return res;
    }

    /**
     * @brief return the stored item with largest key
     * 
     */
    virtual Pair<T> FindMax(void) {
        Pair<T> res;
        int resI;
        int i;
        int maxKey;

        resI = -1;
        maxKey = INT_MIN;
        for(i = 0; i < array.GetSize(); i++) {
            if(array.GetAt(i).GetKey() > maxKey) {
                resI = i;
                maxKey = array.GetAt(i).GetKey();
            }
        }

        if(-1 != resI) {
            res = array.GetAt(resI);
        } else {
            res.SetKey(-1);
        }
        return res;
    }

    /**
     * @brief return the stored item with smallest key larger than k
     * 
     * @param k 
     */
    virtual Pair<T> FindNext(int k) {
        Pair<T> res;
        int i;
        int nextKeyDiff = INT_MAX;
        int diff;
        int resI;

        resI = -1;
        for(i = 0; i < array.GetSize(); i++) {
            diff = array.GetAt(i).GetKey() - k;
            if(diff > 0 && diff < nextKeyDiff) {
                resI = i;
                nextKeyDiff = diff;
            }
        }

        if(-1 != resI) {
            res = array.GetAt(resI);
        } else {
            res.SetKey(-1);
        }

        return res;
    }

    /**
     * @brief return the stored item with largest key smaller than k
     * 
     * @param k 
     */
    virtual Pair<T> FindPrev(int k) {
        Pair<T> res;
        int i;
        int nextKeyAbsDiff = INT_MAX;
        int diff;
        int resI;

        resI = -1;
        for(i = 0; i < array.GetSize(); i++) {
            diff = array.GetAt(i).GetKey() - k;
            if(diff < 0 && Abs(diff) < nextKeyAbsDiff) {
                resI = i;
                nextKeyAbsDiff = Abs(diff);
            }
        }

        if(-1 != resI) {
            res = array.GetAt(resI);
        } else {
            res.SetKey(-1);
        }

        return res;
    }

    /**
     * @brief Print the Set
     * 
     */
    virtual void Print(void) {
        array.Print();
    }

    /**
     * @brief return the size of the set
     * 
     * @param k 
     */
    virtual int GetSize(void) {
        return array.GetSize();
    }

    /**
     * @brief Get an iterator on the start of the sequence
     * 
     */
    auto Begin(void) {
        return array.Begin();        
    }

    /**
     * @brief Returns an iterator referring to the past-the-end 
     * element in the sequence container.
     * 
     */
    auto End(void) {
        return array.End();        
    }
};