#include <iostream>
using namespace std;

class Sequence {
    int* array;
    int size;
    public:

    /**
     * @brief given an iterable X, build sequence from items in X
     * 
     * @param X 
     */
    void Build(int X[], int size) {
        int i;
        array = new int[size];
        this->size = size;
        for(i = 0; i < size; i++) {
            array[i] = X[i];
        }
    }

    /**
     * @brief Get the item at i
     * 
     * @param i 
     * @return int 
     */
    int GetAt(int i) {
        return array[i];
    }

    /**
     * @brief Set the item x at i
     * 
     * @param i 
     * @return int 
     */
    void SetAt(int i, int x) {
        array[i] = x;
    }

    /**
     * @brief Insert Item at the beginning of the array
     * 
     * @param x 
     */
    void InsertFirst(int x) {
        int* newArray;
        int i;

        size += 1; // update size

        newArray = new int[size];
        newArray[0] = x;
        for(i = 1; i < size; i++) {
            newArray[i] = array[i-1];
        }

        delete[] array;
        array = newArray; // update the new array
    }

    /**
     * @brief Delete item at the beginning of the array
     * 
     */
    void DeleteFirst(void) {
        int* newArray;
        int i;

        size -= 1; // update size

        newArray = new int[size];
        for(i = 1; i < size; i++) {
            newArray[i-1] = array[i];
        }

        delete[] array;
        array = newArray; // update the new array
    }

    /**
     * @brief Insert Item at the end of the array
     * 
     * @param x 
     */
    void InsertLast(int x) {
        int* newArray;
        int i;

        size += 1; // update size

        newArray = new int[size];
        for(i = 0; i < size-1; i++) {
            newArray[i] = array[i];
        }
        newArray[size-1] = x;

        delete[] array;
        array = newArray; // update the new array
    }

    /**
     * @brief Delete item at the end of the array
     * 
     */
    void DeleteLast(void) {
        int* newArray;
        int i;

        size -= 1; // update size

        newArray = new int[size];
        for(i = 0; i < size-1; i++) {
            newArray[i] = array[i];
        }

        delete[] array;
        array = newArray; // update the new array
    }

    /**
     * @brief Insert Item at the i index of the array
     * 
     * @param x 
     */
    void InsertAt(int i, int x) {
        int* newArray;
        int j;

        size += 1; // update size

        newArray = new int[size];
        for(j = 0; j < i; j++) {
            newArray[j] = array[j];
        }
        newArray[i] = x;
        for(j = i+1; j < size; j++) {
            newArray[j] = array[j-1];
        }

        delete[] array;
        array = newArray; // update the new array
    }

    /**
     * @brief Delete Item at the i index of the array
     * 
     * @param x 
     */
    void DeleteAt(int i) {
        int* newArray;
        int j;

        size -= 1; // update size

        newArray = new int[size];
        for(j = 0; j < i; j++) {
            newArray[j] = array[j];
        }
        for(j = i+1; j < size; j++) {
            newArray[j-1] = array[j];
        }

        delete[] array;
        array = newArray; // update the new array
    }

    /**
     * @brief print the array
     * 
     */
    void Print(void) {
        int i;
        for(i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    /**
     * @brief Destroy the Sequence object
     * 
     */
    ~Sequence() {
        delete[] array;
    }
};

int main() {
    Sequence* A = new Sequence();
    int i;
    int X[7];
    for(i = 0; i < 7; i++) {
        X[i] = i + 1;
    }
    
    cout << "Testing Build(X, 7):\n";
    A->Build(X, 7);
    A->Print();

    cout << "Testing SetAt(5, 50):\n";
    A->SetAt(5, 50);
    A->Print();
    
    cout << "Testing GetAt(5):\n";
    cout << A->GetAt(5) << endl;

    cout << "testing InsertFirst and Print:\n";
    A->InsertFirst(20);
    A->Print();

    cout << "testing DeleteFirst:\n";
    A->DeleteFirst();
    A->Print();

    cout << "testing InsertLast:\n";
    A->InsertLast(50);
    A->Print();
    
    cout << "testing DeleteLast:\n";
    A->DeleteLast();
    A->Print();
    
    cout << "testing InsertAt:\n";
    A->InsertAt(3, 20);
    A->Print();

    cout << "testing DeleteAt:\n";
    A->DeleteAt(3);
    A->Print();

    delete A;
}