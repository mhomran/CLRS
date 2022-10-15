#include <iostream>
#include "linked_list_seq.hpp"
using namespace std;


/**
 * @brief Construct a new LinkedListSeq object
 * 
 * @param x 
 */
LinkedListSeq::LinkedListSeq() {
    head = NULL; /* head is not a wild pointer now */
}

/**
 * @brief given an iterable X, build sequence from items in X
 * 
 * @param X 
 */
void LinkedListSeq::Build(int X[], int size) {
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
int LinkedListSeq::GetAt(int i) {
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
void LinkedListSeq::SetAt(int i, int x) {
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
void LinkedListSeq::InsertFirst(int x) {
    Node* newNode = new Node;
    newNode->next = head;
    newNode->item = x;
    head = newNode;
}

/**
 * @brief Delete item at the beginning of the array
 * 
 */
void LinkedListSeq::DeleteFirst(void) {
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
void LinkedListSeq::InsertLast(int x) {
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
void LinkedListSeq::DeleteLast(void) {
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
void LinkedListSeq::InsertAt(int i, int x) {
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
void LinkedListSeq::DeleteAt(int i) {
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
void LinkedListSeq::Print(void) {
    Node* currNode = head;
    while(currNode != NULL) {
        cout << currNode->item << " ";
        currNode = currNode->next;
    }
    cout << endl;
}

/**
 * @brief Destroy the LinkedListSeq object
 * 
 */
LinkedListSeq::~LinkedListSeq() {
    Node* currNode;
    Node* tobeDeletedNode;

    currNode = head;
    while(currNode != NULL) {
        tobeDeletedNode = currNode;
        currNode = tobeDeletedNode->next;
        delete tobeDeletedNode;
    }
}

