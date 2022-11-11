#pragma once
#include "seq_node.hpp"

template <class T>
class SeqNode : public BinaryNode<T> {
    int size;

    int Size(SeqNode* A) {
        if(NULL != A) {
            return A->size;
        } else {
            return 0;
        }
    }
    public:
    SeqNode() {
        SubtreeUpdate();
        BinaryNode<T>();
    }

    virtual void SubtreeUpdate(void) {
        BinaryNode<T>::SubtreeUpdate();
        size = 1 + (Size((SeqNode<T>*)this->left) + Size((SeqNode<T>*)this->right));
    }

    SeqNode<T>* SubtreeAt(int i) {
        int nl;
        SeqNode<T>* res = NULL;

        if(i < size) {
            if(NULL != this->left) {
                nl = ((SeqNode<T>*)this->left)->size;
            } else {
                nl = 0;
            }
            
            if(i < nl) {
                res = ((SeqNode<T>*)this->left)->SubtreeAt(i);
            } else if(i > nl) {
                res = ((SeqNode<T>*)this->right)->SubtreeAt(i - nl - 1);
            } else {
                res = this;
            }
        } else {
            /* DO NOTHING */
        }

        return res;
    }

    int GetSize() {
        return size;
    }

    void SetSize(int size) {
        this->size = size;
    }
};