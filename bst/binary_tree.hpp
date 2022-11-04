#pragma once

#include "binary_node.hpp"
#include "../sequence/sequence.hpp"

template <class NodeType, class T>
class BinaryTree {
    NodeType* root;

    NodeType* BuildSubtree(Sequence<T>& X, int i, int j) {
        int c;

        c = (i + j) / 2;

        NodeType* root = new NodeType();
        root->SetItem(X.GetAt(c));
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

        return root;
    }

    public:
    BinaryTree() {
        root = NULL;
    }

    ~BinaryTree() {
        while(NULL != root) {
            NodeType* tobeDeleted = root->SubtreeDelete();
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
};