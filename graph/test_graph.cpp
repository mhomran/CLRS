#include "graph.hpp"

template<size_t Size, class T>
constexpr size_t SizeOfArray(T(&Array)[Size]) { return Size; }

int main() {
    size_t i;
    Graph<char> graph;
    Vertex<char> vertices[4];
    DynamicArraySeq<Vertex<char>*> shortestPath;

    for(i = 0; i < SizeOfArray(vertices); i++) {
        vertices[i].SetIdx(i);
        vertices[i].SetItem(i + 'a');
        graph.InsertVertex(&vertices[i]);
    }

    vertices[0].AddEdgeTo(&vertices[1]);
    vertices[1].AddEdgeTo(&vertices[2]);
    vertices[1].AddEdgeTo(&vertices[3]);
    vertices[2].AddEdgeTo(&vertices[3]);

    cout << "The graph has vertices:\n";
    for(auto vIter = graph.Begin(); vIter != graph.End(); vIter++) {
        cout << *(*vIter) << endl;
    }

    cout << "The first vertex (0,a) is connected to:\n";
    for(auto adjListIter = vertices[0].Begin(); adjListIter != vertices[0].End(); adjListIter++) {
        cout << (*adjListIter)->GetItem() << endl;
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
        cout << vertices[i] << " has a parent: ";
        cout << *vertices[i].GetParent() << endl;
    }

    cout << "The shortest path is:\n";
    for(auto vPtr = shortestPath.Begin(); vPtr != shortestPath.End(); vPtr++) {
        cout << **vPtr << " ";
    }
    cout << endl;
}