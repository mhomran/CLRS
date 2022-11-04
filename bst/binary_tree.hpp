#pragma once

#include "binary_node.hpp"
#include "../sequence/sequence.hpp"

template <class NodeType, class T>
class BinaryTree {
    NodeType* root;
    int size;

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

        return root;
    }

    public:
    BinaryTree() {
        root = NULL;
        size = 0;
    }

    ~BinaryTree() {
        /* subtree delete */
    }

    void Build(Sequence<T>& X) {
        if(X.GetSize() > 0) {
            root = BuildSubtree(X, 0, X.GetSize()-1);
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

    void Print() {
        for(auto i = Begin(); i != End(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
};