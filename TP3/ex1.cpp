// Original code by Gonçalo Leão
// Updated by DA 2024/2025 Team
// Amanda Araujo Silva

#include "MSTTestAux.h"
#include "../data_structures/Graph.h"

// Prim Algorithm: Minimum Spanning Trees
// prim(g)
/*      pick a vertex s to initiate the tree
 *      while there are vertex outside the tree
 *          pick a safe edge
 *          insert the edge and vertex at the tree
 *
 * Priority line: keep all the vertex outside the tree
 */

template <typename T> //T: template parameter, indicates function can work with any type
std::vector<Vertex<T> *> prim(Graph<T> *g) {
    // Input: takes a pointer to a Graph<T>
    // Return: vector in C++ of pointers to Vertex<T>

    // TODO
    // Empty Graph; No vertex
    if(g->getVertexSet().empty()) return g->getVertexSet();

    // Initialization
    for (const auto v : g->getVertexSet()) {
        // For each vertex um the graph
        v->setDist(INF);
        v->setPath(nullptr);
        v->setVisited(false);
    }

    // Start vertex: pick an arbitrary vertex
    Vertex<T> * s; // Variable declaration
    s = g->getVertexSet().front(); // Gets the first vertex
    s ->setDist(0); // Distance zero from itself

    // Initializing priority queue (fila de prioridade)
    MutablePriorityQueue<Vertex<T> q; // Variable declaration !!!
    q.insert(s);

    // Processing node in the queue
    while (!q.empty()) { // While not empty
        v = q.extrac()

    }

    return g->getVertexSet();
}

/// TESTS ///
#include <gtest/gtest.h>
#include <chrono>

TEST(TP3_Ex1, test_prim) {
    Graph<int> graph = createMSTTestGraph<int>();
    std::vector<Vertex<int> *> res = prim(&graph);

    std::stringstream ss;
    for(const auto v : res) {
        ss << v->getInfo() << "<-";
        if ( v->getPath() != nullptr ) {
            ss << v->getPath()->getOrig()->getInfo();
        }
        ss << "|";
    }
    std::cout << ss.str() << std::endl;

    EXPECT_TRUE(isSpanningTree(res));
    EXPECT_EQ(spanningTreeCost(res), 11);
}

TEST(TP3_Ex1_performance, test_performance_prim) {
    //Change these const parameters as needed
    const int MIN_SIZE = 10;
    const int MAX_SIZE = 30; //Try with 100
    const int STEP_SIZE = 10;
    const int N_REPETITIONS = 50;
    for (int n = MIN_SIZE; n <= MAX_SIZE; n += STEP_SIZE) {
        Graph<int> g;
        generateRandomGridGraph(n, g);
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i <= N_REPETITIONS; i++)
            prim(&g);
        auto finish = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
        std::cout << "Processing grid (Prim) " << n << " x " << n << " average time (milliseconds)=" << (elapsed / N_REPETITIONS) << std::endl;
    }
}
