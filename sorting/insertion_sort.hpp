#include "../sequence/sequence.hpp"

class InsertionSort {

    public:
    
    template <class T>
    static void Sort(Sequence<T>& A) {
        int i;
        int j;
        T temp;
        for(i = 1; i < A.GetSize(); i++) {
            temp = A.GetAt(i);
            j = i - 1;
            while(j >= 0 && A.GetAt(j) > temp) {
                A.SetAt(j+1, A.GetAt(j));
                j -= 1;
            }
            A.SetAt(j+1, temp);
        }
    }
};