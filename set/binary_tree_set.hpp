#pragma once
#include "set.hpp"
#include "../bst/binary_tree.hpp"
#include "../bst/bst_node.hpp"


template <class T>
class BinaryTreeSet : public BinaryTree<BstNode<Pair<T>>, Pair<T>>, public Set<T>
{

    public:
    
    /**
     * @brief given an iterable X, build set from items in X
     * 
     * @param X 
     * @param size 
     */
    virtual void Build(Pair<T> X[], int size) {
        int i;
        BstNode<Pair<T>>* tobeInserted;
        for(i = 0; i < size; i++) {
            tobeInserted = new BstNode<Pair<T>>();
            tobeInserted->SetItem(X[i]);
            if(NULL != this->root) {
                this->root->SubtreeInsert(tobeInserted);
            } else {
                this->root = tobeInserted;
            }
        }
    }

    /**
     * @brief return the stored item with key k
     * 
     * @param k 
     */
    virtual Pair<T> Find(int k) {
        Pair<T> res;
        BstNode<Pair<T>>* bstFinding;
        if(NULL != this->root) {
            bstFinding = this->root->SubtreeFind(k);
            if(NULL != bstFinding) {
                res = bstFinding->GetItem();
            } else {
                /* DO NOTHING */
            }
        } else {
            /* DO NOTHING */
        }
        return res;
    }

    /**
     * @brief add x to set (replace item with key x.key if one already exists) 
     * 
     * @param x
     */
    virtual void Insert(Pair<T> x) {
        Pair<T> res;
        BstNode<Pair<T>>* tobeInserted;
        BstNode<Pair<T>>* bstFinding;

        if(NULL == this->root) {
            tobeInserted = new BstNode<Pair<T>>();
            tobeInserted->SetItem(x);
            this->root = tobeInserted;
        } else {
            bstFinding = this->root->SubtreeFind(x.GetKey());
            if(NULL != bstFinding) {
                bstFinding->SetItem(x);
            } else {
                tobeInserted = new BstNode<Pair<T>>();
                tobeInserted->SetItem(x);
                this->root->SubtreeInsert(tobeInserted);
            }
        }
    }

    /**
     * @brief remove and return the stored item with key k
     * 
     * @param k 
     */
    virtual void Delete(int k) {
        BstNode<Pair<T>>* bstFinding;
        BinaryNode<Pair<T>>* tobeDeleted;

        if(NULL != this->root) {
            bstFinding = this->root->SubtreeFind(k);
            if(NULL != bstFinding) {
                tobeDeleted = bstFinding->SubtreeDelete();
                delete tobeDeleted;
            } else {
                /* DO NOTHING */
            }
        } else {
            /* DO NOTHING */
        }
    }

    /**
     * @brief return the stored item with smallest key
     * 
     */
    virtual Pair<T> FindMin(void) {
        Pair<T> res;
        if(NULL != this->root) {
            res = this->root->SubtreeFirst()->GetItem();
        } else {
            /* DO NOTHING */
        }
        return res;
    }

    /**
     * @brief return the stored item with largest key
     * 
     */
    virtual Pair<T> FindMax(void) {
        Pair<T> res;
        if(NULL != this->root) {
            res = this->root->SubtreeLast()->GetItem();
        } else {
            /* DO NOTHING */
        }
        return res;
    }

    /**
     * @brief return the stored item with smallest key larger than k
     * 
     * @param k 
     */
    virtual Pair<T> FindNext(int k) {
        Pair<T> res;
        BstNode<Pair<T>>* bstFinding = this->root->SubtreeFindNext(k);
        if(NULL != bstFinding) {
            res = bstFinding->GetItem();
        } else {
            /* DO NOTHING */
        }
        return res;
    }

    /**
     * @brief return the stored item with largest key smaller than k
     * 
     * @param k 
     */
    virtual Pair<T> FindPrev(int k) {
        Pair<T> res;
        BstNode<Pair<T>>* bstFinding = this->root->SubtreeFindPrev(k);
        if(NULL != bstFinding) {
            res = bstFinding->GetItem();
        } else {
            /* DO NOTHING */
        }
        return res;
    }

    /**
     * @brief return the size of the set
     * 
     * @param k 
     */
    virtual int GetSize(void) {
        return BinaryTree<BstNode<Pair<T>>, Pair<T>>::GetSize();
    }

    /**
     * @brief Print the Set
     * 
     */
    virtual void Print(void) {
        BinaryTree<BstNode<Pair<T>>, Pair<T>>::Print();
    }

    /**
     * @brief Destroy the Set object
     * 
     */
    virtual ~BinaryTreeSet() {};
};