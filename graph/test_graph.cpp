#include "graph.hpp"

template<size_t Size, class T>
constexpr size_t SizeOfArray(T(&Array)[Size]) { return Size; }

int main() {
    size_t i;
    Graph<char> graph;
    Vertex<char> vertices[5];
    Graph<int> largeGraph;
    Vertex<int> largeGraphVertices[9];
    Graph<char> DAG;
    Vertex<char> DAGVertices[4];
    DynamicArraySeq<Vertex<char>*> shortestPath;
    DynamicArraySeq<Vertex<int>*> shortestPath2;
    DynamicArraySeq<DynamicArraySeq<Vertex<char>*>> connectedComponents;
    bool isReachable, isDAG, hasPostiveWeights, hasNegativeCycle;

    for(i = 0; i < SizeOfArray(vertices); i++) {
        vertices[i].SetItem(i + 'a');
        graph.InsertVertex(&vertices[i]);
    }

    vertices[0].AddEdgeTo(&vertices[1], 20);
    vertices[1].AddEdgeTo(&vertices[2], 10);
    vertices[1].AddEdgeTo(&vertices[3], -5);
    vertices[2].AddEdgeTo(&vertices[3], -16);
    vertices[3].AddEdgeTo(&vertices[0], -15);

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
    shortestPath.Clean();
    isReachable = graph.UnweightedShortestPath(&vertices[0], &vertices[3], shortestPath);

    if(isReachable) {
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
    } else {
        cout << "The distantion is not reachable !" << endl;
    }

    cout << "Test UnweightedShortestPath from 0 to 4\n";
    shortestPath.Clean();
    isReachable = graph.UnweightedShortestPath(&vertices[0], &vertices[4], shortestPath);

    if(isReachable) {
        cout << "The distantion is reachable." << endl;
    } else {
        cout << "The distantion is not reachable !" << endl;
    }


    cout << "The connected components are:\n";
    connectedComponents = graph.GetConnectedComponents();
    
    i = 0;
    for(auto cc = connectedComponents.Begin(); cc != connectedComponents.End(); cc++, i++) {
        cout << "component #" << i << ":\n";

        auto ccTemp = *cc;
        /* Watch out as you could create different temporary sequences with *cc */
        for(auto vIter = ccTemp.Begin(); vIter != (ccTemp.End()); vIter++) {
            cout << **vIter << endl;
        }
    }

    cout << endl;
    cout << "Test the DAG relaxation on a cyclic graph \n";
    shortestPath.Clean();
    isDAG = graph.DAGRelaxation(&vertices[0], &vertices[3], shortestPath);
    if(isDAG) {
        cout << "The shortest path is:\n";
        for(auto vPtr = shortestPath.Begin(); vPtr != shortestPath.End(); vPtr++) {
            cout << **vPtr << " ";
        }
        cout << endl;
    } else {
        cout << "The graph is not a DAG !" << endl;
    }

    cout << endl << "Let's make a DAG" << endl;
    
    for(i = 0; i < SizeOfArray(DAGVertices); i++) {
        DAGVertices[i].SetItem(i + 'a');
        DAG.InsertVertex(&DAGVertices[i]);
    }

    DAGVertices[0].AddEdgeTo(&DAGVertices[1], 20);
    DAGVertices[0].AddEdgeTo(&DAGVertices[2], 10);
    DAGVertices[1].AddEdgeTo(&DAGVertices[3], 5);
    DAGVertices[2].AddEdgeTo(&DAGVertices[3], 5);

    cout << endl;
    cout << "Test the DAG relaxation on a DAG\n";
    shortestPath.Clean();
    isDAG = DAG.DAGRelaxation(&DAGVertices[0], &DAGVertices[3], shortestPath);
    if(isDAG) {
        cout << "The graph is a DAG." << endl;

        cout << "The shortest path is:\n";
        for(auto vPtr = shortestPath.Begin(); vPtr != shortestPath.End(); vPtr++) {
            if(NULL != *vPtr) cout << **vPtr << endl;
            else cout << "NULL !" << endl;
        }
        cout << endl;
    } else {
        cout << "The graph is not a DAG !" << endl;
    }

    cout << "check if the graph has a negative weighted cycle\n";
    shortestPath.Clean();
    hasNegativeCycle = DAG.BellmanFord(&DAGVertices[0], &DAGVertices[3], shortestPath);
    
    if(hasNegativeCycle) {
        cout << "The graph has a negative weighted cycle\n";
    } else {
        cout << "The graph doesn't have a negative weighted cycle\n";
        for(auto vPtr = shortestPath.Begin(); vPtr != shortestPath.End(); vPtr++) {
            if(NULL != *vPtr) cout << **vPtr << endl;
            else cout << "NULL !" << endl;
        }
        cout << endl;
    }

    cout << endl << "Test dijkstra on the DAG:" << endl;
    
    shortestPath.Clean();
    hasPostiveWeights = DAG.Dijkstra(&DAGVertices[0], &DAGVertices[3], shortestPath);
    
    if(!hasPostiveWeights) {
        cout << "The graph has negative weights !!" << endl;
    } else {
        cout << "The shortest path is:\n";
        for(auto vPtr = shortestPath.Begin(); vPtr != shortestPath.End(); vPtr++) {
            if(NULL != *vPtr) cout << **vPtr << endl;
            else cout << "NULL !" << endl;
        }
        cout << endl;
    }

    cout << endl << "Test dijkstra on the graph:" << endl;
    
    shortestPath.Clean();
    hasPostiveWeights = DAG.Dijkstra(&DAGVertices[0], &DAGVertices[3], shortestPath);
    
    if(!hasPostiveWeights) {
        cout << "The graph has negative weights !!" << endl;
    } else {
        cout << "The shortest path is:\n";
        for(auto vPtr = shortestPath.Begin(); vPtr != shortestPath.End(); vPtr++) {
            if(NULL != *vPtr) cout << **vPtr << endl;
            else cout << "NULL !" << endl;
        }
        cout << endl;
    }

    cout << endl << "Test dijkstra on the large graph:" << endl;
    

    for(i = 0; i < SizeOfArray(largeGraphVertices); i++) {
        largeGraphVertices[i].SetItem(i);
        largeGraph.InsertVertex(&largeGraphVertices[i]);
    }

    largeGraphVertices[0].AddEdgeTo(&largeGraphVertices[1], 4);
    largeGraphVertices[0].AddEdgeTo(&largeGraphVertices[7], 8);
    
    largeGraphVertices[1].AddEdgeTo(&largeGraphVertices[0], 4);
    largeGraphVertices[1].AddEdgeTo(&largeGraphVertices[2], 8);
    largeGraphVertices[1].AddEdgeTo(&largeGraphVertices[7], 11);
    
    largeGraphVertices[2].AddEdgeTo(&largeGraphVertices[8], 2);
    largeGraphVertices[2].AddEdgeTo(&largeGraphVertices[3], 7);
    largeGraphVertices[2].AddEdgeTo(&largeGraphVertices[1], 8);
    
    largeGraphVertices[3].AddEdgeTo(&largeGraphVertices[5], 14);
    largeGraphVertices[3].AddEdgeTo(&largeGraphVertices[2], 7);
    largeGraphVertices[3].AddEdgeTo(&largeGraphVertices[4], 9);
 
    largeGraphVertices[4].AddEdgeTo(&largeGraphVertices[3], 9);
    largeGraphVertices[4].AddEdgeTo(&largeGraphVertices[5], 10);

    largeGraphVertices[5].AddEdgeTo(&largeGraphVertices[2], 4);
    largeGraphVertices[5].AddEdgeTo(&largeGraphVertices[3], 14);
    largeGraphVertices[5].AddEdgeTo(&largeGraphVertices[6], 2);
    largeGraphVertices[5].AddEdgeTo(&largeGraphVertices[4], 10);

    largeGraphVertices[6].AddEdgeTo(&largeGraphVertices[7], 1);
    largeGraphVertices[6].AddEdgeTo(&largeGraphVertices[8], 6);
    largeGraphVertices[6].AddEdgeTo(&largeGraphVertices[5], 2);

    largeGraphVertices[7].AddEdgeTo(&largeGraphVertices[0], 8);
    largeGraphVertices[7].AddEdgeTo(&largeGraphVertices[1], 11);
    largeGraphVertices[7].AddEdgeTo(&largeGraphVertices[8], 7);
    largeGraphVertices[7].AddEdgeTo(&largeGraphVertices[6], 1);

    largeGraphVertices[8].AddEdgeTo(&largeGraphVertices[2], 2);
    largeGraphVertices[8].AddEdgeTo(&largeGraphVertices[7], 7);
    largeGraphVertices[8].AddEdgeTo(&largeGraphVertices[6], 6);

    shortestPath2.Clean();
    hasPostiveWeights = largeGraph.Dijkstra(&largeGraphVertices[0], &largeGraphVertices[4], shortestPath2);
    
    if(!hasPostiveWeights) {
        cout << "The graph has negative weights !!" << endl;
    } else {
        cout << "The shortest path is:\n";
        for(auto vPtr = shortestPath2.Begin(); vPtr != shortestPath2.End(); vPtr++) {
            if(NULL != *vPtr) cout << **vPtr << endl;
            else cout << "NULL !" << endl;
        }

        cout << "check correct answers on " << endl;
        cout << "https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/" << endl;
        cout << endl;
    }

    cout << endl << "Test Johnson algorithm" << endl;
    hasNegativeCycle = largeGraph.Johnson();

    if(hasNegativeCycle) {
        cout << "The graph has a negative cycle";
    } else {
        /* DO NOTHING */
    }
}
