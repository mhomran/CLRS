#include "binary_node.hpp"
#include "binary_tree.hpp"
#include "../sequence/array_seq.hpp"

int main() {
    ArraySeq<int> A;
    int i;
    
    BinaryTree<BinaryNode<int>, int> binTree;

    for(i = 0; i < 10; i++) {
        A.InsertLast(i);
    }

    binTree.Build(A);

    binTree.Print();
}