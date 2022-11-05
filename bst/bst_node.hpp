#pragma once
#include "binary_node.hpp"

template <class T>
class BstNode : public BinaryNode<T> {
    
    public:
    BstNode<T>* SubtreeFind(int k) {
        BstNode<T>* res;
        res = NULL;
        if(this->item.GetKey() > k) {
            if (NULL != this->left) {
                res = ((BstNode<T>*)this->left)->SubtreeFind(k);
            } else {
                /* DO NOTHING */
            }
        } else if (this->item.GetKey() < k) {
            if (NULL != this->right) {
                res = ((BstNode<T>*)this->right)->SubtreeFind(k);
            } else {
                /* DO NOTHING */
            }
        } else {
            res = this;
        }
        return res;
    }
    
    BstNode<T>* SubtreeFindNext(int k) {
        BstNode<T>* res;
        res = NULL;
        if(this->item.GetKey() > k) {
            if (NULL != this->left) {
                res = ((BstNode<T>*)this->left)->SubtreeFindNext(k);
                if(NULL != res) {
                    /* DO NOTHING */
                } else {
                    res = this;
                }
            } else {
                res = this;
            }
        } else {
            if (NULL != this->right) {
                res = ((BstNode<T>*)this->right)->SubtreeFindNext(k);
            } else {
                /* DO NOTHING */
            }
        }
        return res;
    }
    
    BstNode<T>* SubtreeFindPrev(int k) {
        BstNode<T>* res;
        res = NULL;
        if(this->item.GetKey() < k) {
            if (NULL != this->right) {
                res = ((BstNode<T>*)this->right)->SubtreeFindPrev(k);
                if(NULL != res) {
                    /* DO NOTHING */
                } else {
                    res = this;
                }
            } else {
                res = this;
            }
        } else {
            if (NULL != this->left) {
                res = ((BstNode<T>*)this->left)->SubtreeFindPrev(k);
            } else {
                /* DO NOTHING */
            }
        }
        return res;
    }
    
    BstNode<T>* SubtreeInsert(BstNode<T>* tobeInserted) {
        BstNode<T>* res;

        res = NULL;
        if(this->item.GetKey() < tobeInserted->GetItem().GetKey()) {
            if (NULL != this->right) {
                res = ((BstNode<T>*)this->right)->SubtreeInsert(tobeInserted);
            } else {
                this->SubtreeInsertAfter(tobeInserted);
            }
        } else if(this->item.GetKey() > tobeInserted->GetItem().GetKey()) {
            if (NULL != this->left) {
                res = ((BstNode<T>*)this->left)->SubtreeInsert(tobeInserted);
            } else {
                this->SubtreeInsertBefore(tobeInserted);
            }
        }
        return res;
    }


};