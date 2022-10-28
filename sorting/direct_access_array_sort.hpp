#include "../sequence/sequence.hpp"

class DirectAccessArraySort {

    public:
    
    template <class T>
    static void Sort(Sequence<T>& A) {
        int i, k;
        T* daa;
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

            daa = new T[u];

            for(i = 0; i < A.GetSize(); i++) {
                A_i = A.GetAt(i);
                A_i_key = A_i.GetKey();
                daa[A_i_key] = A_i;
            }

            for(i = 0, k = 0; i < u; i++) {
                if(-1 != daa[i].GetKey()) {
                    A.SetAt(k, daa[i]);
                    k++;
                }
            }

            delete[] daa;
        }
    }
};