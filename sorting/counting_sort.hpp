#include "../sequence/sequence.hpp"
#include "../sequence/linked_list_seq.hpp"

class CountingSort {

    public:

    template <class T>
    static void Sort(Sequence<T>& A) {
        int i, k;
        LinkedListSeq<T>* daa;
        int u;
        T A_i;
        int A_i_key;
        
        if(A.GetSize() > 0) {
            u = A.GetAt(0).GetKey();
            for(i = 1; i < A.GetSize(); i++) {
                A_i_key = A.GetAt(i).GetKey();
                u = A_i_key > u ? A_i_key : u;
            }
            u += 1;

            daa = new LinkedListSeq<T>[u];

            for(i = 0; i < A.GetSize(); i++) {
                A_i = A.GetAt(i);
                A_i_key = A_i.GetKey();
                daa[A_i_key].InsertLast(A_i);
            }

            for(i = 0, k = 0; i < u; i++) {
                for(auto iter = daa[i].Begin(); iter != daa[i].End(); iter++) {
                    A.SetAt(k, *iter);
                    k++;
                }
            }

            delete[] daa;
        }
    }
};