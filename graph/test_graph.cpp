#include "graph.hpp"

template<size_t Size, class T>
constexpr size_t SizeOfArray(T(&Array)[Size]) { return Size; }

int main() {
    size_t i;
    Graph<char> graph;
    Vertex<char> vertices[5];
    DynamicArraySeq<Vertex<char>*> shortestPath;
    DynamicArraySeq<DynamicArraySeq<Vertex<char>*>> connectedComponents;

    for(i = 0; i < SizeOfArray(vertices); i++) {
        vertices[i].SetIdx(i);
        vertices[i].SetItem(i + 'a');
        graph.InsertVertex(&vertices[i]);
    }

    vertices[0].AddEdgeTo(&vertices[1], 20);
    vertices[1].AddEdgeTo(&vertices[2], 10);
    vertices[1].AddEdgeTo(&vertices[3], -5);
    vertices[2].AddEdgeTo(&vertices[3], -1);

    cout << "The graph has vertices:\n";
    for(auto vIter = graph.Begin(); vIter != graph.End(); vIter++) {
        cout << *(*vIter) << endl;
    }

    cout << "The first vertex (0,a) is connected to:\n";
    for(auto adjListIter = vertices[0].Begin(); adjListIter != vertices[0].End(); adjListIter++) {
        cout << (*adjListIter) << endl;
    }

    cout << "Check if the first vertex has an edge to itself\n";
    if(vertices[0].HasEdgeTo(0)) {
        cout << "Vertex 0 has an edge to itself\n";
    } else {
        cout << "Vertex 0 has no edge to itself\n";
    }

    cout << "Check if the first vertex has an edge to vertex (1, b)\n";
    if(vertices[0].HasEdgeTo(1)) {
        cout << "Vertex 0 has an edge to vertex (1, b)\n";
    } else {
        cout << "Vertex 0 has no edge to vertex (1, b)\n";
    }

    cout << "Test UnweightedShortestPath from 0 to 3\n";
    shortestPath = graph.UnweightedShortestPath(&vertices[0], &vertices[3]);

    for(i = 0; i < SizeOfArray(vertices); i++) {
        if(NULL != vertices[i].GetParent()) {
            cout << vertices[i] << " has a parent: ";
            cout << *vertices[i].GetParent() << endl;
        } else {
            cout << vertices[i] << " doesn't have a parent" << endl;
        }
    }

    cout << "The shortest path is:\n";
    for(auto vPtr = shortestPath.Begin(); vPtr != shortestPath.End(); vPtr++) {
        cout << **vPtr << " ";
    }
    cout << endl;

    connectedComponents = graph.GetConnectedComponents();

    cout << "The connected components are:\n";
    
    i = 0;
    for(auto cc = connectedComponents.Begin(); cc != connectedComponents.End(); cc++, i++) {
        cout << "component #" << i << ":\n";

        auto ccTemp = *cc;
        /* Watch out as you could create different temporary sequences with *cc */
        for(auto vIter = ccTemp.Begin(); vIter != (ccTemp.End()); vIter++) {
            cout << **vIter << endl;
        }
    }
}