#include <climits>
#include "set.hpp"

template <class T>
class DirectAccessArraySet {
    Pair<T>* array;
    int u;

    int Abs(int a) {
        if (a > 0) return a;
        else return -a;
    }

    public:
    
    DirectAccessArraySet(int u) {
        this->array = new Pair<T>[u];
        this->u = u;
    }

    /**
     * @brief given an iterable X, build set from items in X
     * 
     * @param X 
     * @param size 
     */
    virtual void Build(Pair<T> X[], int size) {
        int i;
        for(i = 0; i < size; i++) {
            if(0 < X[i].GetKey() && X[i].GetKey() < u) {
                array[X[i].GetKey()] = X[i];
            }
        }
    }

    /**
     * @brief return the stored item with key k
     * 
     * @param k 
     */
    virtual Pair<T> Find(int k) {
        Pair<T> res;
        
        if(k < u) {
            res = array[k];
        } else {
            /* DO NOTHING */
        }

        return res;
    }

    /**
     * @brief add x to set (replace item with key x.key if one already exists) 
     * 
     * @param x
     */
    virtual void Insert(Pair<T> x) {
        
        if(x.GetKey() < u) {
            array[x.GetKey()] = x;
        } else {
            /* DO NOTHING */
        }
    }

    /**
     * @brief remove and return the stored item with key k
     * 
     * @param k 
     */
    virtual void Delete(int k) {
        if(k < u) {
            array[k].SetKey(-1);
        } else {
            /* DO NOTHING */
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
        for(i = 0; i < u; i++) {
            if(-1 != array[i].GetKey() && array[i].GetKey() < minKey) {
                resI = i;
                minKey = array[i].GetKey();
            }
        }

        if(-1 != resI) {
            res = array[resI];
        } else {
            /* DO NOTHING */
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
        for(i = 0; i < u; i++) {
            if(-1 != array[i].GetKey() && array[i].GetKey() > maxKey) {
                resI = i;
                maxKey = array[i].GetKey();
            }
        }

        if(-1 != resI) {
            res = array[resI];
        } else {
            /* DO NOTHING */
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
        for(i = 0; i < u; i++) {
            if(-1 != array[i].GetKey()) {
                diff = array[i].GetKey() - k;
                if(diff > 0 && diff < nextKeyDiff) {
                    resI = i;
                    nextKeyDiff = diff;
                }
            }
        }

        if(-1 != resI) {
            res = array[resI];
        } else {
            /* DO NOTHING */
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
        for(i = 0; i < u; i++) {
            if(-1 != array[i].GetKey()) {
                diff = array[i].GetKey() - k;
                if(diff < 0 && Abs(diff) < nextKeyAbsDiff) {
                    resI = i;
                    nextKeyAbsDiff = Abs(diff);
                }
            }
        }

        if(-1 != resI) {
            res = array[resI];
        } else {
            /* DO NOTHING */
        }

        return res;
    }

    /**
     * @brief Print the Set
     * 
     */
    virtual void Print(void) {
        int i;
        for(i = 0; i < u; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    /**
     * @brief Destroy the Set object
     * 
     */
    virtual ~DirectAccessArraySet() {
        delete[] array;
    };
};