#include "../sequence/sequence.hpp"

class SelectionSort {

    public:
    
    template <class T>
    static void Sort(Sequence<T>& A) {
        int i;
        int m;
        int j;
        T temp;

        for(i = A.GetSize() - 1; i > 0; i--) {
            m = i;
            for(j = i - 1; j >= 0; j--) {
                if(A.GetAt(m) < A.GetAt(j)) m = j;
            }
            temp = A.GetAt(i);
            A.SetAt(i, A.GetAt(m));
            A.SetAt(m, temp);
        }
    }
};