#include <cstdlib>
#include "../sequence/linked_list_seq.hpp"
#include "set_from_seq.hpp"
using namespace std;

template <class T>
class HashTableSetIter;

template <class T>
class HashTableSet;

template <class T>
class HashTableSetIter {   
    int i;
    LinkedListSeqIter<Pair<T>> j;
    HashTableSet<T>* hashTableSet;
    
    public:
    HashTableSetIter() {
        hashTableSet = NULL;
        i = -1;
    }
    ~HashTableSetIter() {}

    void SetHashTableSet(HashTableSet<T>* hashTableSet) {
        this->hashTableSet = hashTableSet;
    }
    void SetIndex(int i) {
        this->i = i;
    }
    void SetIter(LinkedListSeqIter<Pair<T>> j) {
        this->j = j;
    }

    Pair<T> operator*(void) {
        return *j;
    }
    void Inc(void) {
        j++;
        if(j == hashTableSet->GetArray()[i].End()) {
            for(i = i + 1; i < hashTableSet->GetLength(); i++) {
                if(hashTableSet->GetArray()[i].Begin() != hashTableSet->GetArray()[i].End()) {
                    j = hashTableSet->GetArray()[i].Begin();
                    break;
                }
            }
        }
    }
    void operator++(void) {
        Inc();
    }
    void operator++(int) {
        Inc();
    }
    bool operator==(HashTableSetIter<T> B) {
        return this->hashTableSet == B.hashTableSet && this->i == B.i && this->j == B.j;
    }
    bool operator!=(HashTableSetIter<T> B) {
        return this->hashTableSet != B.hashTableSet || this->i != B.i || this->j != B.j;
    }
};

template <class T>
class HashTableSet : public Set<T> {
    SetFromSeq<T, LinkedListSeq<Pair<T>>>* array;

    int size;

    int lower;
    int upper;
    int length;

    long p = (1u << 31) - 1ul;
    long a = rand() % (p - 1);
    
    HashTableSetIter<T> begin;
    HashTableSetIter<T> end;

    int Hash(int k, int m) {
        int h;
        h = (((a * k) % p) % m);
        return h;
    }

    void Resize(int n) {
        SetFromSeq<T, LinkedListSeq<Pair<T>>>* newArray;
        int h;
        int newLength;

        if (0 == n) {
            delete[] array;
            array = NULL;
            lower = 0;
            upper = 0;
            length = 0;
        } else {
            if(this->lower < n && n < this->upper) {
                /* DO NOTHING */
            } else {
                newLength = n * 2;
                this->upper = newLength;
                this->lower = newLength / 4;
                newArray = new SetFromSeq<T, LinkedListSeq<Pair<T>>>[newLength];
                if(array != NULL) {
                    for(auto i = Begin(); i != End(); i++) {
                        h = Hash((*i).GetKey(), newLength);
                        newArray[h].Insert(*i);
                    }
                    delete[] array;
                } else {
                    /* DO NOTHING */
                }
                this->length = newLength;
                array = newArray;
            }
        }
    }

    int Abs(int a) {
        if (a > 0) return a;
        else return -a;
    }

    public:
    /**
     * @brief Construct a new Array Seq object
     * 
     */
    HashTableSet(void) {
        array = NULL;
        size = 0;
        lower = 0;
        upper = 0;
        length = 0;
    }

    /**
     * @brief given an iterable X, build set from items in X
     * 
     * @param X 
     * @param size 
     */
    virtual void Build(Pair<T> X[], int size) {
        auto x = Begin();
        auto y = End();
        if(x == y) {
            int i;
            for(i = 0; i < size; i++) {
                Insert(X[i]);
            }
        }
    }

    /**
     * @brief return the stored item with key k
     * 
     * @param k 
     */
    virtual Pair<T> Find(int k) {
        int h;
        h = Hash(k, length);
        return array[h].Find(k);
    }

    /**
     * @brief add x to set (replace item with key x.key if one already exists) 
     * 
     * @param x
     */
    virtual void Insert(Pair<T> x) {
        int h;
        this->Resize(size+1);
        size += 1;
        h = Hash(x.GetKey(), length);
        array[h].Insert(x);
    }

    /**
     * @brief remove and return the stored item with key k
     * 
     * @param k 
     */
    virtual void Delete(int k) {
        int h;
        this->Resize(size-1);
        size -= 1;
        h = Hash(k, length);
        array[h].Delete(k);
    }

    /**
     * @brief return the stored item with smallest key
     * 
     */
    virtual Pair<T> FindMin(void) {
        Pair<T> res;
        if(size < 0) return res;

        int minKey;
        auto resIt = End();

        minKey = INT_MAX;
        for(auto i = Begin(); i != End(); i++) {
            if((*i).GetKey() < minKey) {
                resIt = i;
                minKey = (*i).GetKey();
            }
        }

        if(End() != resIt) {
            res = *resIt;
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
        if(size < 0) return res;

        int maxKey;
        auto resIt = End();

        maxKey = INT_MIN;
        for(auto i = Begin(); i != End(); i++) {
            if((*i).GetKey() > maxKey) {
                resIt = i;
                maxKey = (*i).GetKey();
            }
        }

        if(End() != resIt) {
            res = *resIt;
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
        if(size < 0) return res;

        int nextKeyDiff = INT_MAX;
        int diff;
        auto resIt = End();

        for(auto i = Begin(); i != End(); i++) {
            diff = (*i).GetKey() - k;
            if(diff > 0 && diff < nextKeyDiff) {
                resIt = i;
                nextKeyDiff = diff;
            }
        }

        if(End() != resIt) {
            res = *resIt;
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
        if(size < 0) return res;

        int nextKeyAbsDiff = INT_MAX;
        int diff;
        auto resIt = End();

        for(auto i = Begin(); i != End(); i++) {
            diff = (*i).GetKey() - k;
            if(diff < 0 && Abs(diff) < nextKeyAbsDiff) {
                resIt = i;
                nextKeyAbsDiff = Abs(diff);
            }   
        }

        if(End() != resIt) {
            res = *resIt;
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
        for(auto i = Begin(); i != End(); i++) {
            cout << *i <<  " ";
        }
        cout << endl;
    }

    /**
     * @brief Destroy the HashTableSet object
     * 
     */
    virtual ~HashTableSet() {
        if (0 != length) {
            delete[] array;
        }
    };

    /**
     * @brief return the size of the set
     * 
     * @param k 
     */
    virtual int GetSize(void) {
        return array->GetSize();
    }

    /**
     * @brief return the length of the set
     * 
     * @param k 
     */
    virtual int GetLength(void) {
        return length;
    }
    /**
     * @brief Get an iterator on the start of the hash table
     * 
     */
    virtual HashTableSetIter<T> Begin(void) {
        int i;
        begin.SetHashTableSet(this);
        begin.SetIndex(length);
        begin.SetIter(LinkedListSeqIter<Pair<T>>());
        if(size > 0) {
            for(i = 0; i < length; i++) {
                if(array[i].Begin() != array[i].End()) {
                    begin.SetIndex(i);
                    begin.SetIter(array[i].Begin()); 
                    break;
                }
            }
        } 
        return begin;
    }

    /**
     * @brief Returns an iterator referring to the past-the-end 
     * element in the hash table container.
     * 
     */
    virtual HashTableSetIter<T> End(void) {
        end.SetHashTableSet(this);
        end.SetIndex(length);
        end.SetIter(LinkedListSeqIter<Pair<T>>());
        return end;
    }

    SetFromSeq<T, LinkedListSeq<Pair<T>>>* GetArray() {
        return array;
    }
};