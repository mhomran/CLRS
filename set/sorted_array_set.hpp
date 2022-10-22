#include "set.hpp"
#include "../sequence/array_seq.hpp"
#include "../sorting/merge_sort.hpp"

template <class T>
class SortedArraySet {
    ArraySeq<Pair<T>> array;
    
    /**
     * @brief Binary search through the array
     * 
     * @param k 
     * @return int 
     */
    int BinarySearch(int k) {
        int i, j, p;

        i = 0;
        j = array.GetSize()-1;
        while(j >= i) {
            p = (i + j) / 2;
            if(array.GetAt(p).GetKey() == k) {
                break;
            } else if(array.GetAt(p).GetKey() > k) {
                j = p - 1;
            } else {
                i = p + 1;
            }
        }

        return p;
    }

    public:
    /**
     * @brief given an iterable X, build set from items in X
     * 
     * @param X 
     * @param size 
     */
    virtual void Build(Pair<T> X[], int size) {
        array.Build(X, size);
        MergeSort::Sort(array, 0, array.GetSize()-1);
    }

    /**
     * @brief return the stored item with key k
     * 
     * @param k 
     */
    virtual Pair<T> Find(int k) {
        Pair<T> res;
        int i;
        res.SetKey(-1);
        i = BinarySearch(k);
        if(array.GetAt(i).GetKey() == k) {
            res = array.GetAt(i);
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
        i = BinarySearch(x.GetKey());
        if(array.GetAt(i).GetKey() == x.GetKey()) {
            array.SetAt(i, x);
        } else if (array.GetAt(i).GetKey() < x.GetKey()) {
            array.InsertAt(i+1, x);
        } else {
            array.InsertAt(i, x);
        }
    }

    /**
     * @brief remove and return the stored item with key k
     * 
     * @param k 
     */
    virtual void Delete(int k) {
        int i;
        i = BinarySearch(k);
        if(array.GetAt(i).GetKey() == k) {
            array.DeleteAt(i);
        } 
    }

    /**
     * @brief return the stored item with smallest key
     * 
     */
    virtual Pair<T> FindMin(void) {
        Pair<T> res;
        res.SetKey(-1);
        if(array.GetSize() > 0) {
            res = array.GetAt(0);
        }
        return res;
    }

    /**
     * @brief return the stored item with largest key
     * 
     */
    virtual Pair<T> FindMax(void) {
        Pair<T> res;
        res.SetKey(-1);
        if(array.GetSize() > 0) {
            res = array.GetAt(array.GetSize()-1);
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
        res.SetKey(-1);
        i = BinarySearch(k);
        if(array.GetAt(i).GetKey() <= k) {
            if(i + 1 < array.GetSize()) {
                res = array.GetAt(i+1);
            }
        } else {
            res = array.GetAt(i);
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
        res.SetKey(-1);
        i = BinarySearch(k);
        if(array.GetAt(i).GetKey() >= k) {
            if(i - 1 < array.GetSize()) {
                res = array.GetAt(i - 1);
            }
        } else {
            res = array.GetAt(i);
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
     * @brief Destroy the Set object
     * 
     */
    virtual ~SortedArraySet() {};
};