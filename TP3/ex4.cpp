// Original code by Gonçalo Leão
// Updated by DA 2024/2025 Team

#include "../data_structures/Graph.h"
#include "../data_structures/MutablePriorityQueue.h"

using namespace std;

/*This method implements the Dijkstra algorithm to find the shortest paths from s (vertex
 *which contains element origin) to all other vertices, in a given weighted graph (see
 *theoretical class slides). Update the Vertex class with member variables int dist and
 *Vertex<T>* path, representing the distance to the start vertex and the previous vertex in
 *the shortest path, respectively. Since the STL doesn’t support mutable priority queues,
 *you can use the class provided MutablePriorityQueue.
 */

template <class T>
bool relax(Edge<T> *edge) { // d[u] + w(u,v) < d[v]
    // TODO
    // Check if the distance is better (smaller) and update it
    // Adjacent edges to u
    // for (int v = 0; v < N; v++) { //N: size of G
    //     if (G[u][v]) // Como está implementado o grafo?!! >>>> class!! methods and attributes
    // }

    if (edge->getOrig()->getDist() + edge->getWeight() < edge->getDest()->getDist()) {
        edge->getDest()->setDist(edge->getOrig()->getDist() + edge->getWeight());
        edge->getDest()->setPath(edge);
        return true;
    }
    return false;
}

template <class T>
void dijkstra(Graph<T> * g, const int &origin) {
    // TODO
    // Input: graph, origin

    // Initialization
    for (auto v : g -> getVertexSet()) {
        v->setDist(INF);
        v->setPath(nullptr);
    }
    auto s = g->findVertex(origin);
    s->setDist(0);
    MutablePriorityQueue<Vertex<T>> *q; // Provided class
    q->insert(s);

    while (!q->empty()) { // (.) giving error
        Vertex<T> *v = q->extractMin();
        for (auto e : v->getAdj()) {
            int oldDist = e->getDest()->getDist(); // int? edge?
            if (relax(e)) { // true/false
                if (oldDist == INF) q->insert(e->getDest());
                else q->decreaseKey(e->getDest()); // dest??
            }
        }
    }
    return;
    // Output: none; cada vértice com uma dist min path atualizada
}

template <class T>
static std::vector<T> getPath(Graph<T> * g, const int &origin, const int &dest) {
    std::vector<T> res;
    // TODO


    return res;
}

/// TESTS ///
#include <gtest/gtest.h>
#include <chrono>

template <class T>
 static void checkAllPaths(Graph<T> &g, std::string expected) {
    std::stringstream ss;
    std::vector<Vertex<T> *> vs = g.getVertexSet();
    for(unsigned int i = 0; i < vs.size(); i++) {
        ss << vs[i]->getInfo() << "<-";
        if ( vs[i]->getPath() != nullptr ) {
            ss << vs[i]->getPath()->getOrig()->getInfo();
        }
        ss << "|";
    }
    EXPECT_EQ(expected, ss.str());
}


static void checkSinglePath(std::vector<int> path, std::string expected) {
    std::stringstream ss;
    for(unsigned int i = 0; i < path.size(); i++) {
        ss << path[i] << " ";
    }
    EXPECT_EQ(expected, ss.str());
}

TEST(TP3_Ex4, test_dijkstra) {
    Graph<int> myGraph;

    for(int i = 1; i <= 7; i++)
        myGraph.addVertex(i);

    myGraph.addEdge(1, 2, 2);
    myGraph.addEdge(1, 4, 7);
    myGraph.addEdge(2, 4, 3);
    myGraph.addEdge(2, 5, 5);
    myGraph.addEdge(3, 1, 2);
    myGraph.addEdge(3, 6, 5);
    myGraph.addEdge(4, 3, 1);
    myGraph.addEdge(4, 5, 1);
    myGraph.addEdge(4, 6, 6);
    myGraph.addEdge(4, 7, 4);
    myGraph.addEdge(5, 7, 2);
    myGraph.addEdge(6, 4, 3);
    myGraph.addEdge(7, 6, 4);

    dijkstra(&myGraph, 3);
    checkAllPaths(myGraph, "1<-3|2<-1|3<-|4<-2|5<-4|6<-3|7<-5|");

    dijkstra(&myGraph, 1);
    checkAllPaths(myGraph, "1<-|2<-1|3<-4|4<-2|5<-4|6<-4|7<-5|");
    checkSinglePath(getPath(&myGraph, 1, 7), "1 2 4 5 7 ");

    dijkstra(&myGraph,5);
    checkSinglePath(getPath(&myGraph, 5, 6), "5 7 6 ");

    dijkstra(&myGraph, 7);
    checkSinglePath(getPath(&myGraph, 7, 1), "7 6 4 3 1 ");

}