#pragma once

#include "../set/hash_table_set.hpp"

template<class T>
class Vertex;

template<class T>
class Edge {
    Vertex<T>* src;
    Vertex<T>* dst;
    int weight;
    public:

    Edge(void) {
        src = NULL;
        dst = NULL;
        weight = 1;
    }

    Edge(Vertex<T>* src, Vertex<T>* dst, int weight) 
    : src(src), dst(dst), weight(weight) {
        /* DO NOTHING */
    }

    void SetSrc(Vertex<T>* src) {
        this->src = src;
    }
    void SetDst(Vertex<T>* dst) {
        this->dst = dst;
    }
    void SetWeight(int weight) {
        this->weight = weight;
    }
    
    Vertex<T>* Getsrc(void) {
        return this->src;
    }
    Vertex<T>* GetDst(void) {
        return this->dst;
    }
    int GetWeight(void) {
        return this->weight;
    }

    friend ostream & operator << (ostream &out, const Edge &c) {
        out << "(" << *c.src << ") ";
        out << "-(" << c.weight << ")-> ";
        out << "(" << *c.dst << ") ";
        return out;
    }
};

template <class T>
class VertexIter : public HashTableSetIter<T> {
    public:
    VertexIter(const HashTableSetIter<T>& other) 
    : HashTableSetIter<T>(other) {
        /* DO NOTHING */
    }
    
    T operator*(void) {
        return HashTableSetIter<T>::operator*().GetItem();
    }
};

template <class T>
class Vertex {
    T item;
    int idx;

    bool visited;
    bool isInCurrentDAG;
    int shortestDistance;
    Vertex<T>* parent;

    HashTableSet<Edge<T>> adjList;

    public:
    Vertex() {
        parent = NULL;
    }

    void SetItem(T item) {
        this->item = item;
    }

    T GetItem(void) {
        return this->item;
    }

    void SetIdx(int idx) {
        this->idx = idx;
    }

    int GetIdx(void) {
        return this->idx;
    }
    
    void SetVisited(bool visited) {
        this->visited = visited;
    }

    bool IsVisited(void) {
        return this->visited;
    }

    void SetIsInCurrentDAG(bool isInCurrentDAG) {
        this->isInCurrentDAG = isInCurrentDAG;
    }

    bool IsInCurrentDAG(void) {
        return this->isInCurrentDAG;
    }

    void SetParent(Vertex<T>* parent) {
        this->parent = parent;
    }

    Vertex<T>* GetParent(void) {
        return this->parent;
    }

    void SetShortestDistance(int shortestDistance) {
        this->shortestDistance = shortestDistance;
    }

    int GetShortestDistance(void) {
        return this->shortestDistance;
    }

    void AddEdgeTo(Vertex<T>* tobeInsertedVertex, int weight=1) {
        Pair<Edge<T>> tobeInsertedPair;
        Edge<T> tobeInsertedEdge(this, tobeInsertedVertex, weight);

        if(NULL != tobeInsertedVertex) {
            tobeInsertedPair.SetKey(tobeInsertedVertex->GetIdx());
            tobeInsertedPair.SetItem(tobeInsertedEdge);
            adjList.Insert(tobeInsertedPair);
        } else {
            /* DO NOTHING */
        }
    }

    VertexIter<Edge<T>> Begin(void) {
        VertexIter<Edge<T>> begin = VertexIter<Edge<T>>(adjList.Begin());
        return begin;
    }

    VertexIter<Edge<T>> End(void) {
        VertexIter<Edge<T>> end = VertexIter<Edge<T>>(adjList.End());
        return end;
    }

    bool HasEdgeTo (int idx) {
        bool res;
        Pair<Edge<T>> found = adjList.Find(idx);

        if(-1 == found.GetKey()) {
            res = false;
        } else {
            res = true;
        }

        return res;
    }

    friend ostream & operator << (ostream &out, const Vertex &c) {
        out << c.idx << "," << c.item;
        return out;
    }

    void RelaxEdges(void) {
        for(auto edge = Begin(); edge != End(); edge++) {
            if((*edge).GetDst()->GetShortestDistance() > this->shortestDistance + (*edge).GetWeight()){
                (*edge).GetDst()->SetShortestDistance(this->shortestDistance + (*edge).GetWeight());
                (*edge).GetDst()->SetParent(this);
            } else {
                /* DO NOTHING */
            }
        }
    }
};