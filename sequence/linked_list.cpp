#include <iostream>
using namespace std;

typedef struct node {
    struct node* next;
    int item;
} Node;

class Sequence {
    Node* head;

    public:
    /**
     * @brief Construct a new Sequence object
     * 
     * @param x 
     */
    Sequence() {
        head = NULL; /* head is not a wild pointer now */
    }

    /**
     * @brief given an iterable X, build sequence from items in X
     * 
     * @param X 
     */
    void Build(int X[], int size) {
        Node* newNode;
        Node* currNode;
        int i;

        if(size > 0) {
            newNode = new Node;
            newNode->item = X[0];
            head = newNode;
            currNode = newNode;

            for(i = 1; i < size; i++) {
                newNode = new Node;
                newNode->item = X[i];
                currNode->next = newNode;
                currNode = newNode;
            }
            currNode->next = NULL;
        }
    }

    /**
     * @brief Get the item at i
     * 
     * @param i 
     * @return int 
     */
    int GetAt(int i) {
        Node* currNode = head;
        while(i > 0) {
            currNode = currNode->next;
            i--;
        }
        return currNode->item;
    }

    /**
     * @brief Set the item x at i
     * 
     * @param i 
     * @return int 
     */
    void SetAt(int i, int x) {
        Node* currNode = head;
        while(i > 0) {
            currNode = currNode->next;
            i--;
        }
        currNode->item = x;
    }

    /**
     * @brief Insert Item at the beginning of the array
     * 
     * @param x 
     */
    void InsertFirst(int x) {
        Node* newNode = new Node;
        newNode->next = head;
        newNode->item = x;
        head = newNode;
    }

    /**
     * @brief Delete item at the beginning of the array
     * 
     */
    void DeleteFirst(void) {
        Node* newHead;
        if(head != NULL) {
            newHead = head->next;
            delete head;
            head = newHead;
        }
    }

    /**
     * @brief Insert Item at the end of the array
     * 
     * @param x 
     */
    void InsertLast(int x) {
        Node* currNode = head;
        Node* newNode = new Node;
        newNode->item = x;
        newNode->next = NULL;
        
        if(head == NULL) {
            head = newNode;
        } else {
            while(currNode->next != NULL) {
                currNode = currNode->next;
            }
            currNode->next = newNode;
        }
    }

    /**
     * @brief Delete item at the end of the array
     * 
     */
    void DeleteLast(void) {
        Node* prevNode = head;
        Node* currNode;
        if(head != NULL) {
            if(head->next != NULL) {
                currNode = head->next;
                while(currNode->next != NULL) {
                    prevNode = prevNode->next;
                    currNode = currNode->next;
                }
                delete currNode;
                prevNode->next = NULL;
            } else {
                delete head;
                head = NULL;
            }
        } else {
            /* DO NOTHING */
        }
    }

    /**
     * @brief Insert Item at the i index of the array
     * 
     * @param x 
     */
    void InsertAt(int i, int x) {
        Node* prevNode;
        Node* currNode;
        Node* newNode;
        int pointer;

        newNode = new Node;
        newNode->item = x;

        if(i == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            if(head != NULL && head->next != NULL) {
                prevNode = head;
                currNode = head->next;
                pointer = 0;
                while(currNode->next != NULL && pointer != i-1) {
                    prevNode = prevNode->next;
                    currNode = currNode->next;
                    pointer += 1;
                }
                if(pointer == i-1) {
                    newNode->next = currNode;
                    prevNode->next = newNode;
                } else {
                    /* DO NOTHING */
                }             
            } else {
                /* DO NOTHING */
            }
        }
    }

    /**
     * @brief Delete Item at the i index of the array
     * 
     * @param x 
     */
    void DeleteAt(int i) {
        Node* newHead;
        Node* tobeDeletedNode;
        Node* currNode;
        Node* prevNode;
        int pointer;
        if(i == 0) {
            if(head != NULL) {
                newHead = head->next;
                delete head;
                head = newHead;
            } else {
                /* DO NOTHING */
            }
        } else {
            if(head != NULL && head->next != NULL) {
                prevNode = head;
                currNode = head->next;
                pointer = 0;
                while(currNode->next != NULL && pointer != i-1) {
                    prevNode = prevNode->next;
                    currNode = currNode->next;
                    pointer += 1;
                }
                if(pointer == i-1) {
                    tobeDeletedNode = currNode;
                    prevNode->next = currNode->next;
                    delete tobeDeletedNode;
                } else {
                    /* DO NOTHING */
                }             
            } else {
                /* DO NOTHING */
            }
        }
    }

    /**
     * @brief print the array
     * 
     */
    void Print(void) {
        Node* currNode = head;
        while(currNode != NULL) {
            cout << currNode->item << " ";
            currNode = currNode->next;
        }
        cout << endl;
    }

    /**
     * @brief Destroy the Sequence object
     * 
     */
    ~Sequence() {
        Node* currNode;
        Node* tobeDeletedNode;

        currNode = head;
        while(currNode != NULL) {
            tobeDeletedNode = currNode;
            currNode = tobeDeletedNode->next;
            delete tobeDeletedNode;
        }
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
    
    cout << "testing InsertAt(3, 20):\n";
    A->InsertAt(3, 20);
    A->Print();
    cout << "testing InsertAt(0, 10):\n";
    A->InsertAt(0, 10);
    A->Print();
    cout << "testing InsertAt(9, 9) (no item @ 9):\n";
    A->InsertAt(9, 9);
    A->Print();
    cout << "testing InsertAt(1, 20):\n";
    A->InsertAt(1, 20);
    A->Print();

    cout << "testing DeleteAt(3):\n";
    A->DeleteAt(3);
    A->Print();
    cout << "testing DeleteAt(0):\n";
    A->DeleteAt(0);
    A->Print();
    cout << "testing DeleteAt(7):\n";
    A->DeleteAt(7);
    A->Print();
    cout << "testing DeleteAt(7) (out of range):\n";
    A->DeleteAt(7);
    A->Print();
    

    delete A;
}