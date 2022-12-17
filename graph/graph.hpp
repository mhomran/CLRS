#pragma once

#include "../set/hash_table_set.hpp"
#include "vertex.hpp"
#include "../sequence/dynamic_array_seq.hpp"
#include "priority_queue.hpp"

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
                if(! (*edge)->GetDst()->IsVisited()) {
                    (*edge)->GetDst()->SetParent(curr);
                    (*edge)->GetDst()->SetVisited(true);
                    queue.InsertLast((*edge)->GetDst());
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
            if(! (*edge)->GetDst()->IsVisited()) {
                (*edge)->GetDst()->SetParent(src);
                (*edge)->GetDst()->SetVisited(true);
                (*edge)->GetDst()->SetIsInCurrentDAG(true);
                if(!DepthFirstSearch((*edge)->GetDst(), TopologicalOrder)) {
                    isDAG = false;
                } else {
                    /* DO NOTHING */
                }
            } else {
                if((*edge)->GetDst()->IsInCurrentDAG()) {
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

    void JohnsonReweighting(void){
        int newWeight;
        for(auto vIter = this->Begin(); vIter != this->End(); vIter++) {
            for(auto edge = (*vIter)->Begin(); edge != (*vIter)->End(); edge++) {
                newWeight = (*edge)->GetWeight();
                newWeight += (*edge)->GetSrc()->GetShortestDistance();
                newWeight -= (*edge)->GetDst()->GetShortestDistance();
                (*edge)->SetWeight(newWeight);
            }
        }
    }

    public:
    void InsertVertex(Vertex<T>* tobeInsertedVertex) {
        Pair<Vertex<T>*> tobeInsertedPair;

        if(NULL != tobeInsertedVertex) {
            tobeInsertedPair.SetKey(tobeInsertedVertex->GetId());
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
            
            path.InsertLast(dst);
            while(NULL != iter && iter != src) {
                iter = iter->GetParent();
                path.InsertLast(iter);
            }
            path.Reverse();
        } else {
            /* DO NOTHING */
        }

        return isDAG;
    }

    bool BellmanFord(Vertex<T>* src, Vertex<T>* dst, 
    DynamicArraySeq<Vertex<T>*>& path) {
        bool hasNegativeCycle = false;
        bool relaxable;
        Vertex<T>* iter;

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

        iter = dst;
        path.InsertLast(dst);
        while(NULL != iter && iter != src) {
            iter = iter->GetParent();
            path.InsertLast(iter);
        }
        path.Reverse();

        return hasNegativeCycle;
    }

    bool Dijkstra(Vertex<T>* src, Vertex<T>* dst, 
    DynamicArraySeq<Vertex<T>*>& path) {
        PriorityQueue<T> pq;
        bool hasNegativeWeights = true;
        Vertex<T>* iter;

        InitializeVertices();

        src->SetShortestDistance(0);
        src->SetParent(src);

        for(auto vIter = this->Begin(); vIter != this->End(); vIter++) {
            pq.Insert((*vIter));
        }
        
        for(auto vIter = this->Begin(); vIter != this->End(); vIter++) {
            iter = pq.DeleteMin();

            for(auto edge = iter->Begin(); edge != iter->End(); edge++) {
                if((*edge)->GetSrc()->GetShortestDistance() != INT_MAX &&
                    (*edge)->GetDst()->GetShortestDistance() > 
                    (*edge)->GetSrc()->GetShortestDistance() + (*edge)->GetWeight()){
                    
                    if((*edge)->GetWeight() < 0) {
                        hasNegativeWeights = false;
                        break;
                    } else {
                        (*edge)->GetDst()->SetShortestDistance((*edge)->GetSrc()->GetShortestDistance() + (*edge)->GetWeight());
                        (*edge)->GetDst()->SetParent((*edge)->GetSrc());
                        pq.DecreaseKey((*edge)->GetDst(), (*edge)->GetDst()->GetShortestDistance());
                    }
                
                } else {
                    /* DO NOTHING */
                }
            }

            if(!hasNegativeWeights) {
                break;
            } else {
                /* DO NOTHING */
            }
        }

        iter = dst;
        path.InsertLast(dst);
        while(NULL != iter && iter != src) {
            iter = iter->GetParent();
            path.InsertLast(iter);
        }
        path.Reverse();

        return hasNegativeWeights;
    }

    bool Johnson(void) {
        bool hasNegativeCycle;
        Vertex<T> x;
        Graph<T> Gx;
        DynamicArraySeq<Vertex<T>*> sp;
        DynamicArraySeq<Vertex<T>*> path;
        Vertex<T>* iter;

        for(auto vIter = this->Begin(); vIter != this->End(); vIter++) {
            x.AddEdgeTo(*vIter, 0);
        }

        Gx.InsertVertex(&x);
        for(auto vIter = this->Begin(); vIter != this->End(); vIter++) {
            Gx.InsertVertex(*vIter);
        }

        hasNegativeCycle = Gx.BellmanFord(&x, &x, sp);
        if(hasNegativeCycle) {
            hasNegativeCycle = true;
        } else {
            hasNegativeCycle = false;
            Gx.JohnsonReweighting();
            
            for(auto vIter = this->Begin(); vIter != this->End(); vIter++) {
                Dijkstra(*vIter, NULL, sp);
                
                for(auto dst = this->Begin(); dst != this->End(); dst++) {

                    path.Clean();
                    iter = *dst;
                    path.InsertLast(*dst);
                    while(NULL != iter && iter != *vIter) {
                        iter = iter->GetParent();
                        path.InsertLast(iter);
                    }
                    path.Reverse();

                    for(auto vPtr = path.Begin(); vPtr != path.End(); vPtr++) {
                        if(NULL != *vPtr) cout << **vPtr << endl;
                        else cout << "NULL !" << endl;
                    }
                    cout << endl;
                }
            }
        }

        return hasNegativeCycle;
    }
};