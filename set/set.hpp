#include <iostream>
using namespace std;
 
template <class T>
class Pair {
    int key;
    T item;
    public:
    Pair() {
        key = -1;
    }

    Pair(const Pair& s)
    {
        key = s.key;
        item = s.item;
    }

    friend ostream & operator << (ostream &out, const Pair &c) {
        out << c.key << "," << c.item;
        return out;
    }

    int operator>(Pair<T>R) {
        return key > R.key;
    }

    int operator<(Pair<T>R) {
        return key < R.key;
    }

    int operator>=(Pair<T>R) {
        return key >= R.key;
    }

    int operator<=(Pair<T>R) {
        return key <= R.key;
    }

    int operator==(Pair<T>R) {
        return key == R.key;
    }

    int operator!=(Pair<T>R) {
        return key != R.key;
    }

    int GetKey(void) {
        return key;
    }
    void SetKey(int key) {
        this->key = key;
    }
    T GetItem(void) {
        return item;
    }
    void SetItem(T item) {
        this->item = item;
    }
};

template <class T>
class Set {
    public:
    /**
     * @brief given an iterable X, build set from items in X
     * 
     * @param X 
     * @param size 
     */
    virtual void Build(Pair<T> X[], int size) = 0;

    /**
     * @brief return the stored item with key k
     * 
     * @param k 
     */
    virtual Pair<T> Find(int k) = 0;

    /**
     * @brief add x to set (replace item with key x.key if one already exists) 
     * 
     * @param x
     */
    virtual void Insert(Pair<T> x) = 0;

    /**
     * @brief remove and return the stored item with key k
     * 
     * @param k 
     */
    virtual void Delete(int k) = 0;

    /**
     * @brief return the stored item with smallest key
     * 
     */
    virtual Pair<T> FindMin(void) = 0;

    /**
     * @brief return the stored item with largest key
     * 
     */
    virtual Pair<T> FindMax(void) = 0;

    /**
     * @brief return the stored item with smallest key larger than k
     * 
     * @param k 
     */
    virtual Pair<T> FindNext(int k) = 0;

    /**
     * @brief return the stored item with largest key smaller than k
     * 
     * @param k 
     */
    virtual Pair<T> FindPrev(int k) = 0;

    /**
     * @brief return the size of the set
     * 
     * @param k 
     */
    virtual int GetSize(void) = 0;

    /**
     * @brief Print the Set
     * 
     */
    virtual void Print(void) = 0;

    /**
     * @brief Destroy the Set object
     * 
     */
    virtual ~Set() {};
};