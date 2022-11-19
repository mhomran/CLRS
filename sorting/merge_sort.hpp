#pragma once

#include "../sequence/sequence.hpp"

class MergeSort {

    template <class T>
    static void Swap(T* A, T* B) {
        T temp;
        temp = *A;
        *A = *B;
        *B = temp;
    }

    template <class T>
    static void Merge(Sequence<T>& A, int a, int b) {
        int c;
        T* L; int L_size;
        T* R; int R_size;
        int i;
        int x, y;

        c = (a + b) / 2;

        L_size = c - a + 1; L = new T[L_size];
        R_size = b - c; R = new T[R_size];

        for(i = a; i <= c; i++) {
            L[i-a] = A.GetAt(i);
        }
        for(i = c+1; i <= b; i++) {
            R[i-c-1] = A.GetAt(i);
        }

        x = 0;
        y = 0;
        for(i = a; i <= b; i++) {
            if(x >= L_size){
                A.SetAt(i, R[y]);
                y++;
            } else if (y >= R_size) {
                A.SetAt(i, L[x]);
                x++;
            } else if (L[x] < R[y]) {
                A.SetAt(i, L[x]);
                x++;
            } else {
                A.SetAt(i, R[y]);
                y++;
            }
        }

        delete[] L;
        delete[] R;
    }
    public:
    
    template <class T>
    static void Sort(Sequence<T>& A, int a, int b) {
        int c;
        if (a < b) {
            c = (a + b) / 2;
            Sort(A, a, c);
            Sort(A, c+1, b);
            Merge(A, a, b);
        } else {
            /* DO NOTHING */
        }
    }
};