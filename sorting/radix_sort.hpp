#include <climits>
#include "../sequence/sequence.hpp"
#include "../sequence/dynamic_array_seq.hpp"
#include "../set/set.hpp"
#include "counting_sort.hpp"

template <class T>
class RadixSortObj {
    T item;
    int key;
    DynamicArraySeq<int> digits;

    public:

    RadixSortObj() {}

    RadixSortObj(T item, DynamicArraySeq<int> digits)
    {
        this->item = item;
        this->digits = digits;
    }

    void SetKey(int key) {
        this->key = key;
    }

    int GetKey(void) {
        return key;
    }

    void SetItem(T item) {
        this->item = item;
    }

    T GetItem(void) {
        return this->item;
    }

    int GetDigitAt(int k) {
        return digits.GetAt(k);
    }

    void InsertDigit(int k) {
        digits.InsertLast(k);
    }

    friend ostream & operator << (ostream &out, const RadixSortObj &c) {
        out << c.item << endl;
        return out;
    }
};

class RadixSort {

    template <class T>
    static int FindMaxKey(Sequence<T>& A) {
        T A_i;
        int A_i_key;
        int u = -1;
        int i;

        if (A.GetSize() > 0) {
            u = A.GetAt(0).GetKey();
            for(i = 1; i < A.GetSize(); i++) {
                A_i = A.GetAt(i);
                A_i_key = A_i.GetKey();
                u = A_i_key > u ? A_i_key : u;
            }
        } else {
            /* DO NOTHING */
        }
        return u;
    }

    template <class T>
    static void CopyIntoDaa(DynamicArraySeq<RadixSortObj<T>>& daa, Sequence<T>& A) {
        int i;
        RadixSortObj<T> daa_i;

        for(i = 0; i < A.GetSize(); i++) {
            daa_i.SetItem(A.GetAt(i));
            daa.InsertLast(daa_i);
        }
    }

    template <class T>
    static void FillInDigits(DynamicArraySeq<RadixSortObj<T>>& daa, int c) {
        int j, k;
        int daa_i_key;
        RadixSortObj<T> daa_i;

        for(j = 0; j < daa.GetSize(); j++) {
            daa_i = daa.GetAt(j);
            daa_i_key = daa_i.GetItem().GetKey();

            for(k = 0; k < c; k++) {
                daa_i.InsertDigit(daa_i_key % daa.GetSize());
                daa_i_key /= daa.GetSize();                
            }
            daa.SetAt(j, daa_i);
        }
    }

    
    template <class T>
    static void RunCountingSorts(DynamicArraySeq<RadixSortObj<T>>& daa, int c) {
        RadixSortObj<T> daa_i;
        T daa_i_key;
        int i, j;

        for(i = 0; i < c; i++) {
            for(j = 0; j < daa.GetSize(); j++) {
                daa_i = daa.GetAt(j);
                daa_i.SetKey(daa_i.GetDigitAt(i));
                daa.SetAt(j, daa_i);
            }
            CountingSort::Sort(daa);
        }
    }

    public:
    
    template <class T>
    static void Sort(Sequence<T>& A) {
        int c;
        int j;
        T A_i;
        int u;
        DynamicArraySeq<RadixSortObj<T>> daa;
        RadixSortObj<T> daa_i;

        if (A.GetSize() > 0) {
            u = 1 + FindMaxKey(A);
            c = 1 + (u / A.GetSize());
            
            CopyIntoDaa(daa, A);

            FillInDigits(daa, c);

            RunCountingSorts(daa, c);

            for(j = 0; j < A.GetSize(); j++) {
                A.SetAt(j, daa.GetAt(j).GetItem());
            }
        } else {
            /* DO NOTHING */
        }
    }
};