#include "graph.hpp"

template<size_t Size, class T>
constexpr size_t SizeOfArray(T(&Array)[Size]) { return Size; }

int main() {
    size_t i, j;
    Graph<char> graph;
    Vertex<char> vertices[4];
    
    for(i = 0; i < SizeOfArray(vertices); i++) {
        vertices[i].SetIdx(i);
        vertices[i].SetItem(i + 'a');
        graph.InsertVertex(&vertices[i]);
    }

    for(i = 0; i < SizeOfArray(vertices); i++) {
        for(j = 0; j < SizeOfArray(vertices); j++) {
            if(i != j) {
                vertices[i].AddEdgeTo(&vertices[j]);
            } else {
                /* DO NOTHING */
            }
        }
    }

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
}