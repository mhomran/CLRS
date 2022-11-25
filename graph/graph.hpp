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
    
    void BreadthFirstSearch(Vertex<T>* src) {
        DynamicArraySeq<Vertex<T>*> queue;
        Vertex<T>* curr;

        src->SetParent(src);
        src->SetVisited(true);
        
        queue.InsertLast(src);
        
        while(!queue.isEmpty()) {
            curr = queue.GetAt(0);
            queue.DeleteFirst();

            for(auto edge = curr->Begin(); edge != curr->End(); edge++) {
                if(! (*edge).GetDst()->IsVisited()) {
                    (*edge).GetDst()->SetParent(curr);
                    (*edge).GetDst()->SetVisited(true);
                    queue.InsertLast((*edge).GetDst());
                } else {
                    /* DO NOTHING */
                }
            }
        }
    }

    void 
    DepthFirstSearch(Vertex<T>* src, 
    DynamicArraySeq<Vertex<T>*>& connectedComponent) {
        for(auto edge = src->Begin(); edge != src->End(); edge++) {
            if(! (*edge).GetDst()->IsVisited()) {
                (*edge).GetDst()->SetParent(src);
                (*edge).GetDst()->SetVisited(true);
                DepthFirstSearch((*edge).GetDst(), connectedComponent);
            }
        }
        
        connectedComponent.InsertLast(src);
    }

    void MakeVerticesNotVisited(void) {
        for(auto vIter = Begin(); vIter != End(); vIter++) {
            (*vIter)->SetVisited(false);
        }
    }

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

    DynamicArraySeq<Vertex<T>*> UnweightedShortestPath(Vertex<T>* src, Vertex<T>* dst) {
        DynamicArraySeq<Vertex<T>*> path;
        Vertex<T>* iter = dst;

        MakeVerticesNotVisited();
        BreadthFirstSearch(src);
        
        path.InsertFirst(dst);
        while(iter != src) {
            iter = iter->GetParent();
            path.InsertFirst(iter);
        }

        return path;
    }

    DynamicArraySeq<DynamicArraySeq<Vertex<T>*>> 
    GetConnectedComponents(void) {
        DynamicArraySeq<DynamicArraySeq<Vertex<T>*>> res;
        
        MakeVerticesNotVisited();
        
        for(auto vIter = Begin(); vIter != End(); vIter++) {
            if(!(*vIter)->IsVisited()) {
                DynamicArraySeq<Vertex<T>*> connectedComponent;
                DepthFirstSearch((*vIter), connectedComponent);
                res.InsertLast(connectedComponent);
            } else {
                /* DO NOTHING */
            }
        }

        return res;
    }
};