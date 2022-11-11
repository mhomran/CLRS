#pragma once

#include <iostream>
#include <cstddef>
#include "sequence.hpp"
#include "../bst/binary_tree.hpp"
#include "../bst/seq_node.hpp"
using namespace std;

template <class T> 
class BinaryTreeSeq : public Sequence<T> {
    BinaryTree<SeqNode<T>, T> binTree;
    
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
        SeqNode<T>* res;
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
        SeqNode<T>* res;
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
        SeqNode<T>* first;
        SeqNode<T>* tobeInserted;
        
        tobeInserted = new SeqNode<T>();
        tobeInserted->SetItem(x);

        if(NULL != binTree.GetRoot()) {
            first = (SeqNode<T>*)binTree.GetRoot()->SubtreeFirst();
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
        SeqNode<T>* first;
        
        if(NULL != binTree.GetRoot()) {
            first = (SeqNode<T>*)binTree.GetRoot()->SubtreeFirst();
            first = (SeqNode<T>*)first->SubtreeDelete();
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
        SeqNode<T>* last;
        SeqNode<T>* tobeInserted;
        
        tobeInserted = new SeqNode<T>();
        tobeInserted->SetItem(x);

        if(NULL != binTree.GetRoot()) {
            last = (SeqNode<T>*)binTree.GetRoot()->SubtreeLast();
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
        SeqNode<T>* last;
        
        if(NULL != binTree.GetRoot()) {
            last = (SeqNode<T>*)binTree.GetRoot()->SubtreeLast();
            last = (SeqNode<T>*)last->SubtreeDelete();
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
        SeqNode<T>* res;
        SeqNode<T>* tobeInserted;
        
        
        if(0 < i && i < GetSize()) {
            tobeInserted = new SeqNode<T>();
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
        SeqNode<T>* tobeDeleted;
        
        if(0 < i && i < GetSize()) {
            tobeDeleted = (SeqNode<T>*)binTree.GetRoot()->SubtreeAt(i);
            tobeDeleted = (SeqNode<T>*)tobeDeleted->SubtreeDelete();
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