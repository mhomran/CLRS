#pragma once

#include "../sequence/dynamic_array_seq.hpp"

template <class T>
class BinaryNode;

template <class T>
class BinaryNodeIter {
    DynamicArraySeq<BinaryNode<T>*> stack;

    void Next(void) {
        if(stack.GetSize() > 0) {
            BinaryNode<T>* curr = stack.GetAt(stack.GetSize()-1);
            stack.DeleteLast();

            curr = curr->GetRight();
            while(NULL != curr) {
                stack.InsertLast(curr);
                curr = curr->GetLeft();
            }
            
        } else {
            /* DO NOTHING */
        }
    }

    public:
    BinaryNodeIter(BinaryNode<T>* root) {
        if(NULL != root) {
            while(NULL != root) {
                stack.InsertLast(root);
                root = root->GetLeft();
            }
        } else {
            /* DO NOTHING */
        }
    }

    void operator ++(int) {
        Next();
    }

    void operator ++() {
        Next();
    }
    
    T operator *() {
        T res;
        if(stack.GetSize() > 0) {
            BinaryNode<T>* curr = stack.GetAt(stack.GetSize()-1);
            res = curr->GetItem();
        } else {
            /* DO NOTHING */
        }
        return res;
    }

    bool operator != (BinaryNodeIter<T> B) {
        return ! operator ==(B);
    }

    bool operator == (BinaryNodeIter<T> B) {
        bool res = true;
        int i;
        if(B.stack.GetSize() == stack.GetSize()) {
            for(i = 0; i < stack.GetSize(); i++) {
                if(B.stack.GetAt(i) != stack.GetAt(i)) {
                    res = false;
                    break;
                }
            }
        } else {
            res = false;
        }
        return res;
    }
};

template <class T>
class BinaryNode {
    T item;
    BinaryNode* right;
    BinaryNode* left;
    BinaryNode* parent;

    public:
    BinaryNode(void) {
        this->right = NULL;
        this->left = NULL;
        this->parent = NULL;
    }

    void DeepCopy(BinaryNode& A) {
        A.left = left;
        A.right = right;
        A.parent = parent;
        A.item = item;
    }

    BinaryNode(BinaryNode& A) {
        DeepCopy(A);
    }

    void operator = (BinaryNode& A) {
        DeepCopy(A);
    }

    void SetRight(BinaryNode* right) {
        this->right = right;
    }

    void SetLeft(BinaryNode* left) {
        this->left = left;
    }

    void SetParent(BinaryNode* parent) {
        this->parent = parent;
    }
    
    void SetItem(T item) {
        this->item = item;
    }

    BinaryNode* GetRight(void) {
        return right;
    }

    BinaryNode* GetLeft(void) {
        return left;
    }

    BinaryNode* GetParent(void) {
        return parent;
    }
    
    T GetItem(void) {
        return item;
    }

    BinaryNode* SubtreeFirst(void) {
        BinaryNode* result;
        if(NULL != left) {
            result = SubtreeFirst(left);
        } else {
            result = this;
        }
        return result;
    }

    BinaryNode* SubtreeLast(void) {
        BinaryNode* result;
        if(NULL != right) {
            result = SubtreeLast(left);
        } else {
            result = this;
        }
        return result;
    }

    BinaryNode* Successor(void) {
        BinaryNode* result;
        BinaryNode* curr;
        if(NULL != right) {
            result = SubtreeFirst(right);
        } else {
            curr = this;
            while(NULL != curr->parent && curr != curr->parent->left) {
                curr = curr->parent;
            }
            result = curr->parent;
        }
        return result;
    }
    
    BinaryNode* Predecessor(void) {
        BinaryNode* result;
        BinaryNode* curr;
        if(NULL != left) {
            result = SubtreeLast(left);
        } else {
            curr = this;
            while(NULL != curr->parent && curr != curr->parent->right) {
                curr = curr->parent;
            }
            result = curr->parent;
        }
        return result;
    }

    void SubtreeInsertBefore(BinaryNode* tobeInserted) {
        BinaryNode* pred;

        if(NULL == left) {
            left = tobeInserted;
            tobeInserted->parent = this;
        } else {
            pred = left->SubtreeLast();
            pred->right = tobeInserted;
            tobeInserted->parent = pred;
        }
    }

    void SubtreeInsertAfter(BinaryNode* tobeInserted) {
        BinaryNode* succ;

        if(NULL == right) {
            right = tobeInserted;
            tobeInserted->parent = this;
        } else {
            succ = right->SubtreeFirst();
            succ->left = tobeInserted;
            tobeInserted->parent = succ;
        }
    }

    void SubtreeDelete(void) {
        BinaryNode* pred;
        BinaryNode* succ;
        T temp;
        if(NULL != left || NULL != right) {
            if(NULL != left) {
                pred = left->SubtreeLast();
                temp = pred->item;
                pred->item = item;
                item = temp;
                pred->SubtreeDelete();
            } else {
                succ = left->SubtreeFirst();
                temp = succ->item;
                succ->item = item;
                item = temp;
                succ->SubtreeDelete();
            }
        } else {
            if(NULL != parent) {
                if(this == parent->left) parent->left = NULL;
                else parent->right = NULL;
            } else {
                /* DO NOTHING */
            }
        }
    }

    BinaryNodeIter<T> Begin(void) {
        BinaryNodeIter<T> begin(this);
        return begin;
    }

    BinaryNodeIter<T> End(void) {
        BinaryNodeIter<T> end(NULL);
        return end;
    }
 };
