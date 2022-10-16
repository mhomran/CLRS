class InsertionSort {

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
        int j;
        T temp;
        for(i = 1; i < size; i++) {
            temp = A[i];
            j = i - 1;
            while(j >= 0 && A[j] > temp) {
                A[j+1] = A[j];
                j -= 1;
            }
            A[j+1] = temp;
        }
    }
};