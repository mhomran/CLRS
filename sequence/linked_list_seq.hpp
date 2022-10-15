#include "sequence.hpp"

typedef struct node {
    struct node* next;
    int item;
} Node;

class LinkedListSeq : public Sequence {
    Node* head;
    
    public:

    LinkedListSeq(void);
    ~LinkedListSeq(void);

    /**
     * @brief given an iterable X, build sequence from items in X
     * 
     * @param X 
     */
    virtual void Build(int X[], int size);

    /**
     * @brief Get the item at i
     * 
     * @param i 
     * @return int 
     */
    virtual int GetAt(int i);

    /**
     * @brief Set the item x at i
     * 
     * @param i 
     * @return int 
     */
    virtual void SetAt(int i, int x);

    /**
     * @brief Insert Item at the beginning of the sequence
     * 
     * @param x 
     */
    virtual void InsertFirst(int x);

    /**
     * @brief Delete item at the beginning of the sequence
     * 
     */
    virtual void DeleteFirst(void);

    /**
     * @brief Insert Item at the end of the sequence
     * 
     * @param x 
     */
    virtual void InsertLast(int x);

    /**
     * @brief Delete item at the end of the sequence
     * 
     */
    virtual void DeleteLast(void);

    /**
     * @brief Insert Item at the i index of the sequence
     * 
     * @param x 
     */
    virtual void InsertAt(int i, int x);

    /**
     * @brief Delete Item at the i index of the sequence
     * 
     * @param x 
     */
    virtual void DeleteAt(int i);

    /**
     * @brief print the sequence
     * 
     */
    virtual void Print(void);

};