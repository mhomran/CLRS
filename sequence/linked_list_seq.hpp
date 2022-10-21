#include <iostream>
#include <cstddef>
#include "sequence.hpp"
using namespace std;

template <class T>
struct Node {
    Node<T>* next;
    T item;
};

template <class T> 
class LinkedListSeqIter {
    
    Node<T>* curr;

    public: 

    public:
    LinkedListSeqIter() {}
    ~LinkedListSeqIter() {}

    void SetCurr(Node<T>* curr) {
        this->curr = curr;
    }

    T operator*(void) {
        return curr->item;
    }
    void operator++(void) {
        curr = curr->next;
    }
    void operator++(int) {
        curr = curr->next;
    }
    bool operator==(LinkedListSeqIter<T> B) {
        return this->curr == B.curr;
    }
    bool operator!=(LinkedListSeqIter<T> B) {
        return this->curr != B.curr;
    }
};



template <class T> 
class LinkedListSeq : public Sequence<T> {
    Node<T>* head;
    int size;

    LinkedListSeqIter<T> begin;
    LinkedListSeqIter<T> end;

    public:
    
    /**
     * @brief Construct a new Array Seq object
     * 
     */
    LinkedListSeq(void) {
        head = NULL; /* head is not a wild pointer now */
        size = 0;
    }

    /**
     * @brief Destroy the Array Seq object
     * 
     */
    ~LinkedListSeq(void) {
        Node<T>* currNode;
        Node<T>* tobeDeletedNode;

        currNode = head;
        while(currNode != NULL) {
            tobeDeletedNode = currNode;
            currNode = tobeDeletedNode->next;
            delete tobeDeletedNode;
        }
    }

    /**
     * @brief given an iterable X, build sequence from items in X
     * 
     * @param X 
     */
    virtual void Build(T X[], int size) {
        Node<T>* newNode;
        Node<T>* currNode;
        int i;

        if(size > 0) {
            newNode = new Node<T>;
            newNode->item = X[0];
            head = newNode;
            currNode = newNode;

            for(i = 1; i < size; i++) {
                newNode = new Node<T>;
                newNode->item = X[i];
                currNode->next = newNode;
                currNode = newNode;
            }
            currNode->next = NULL;

            this->size = size;
        }
    }

    /**
     * @brief Get the item at i
     * 
     * @param i 
     * @return T 
     */
    virtual T GetAt(int i){
        Node<T>* currNode = head;
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
    virtual void SetAt(int i, T x) {
        Node<T>* currNode = head;
        while(i > 0) {
            currNode = currNode->next;
            i--;
        }
        currNode->item = x;
    }

    /**
     * @brief Insert Item at the beginning of the sequence
     * 
     * @param x 
     */
    virtual void InsertFirst(T x) {
        Node<T>* newNode = new Node<T>;
        newNode->next = head;
        newNode->item = x;
        head = newNode;
        size += 1;
    }

    /**
     * @brief Delete item at the beginning of the sequence
     * 
     */
    virtual void DeleteFirst(void) {
        Node<T>* newHead;
        if(head != NULL) {
            newHead = head->next;
            delete head;
            head = newHead;
            size -= 1;
        }
    }

    /**
     * @brief Insert Item at the end of the sequence
     * 
     * @param x 
     */
    virtual void InsertLast(T x) {
        Node<T>* currNode = head;
        Node<T>* newNode = new Node<T>;
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
        size += 1;
    }

    /**
     * @brief Delete item at the end of the sequence
     * 
     */
    virtual void DeleteLast(void) {
        Node<T>* prevNode = head;
        Node<T>* currNode;
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
            size -= 1;
        } else {
            /* DO NOTHING */
        }
    }

    /**
     * @brief Insert Item at the i index of the sequence
     * 
     * @param x 
     */
    virtual void InsertAt(int i, T x) {
        Node<T>* prevNode;
        Node<T>* currNode;
        Node<T>* newNode;
        int pointer;

        newNode = new Node<T>;
        newNode->item = x;

        if(i == 0) {
            this->InsertFirst(x);
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
                    size += 1;
                } else {
                    /* DO NOTHING */
                }             
            } else {
                /* DO NOTHING */
            }
        }
    }

    /**
     * @brief Delete Item at the i index of the sequence
     * 
     * @param x 
     */
    virtual void DeleteAt(int i) {
        Node<T>* tobeDeletedNode;
        Node<T>* currNode;
        Node<T>* prevNode;
        int pointer;
        if(i == 0) {
            DeleteFirst();
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
                    size -= 1;
                } else {
                    /* DO NOTHING */
                }             
            } else {
                /* DO NOTHING */
            }
        }
    }

    /**
     * @brief print the sequence
     * 
     */
    virtual void Print(void) {
        for(auto i = Begin(); i != End(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }

    /**
     * @brief Get the Size object
     * 
     * @return int 
     */
    int GetSize(void) {
        return size;
    }
    
    /**
     * @brief Get an iterator on the start of the sequence
     * 
     */
    virtual LinkedListSeqIter<T> Begin(void) {
        begin.SetCurr(head);
        return begin;        
    }

    /**
     * @brief Returns an iterator referring to the past-the-end 
     * element in the sequence container.
     * 
     */
    virtual LinkedListSeqIter<T> End(void) {
        end.SetCurr(NULL);
        return end;
    }
};