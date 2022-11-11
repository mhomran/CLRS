#include "binary_node.hpp"
#include "binary_tree.hpp"
#include "../sequence/array_seq.hpp"

int main() {
    ArraySeq<int> A;
    int i;
    
    BinaryTree<BinaryNode<int>, int> binTree;

    BinaryNode<int>* last;
    BinaryNode<int>* tobeInserted;

    for(i = 0; i < 10; i++) {
        A.InsertLast(i);
    }

    binTree.Build(A);

    binTree.PrintLevels();

    last = binTree.GetRoot();

    for(i = 10; i < 20; i++) {
        tobeInserted = new BinaryNode<int>();
        tobeInserted->SetItem(i);

        last->SubtreeInsertAfter(tobeInserted);
        last = tobeInserted;

        binTree.PrintLevels();
        cout << endl;
    }
}