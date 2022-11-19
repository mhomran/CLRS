#pragma once

#include "../set/hash_table_set.hpp"
#include "vertex.hpp"
#include "../sequence/dynamic_array_seq.hpp"


template <class T>
class GraphIter : public HashTableSetIter<T> {
    public:
    GraphIter(const HashTableSetIter<T>& other) 
    : HashTableSetIter<T>(other) {
        /* DO NOTHING */
    }
    
    T operator*(void) {
        return HashTableSetIter<T>::operator*().GetItem();
    }
};

template <class T>
class Graph {
    HashTableSet<Vertex<T>*> vertices;
    
    public:
    void InsertVertex(Vertex<T>* tobeInsertedVertex) {
        Pair<Vertex<T>*> tobeInsertedPair;

        if(NULL != tobeInsertedVertex) {
            tobeInsertedPair.SetKey(tobeInsertedVertex->GetIdx());
            tobeInsertedPair.SetItem(tobeInsertedVertex);
            vertices.Insert(tobeInsertedPair);
        } else {
            /* DO NOTHING */
        }
    }

    GraphIter<Vertex<T>*> Begin(void) {
        GraphIter<Vertex<T>*> begin = GraphIter<Vertex<T>*>(vertices.Begin());
        return begin;
    }

    GraphIter<Vertex<T>*> End(void) {
        GraphIter<Vertex<T>*> end = GraphIter<Vertex<T>*>(vertices.End());
        return end;
    }
};