#pragma once

#include "binary_node.hpp"
#include "../sequence/sequence.hpp"
#include "../sequence/dynamic_array_seq.hpp"

template <class NodeType, class T>
class BinaryTree {
    

    NodeType* BuildSubtree(Sequence<T>& X, int i, int j) {
        int c;

        c = (i + j) / 2;

        NodeType* root = new NodeType();
        root->SetItem(X.GetAt(c));

        if(i < c) {
            NodeType* left = BuildSubtree(X, i, c-1);
            root->SetLeft(left);
            left->SetParent(root);
        }
        if(c < j) {
            NodeType* right = BuildSubtree(X, c+1, j);
            root->SetRight(right);
            right->SetParent(root);
        }

        root->SubtreeUpdate();

        return root;
    }
    
    NodeType* BuildSubtree(T X[], int i, int j) {
        int c;

        c = (i + j) / 2;

        NodeType* root = new NodeType();
        root->SetItem(X[c]);
        root->SetSize(j - i + 1);

        if(i < c) {
            NodeType* left = BuildSubtree(X, i, c-1);
            root->SetLeft(left);
            left->SetParent(root);
        }
        if(c < j) {
            NodeType* right = BuildSubtree(X, c+1, j);
            root->SetRight(right);
            right->SetParent(root);
        }

        root->SubtreeUpdate();

        return root;
    }

    protected:
    NodeType* root;

    public:
    BinaryTree() {
        root = NULL;
    }

    ~BinaryTree() {
        while(NULL != root) {
            NodeType* tobeDeleted = ((NodeType*)root->SubtreeDelete());
            if(tobeDeleted == root) root = NULL;
            delete tobeDeleted;
        } 
    }

    void Build(Sequence<T>& X) {
        if(X.GetSize() > 0) {
            root = BuildSubtree(X, 0, X.GetSize()-1);
        } else {
            /* DO NOTHING */
        }
    }
    
    void Build(T X[], int size) {
        if(size > 0) {
            root = BuildSubtree(X, 0, size-1);
        } else {
            /* DO NOTHING */
        }
    }

    BinaryNodeIter<T> Begin() {
        BinaryNodeIter<T> begin(root);
        return begin;
    }

    BinaryNodeIter<T> End() {
        BinaryNodeIter<T> end(NULL);
        return end;
    }

    NodeType* GetRoot() {
        return root;
    }
    
    void SetRoot(NodeType* root) {
        this->root = root;
    }

    int GetSize() {
        int size;
        if(NULL != root) {
            size = root->GetSize();
        } else {
            size = 0;
        }
        return size;
    }

    void Print() {
        for(auto i = Begin(); i != End(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }

    void PrintLevels() {
        DynamicArraySeq<NodeType*> queue;
        NodeType* tobePrinted;
        int levelNumberOfNodes;
        if(NULL != root) {
            queue.InsertFirst(root);
            levelNumberOfNodes = 1;
            while(levelNumberOfNodes > 0) {
                tobePrinted = queue.GetAt(0);

                cout << tobePrinted->GetItem() << " ";

                queue.DeleteFirst();
                if (NULL != tobePrinted->GetLeft()) {
                    queue.InsertLast(tobePrinted->GetLeft());
                } else {
                    /* DO NOTHING */
                }
                if (NULL != tobePrinted->GetRight()) {
                    queue.InsertLast(tobePrinted->GetRight());
                } else {
                    /* DO NOTHING */
                }

                levelNumberOfNodes --;
                if(0 == levelNumberOfNodes) {
                    levelNumberOfNodes = queue.GetSize();
                    cout << endl;
                } else {
                    /* DO NOTHING */
                }
            }
        } else {
            /* DO NOTHING */
        }
    }
};