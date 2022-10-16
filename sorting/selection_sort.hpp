class SelectionSort {

    template <class T>
    static void Swap(T* A, T* B) {
        T temp;
        temp = *A;
        *A = *B;
        *B = temp;
    }
    public:
    
    template <class T>
    static void Sort(T A[], int size) {
        int i;
        int m;
        int j;
        for(i = size - 1; i > 0; i--) {
            m = i;
            for(j = i - 1; j >= 0; j--) {
                if(A[m] < A[j]) m = j;
            }
            Swap(&A[i], &A[m]);
        }
    }
};