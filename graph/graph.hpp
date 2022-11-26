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

    bool
    DepthFirstSearch(Vertex<T>* src, 
    DynamicArraySeq<Vertex<T>*>& TopologicalOrder) {
        bool isDAG = true;
        for(auto edge = src->Begin(); edge != src->End(); edge++) {
            if(! (*edge).GetDst()->IsVisited()) {
                (*edge).GetDst()->SetParent(src);
                (*edge).GetDst()->SetVisited(true);
                (*edge).GetDst()->SetIsInCurrentDAG(true);
                if(!DepthFirstSearch((*edge).GetDst(), TopologicalOrder)) {
                    isDAG = false;
                } else {
                    /* DO NOTHING */
                }
            } else {
                if((*edge).GetDst()->IsInCurrentDAG()) {
                    isDAG = false;
                } else {
                    /* DO NOTHING */
                }
            }
        }

        src->SetIsInCurrentDAG(false);
        
        TopologicalOrder.InsertFirst(src);

        return isDAG;
    }

    void InitializeVertices(void) {
        for(auto vIter = Begin(); vIter != End(); vIter++) {
            (*vIter)->SetParent(NULL);
            (*vIter)->SetVisited(false);
            (*vIter)->SetShortestDistance(INT_MAX);
            (*vIter)->SetIsInCurrentDAG(false);
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

    bool UnweightedShortestPath(Vertex<T>* src, 
    Vertex<T>* dst, DynamicArraySeq<Vertex<T>*>& path) {
        Vertex<T>* iter = dst;
        bool isReachable;

        InitializeVertices();
        BreadthFirstSearch(src);
        
        path.InsertFirst(dst);
        while(NULL != iter && iter != src) {
            iter = iter->GetParent();
            path.InsertFirst(iter);
        }

        if(NULL == iter) {
            isReachable = false;
        } else {
            isReachable = true;
        }

        return isReachable;
    }

    DynamicArraySeq<DynamicArraySeq<Vertex<T>*>> 
    GetConnectedComponents(void) {
        DynamicArraySeq<DynamicArraySeq<Vertex<T>*>> res;
        
        InitializeVertices();
        
        for(auto vIter = Begin(); vIter != End(); vIter++) {
            if(!(*vIter)->IsVisited()) {
                DynamicArraySeq<Vertex<T>*> connectedComponent;
                (*vIter)->SetVisited(true);
                (*vIter)->SetParent((*vIter));
                DepthFirstSearch((*vIter), connectedComponent);
                res.InsertLast(connectedComponent);
            } else {
                /* DO NOTHING */
            }
        }

        return res;
    }

    bool
    DAGRelaxation(Vertex<T>* src, Vertex<T>* dst, 
    DynamicArraySeq<Vertex<T>*>& path) {
        bool isDAG;
        DynamicArraySeq<Vertex<T>*> topologicalOrder;
        Vertex<T>* iter = dst;

        InitializeVertices();

        src->SetVisited(true);
        src->SetIsInCurrentDAG(true);
        src->SetParent(src);
        src->SetShortestDistance(0);

        isDAG = DepthFirstSearch(src, topologicalOrder);

        if(isDAG) {
            for(auto v = topologicalOrder.Begin(); v != topologicalOrder.End(); v++) {
                (*v)->RelaxEdges();
            }
            
            path.InsertFirst(dst);
            while(NULL != iter && iter != src) {
                iter = iter->GetParent();
                path.InsertFirst(iter);
            }
        } else {
            /* DO NOTHING */
        }

        return isDAG;
    }

    bool HasNegativeCycle(void) {
        bool hasNegativeCycle = false;
        bool relaxable;

        InitializeVertices();

        auto start = *this->Begin();
        start->SetShortestDistance(0);
        start->SetParent(start);

        for(auto uIter = this->Begin(); uIter != this->End(); uIter++) {
            for(auto vIter = this->Begin(); vIter != this->End(); vIter++) {
                (*vIter)->RelaxEdges();
            }
        }

        for(auto vIter = this->Begin(); vIter != this->End(); vIter++) {
            relaxable = (*vIter)->RelaxEdges();
            if(relaxable) {
                hasNegativeCycle = true;
                break;
            } else {
                /* DO NOTHING */
            }
        }

        return hasNegativeCycle;
    }
};