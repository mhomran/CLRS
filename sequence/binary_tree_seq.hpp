#pragma once

#include <iostream>
#include <cstddef>
#include "sequence.hpp"
#include "../bst/binary_tree.hpp"
using namespace std;

template <class T> 
class BinaryTreeSeq : public Sequence<T> {
    BinaryTree<BinaryNode<T>, T> binTree;
    
    public:
    
    /**
     * @brief Construct a new Array Seq object
     * 
     */
    BinaryTreeSeq(void) {
    }

    /**
     * @brief Destroy the Array Seq object
     * 
     */
    ~BinaryTreeSeq(void) {
    }

    /**
     * @brief given an iterable X, build sequence from items in X
     * 
     * @param X 
     */
    virtual void Build(T X[], int size) {
        binTree.Build(X, size);
    }

    /**
     * @brief Get the item at i
     * 
     * @param i 
     * @return T 
     */
    virtual T GetAt(int i){
        BinaryNode<T>* res;
        T item;
        res = binTree.GetRoot()->SubtreeAt(i);
        if(NULL != res) {
            item = res->GetItem();
        } else {
            /* DO NOTHING */
        }
        return item;
    }

    /**
     * @brief Set the item x at i
     * 
     * @param i 
     * @return int 
     */
    virtual void SetAt(int i, T x) {
        BinaryNode<T>* res;
        res = binTree.GetRoot()->SubtreeAt(i);
        if(NULL != res) {
            res->SetItem(x);
        } else {
            /* DO NOTHING */
        }
    }

    /**
     * @brief Insert Item at the beginning of the sequence
     * 
     * @param x 
     */
    virtual void InsertFirst(T x) {
        BinaryNode<T>* first;
        BinaryNode<T>* tobeInserted;
        
        tobeInserted = new BinaryNode<T>();
        tobeInserted->SetItem(x);

        if(NULL != binTree.GetRoot()) {
            first = binTree.GetRoot()->SubtreeFirst();
            first->SubtreeInsertBefore(tobeInserted);
        } else {
            binTree.SetRoot(tobeInserted);
        }
    }

    /**
     * @brief Delete item at the beginning of the sequence
     * 
     */
    virtual void DeleteFirst(void) {
        BinaryNode<T>* first;
        
        if(NULL != binTree.GetRoot()) {
            first = binTree.GetRoot()->SubtreeFirst();
            first = first->SubtreeDelete();
            delete first;
        } else {
            delete binTree.GetRoot();
            binTree.SetRoot(NULL);
        }
    }

    /**
     * @brief Insert Item at the end of the sequence
     * 
     * @param x 
     */
    virtual void InsertLast(T x) {
        BinaryNode<T>* last;
        BinaryNode<T>* tobeInserted;
        
        tobeInserted = new BinaryNode<T>();
        tobeInserted->SetItem(x);

        if(NULL != binTree.GetRoot()) {
            last = binTree.GetRoot()->SubtreeLast();
            last->SubtreeInsertAfter(tobeInserted);
        } else {
            binTree.SetRoot(tobeInserted);
        }
    }

    /**
     * @brief Delete item at the end of the sequence
     * 
     */
    virtual void DeleteLast(void) {
        BinaryNode<T>* last;
        
        if(NULL != binTree.GetRoot()) {
            last = binTree.GetRoot()->SubtreeLast();
            last = last->SubtreeDelete();
            delete last;
        } else {
            delete binTree.GetRoot();
            binTree.SetRoot(NULL);
        }
    }

    /**
     * @brief Insert Item at the i index of the sequence
     * 
     * @param x 
     */
    virtual void InsertAt(int i, T x) {
        BinaryNode<T>* res;
        BinaryNode<T>* tobeInserted;
        
        
        if(0 < i && i < GetSize()) {
            tobeInserted = new BinaryNode<T>();
            tobeInserted->SetItem(x);
            
            res = binTree.GetRoot()->SubtreeAt(i-1);
            res->SubtreeInsertAfter(tobeInserted);
        } else if (0 == i) {
            InsertFirst(x);
        } else {
            /* DO NOTHING */
        }
    }

    /**
     * @brief Delete Item at the i index of the sequence
     * 
     * @param x 
     */
    virtual void DeleteAt(int i) {
        BinaryNode<T>* tobeDeleted;
        
        if(0 < i && i < GetSize()) {
            tobeDeleted = binTree.GetRoot()->SubtreeAt(i);
            tobeDeleted = tobeDeleted->SubtreeDelete();
            delete tobeDeleted;
        } else if (0 == i) {
            DeleteFirst();
        } else {
            /* DO NOTHING */
        }
    }

    /**
     * @brief print the sequence
     * 
     */
    virtual void Print(void) {
        binTree.Print();
    }

    /**
     * @brief Get the Size object
     * 
     * @return int 
     */
    virtual int GetSize(void) {
        return binTree.GetSize();
    }

    /**
     * @brief Get an iterator on the start of the sequence
     * 
     */
    auto Begin(void) {
        return binTree.Begin();
    }

    /**
     * @brief Returns an iterator referring to the past-the-end 
     * element in the sequence container.
     * 
     */
    auto End(void) {
        return binTree.End();
    }
};