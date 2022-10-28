#include "../sequence/sequence.hpp"
#include "../sequence/linked_list_seq.hpp"
#include "../sequence/dynamic_array_seq.hpp"

class CountingSort {

    public:
    
    static void Sort(Sequence<int>& A) {
        int i, k;
        DynamicArraySeq<int>* daa;
        int u;
        int A_i;
        
        if(A.GetSize() > 1) {
            u = A.GetAt(0);
            for(i = 1; i < A.GetSize(); i++) {
                A_i = A.GetAt(i);
                u = A_i > u ? A_i : u;
            }
            u += 1;

            daa = new DynamicArraySeq<int>[u];

            for(i = 0; i < A.GetSize(); i++) {
                A_i = A.GetAt(i);
                daa[A_i].InsertLast(A_i);
            }

            for(i = 0, k = 0; i < u; i++) {
                for(auto iter = daa[i].Begin(); iter != daa[i].End(); iter++) {
                    A.SetAt(k, *iter);
                    k++;
                }
            }

            delete[] daa;
        } else {
            /* DO NOTHING */
        }
    }
};