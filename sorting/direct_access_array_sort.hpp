#include "../sequence/sequence.hpp"

class DirectAccessArraySort {

    public:
    
    static void Sort(Sequence<int>& A) {
        int i, k;
        int* daa;
        int u;
        int A_i;
        
        if(A.GetSize() > 0) {
            u = A.GetAt(0);
            for(i = 1; i < A.GetSize(); i++) {
                A_i = A.GetAt(i);
                u = A_i > u ? A_i : u;
            }
            u += 1;

            daa = new int[u];
            for(i = 0; i < u; i++) {
                daa[i] = -1;
            }

            for(i = 0; i < A.GetSize(); i++) {
                A_i = A.GetAt(i);
                daa[A_i] = A_i;
            }

            for(i = 0, k = 0; i < u; i++) {
                if(-1 != daa[i]) {
                    A.SetAt(k, daa[i]);
                    k++;
                }
            }

            delete[] daa;
        }
    }
};