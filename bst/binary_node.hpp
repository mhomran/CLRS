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
    
    protected:
    T item;
    BinaryNode* right;
    BinaryNode* left;
    BinaryNode* parent;
    int height;

    int Height(BinaryNode* node) {
        if (NULL != node) return node->height;
        else return -1;
    }

    int GetSkew(void) {
        return Height(right) - Height(left);
    }

    template <class D>
    static void Swap(D&x, D&y) {
        D temp = x;
        x = y;
        y = temp;
    }

    void SubtreeRotateRight(void) {
        BinaryNode *D, *B, *E, *A, *C;

        D = this;
        B = D->left;
        E = D->right;
        A = B->left;
        C = B->right;

        Swap(B, D);
        Swap(B->item, D->item);

        D->SetLeft(C);
        D->SetRight(E);
        B->SetLeft(A);
        B->SetRight(D);

        if(NULL != A) A->SetParent(B);
        if(NULL != E) E->SetParent(D);

        B->SubtreeUpdate();
        D->SubtreeUpdate();
    }
    
    void SubtreeRotateLeft(void) {
        BinaryNode *D, *B, *E, *A, *C;

        B = this;
        A = B->left;
        D = B->right;
        C = D->left;
        E = D->right;

        Swap(B, D);
        Swap(B->item, D->item);

        D->SetLeft(B);
        D->SetRight(E);
        B->SetLeft(A);
        B->SetRight(C);

        if(NULL != A) A->SetParent(B);
        if(NULL != E) E->SetParent(D);

        B->SubtreeUpdate();
        D->SubtreeUpdate();
    }

    void Rebalance(void) {
        if(GetSkew() == 2) {
            if (right->GetSkew() < 0) {
                right->SubtreeRotateRight();
            } else {
                /* DO NOTHING */
            }
            SubtreeRotateLeft();
        } else if(GetSkew() == -2) {
            if (left->GetSkew() > 0) {
                left->SubtreeRotateLeft();
            } else {
                /* DO NOTHING */
            }
            SubtreeRotateRight();
        }
    }

    void Maintain(void) {
        Rebalance();
        SubtreeUpdate();
        if(NULL != parent) parent->Maintain();
    }

    public:
    BinaryNode(void) {
        this->right = NULL;
        this->left = NULL;
        this->parent = NULL;
        SubtreeUpdate();
    }

    virtual void DeepCopy(BinaryNode& A) {
        A.left = left;
        A.right = right;
        A.parent = parent;
        A.item = item;
        A.height = height;
    }
    
    virtual void DeepCopy(BinaryNode* A) {
        if (NULL != A) {
            DeepCopy(*A);
        } else {
            /* DO NOTHING */
        }
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

    void SetHeight(int height) {
        this->height = height;
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
    
    int GetHeight(void) {
        return height;
    }
    
    virtual void SubtreeUpdate(void) {
        height = 1 + max(Height(left), Height(right));
    }

    BinaryNode* SubtreeFirst(void) {
        BinaryNode* result;
        if(NULL != left) {
            result = left->SubtreeFirst();
        } else {
            result = this;
        }
        return result;
    }

    BinaryNode* SubtreeLast(void) {
        BinaryNode* result;
        if(NULL != right) {
            result = right->SubtreeLast();
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

        tobeInserted->Maintain();
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

        tobeInserted->Maintain();
    }

    BinaryNode* SubtreeDelete(void) {
        BinaryNode *pred, *succ, *tobeDeleted;
        
        if(NULL != left || NULL != right) {
            if(NULL != left) {
                pred = left->SubtreeLast();
                Swap(pred->item, this->item);
                tobeDeleted = pred->SubtreeDelete();
            } else {
                succ = right->SubtreeFirst();
                Swap(succ->item, this->item);
                tobeDeleted = succ->SubtreeDelete();
            }
        } else {
            tobeDeleted = this;
            if(NULL != parent) {
                if(this == parent->left) parent->left = NULL;
                else parent->right = NULL;

                tobeDeleted->Maintain();
            } else {
                /* DO NOTHING */
            }
        }
        return tobeDeleted;
    }

    BinaryNodeIter<T> Begin(void) {
        BinaryNodeIter<T> begin(this);
        return begin;
    }

    BinaryNodeIter<T> End(void) {
        BinaryNodeIter<T> end(NULL);
        return end;
    }

    virtual ~BinaryNode() {}
 };
