#pragma once

#include "../set/hash_table_set.hpp"

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
    int shortestDistance;
    Vertex<T>* parent;

    HashTableSet<Vertex<T>*> adjList;

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

    void SetParent(Vertex<T>* parent) {
        this->parent = parent;
    }

    Vertex<T>* GetParent(void) {
        return this->parent;
    }

    void SetShortestDistance(int shortestDistance) {
        this->shortestDistance = shortestDistance;
    }

    int SetShortestDistance(void) {
        return this->SetShortestDistance;
    }

    void AddEdgeTo(Vertex<T>* tobeInsertedVertex) {
        Pair<Vertex<T>*> tobeInsertedPair;

        if(NULL != tobeInsertedVertex) {
            tobeInsertedPair.SetKey(tobeInsertedVertex->GetIdx());
            tobeInsertedPair.SetItem(tobeInsertedVertex);
            adjList.Insert(tobeInsertedPair);
        } else {
            /* DO NOTHING */
        }
    }

    VertexIter<Vertex<T>*> Begin(void) {
        VertexIter<Vertex<T>*> begin = VertexIter<Vertex<T>*>(adjList.Begin());
        return begin;
    }

    VertexIter<Vertex<T>*> End(void) {
        VertexIter<Vertex<T>*> end = VertexIter<Vertex<T>*>(adjList.End());
        return end;
    }

    bool HasEdgeTo (int idx) {
        bool res;
        Pair<Vertex<T>*> found = adjList.Find(idx);

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
};