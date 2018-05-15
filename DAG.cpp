//
// Created by andreea on 10.05.2018.
//

#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include "Lowest_Cost_Walk.h"
#include "DAG.h"

std::vector<int> DAG::topologicalSort(DirGraph &G) {
    /*
     * Performs a topological sortin on the graph G
     * Returns the sorted vertices
     * If there exists a cycle, throw exception
     * */
    std::vector<int> sorted;
    std::queue<int> Q;
    std::unordered_map<int, int> count;
    for (int i = 0; i < G.getNrVertices(); i++) {
        count[i] = static_cast<int>(G.getDegreeIn(i));
        if (count[i] == 0)
            Q.push(i);
    }

    while(!Q.empty()) {
        int x = Q.front();
        sorted.push_back(x);
        Q.pop();
        for(auto i: G.getOutbound(x)) {
            count[i] --;
            if(count[i] == 0) {
                Q.push(i);
            }
        }
    }
    if(sorted.size() < G.getNrVertices())
        throw "Graph has a cycle!";
//    for(auto i :sorted)
//        std::cout << i << '\n';
    return sorted;
}

int DAG::highestCostPath(DirGraph &G, int start, int stop) {
    std::vector<int> sorted = topologicalSort(G);
    std::vector<int> path(static_cast<size_t >(G.getNrVertices() + 1), -1);
    path.push_back(start);
    int INF = 20000000;
    std::vector<int> distances(G.getNrVertices(), -INF);
    distances[start] = 0;
    for (auto i : sorted) {
        if (distances[i] == -INF)
            continue;
        for (auto j : G.getOutbound(i)) {
            if (distances[j] < distances[i] + G.findEdge(i, j).getCost()){
                distances[j] = distances[i] + G.findEdge(i, j).getCost();
                path[j] = i;
            }
        }
    }
    PrintPath(path, stop, stop);
    std::cout << "\n";
//    for(auto i: path)
//        std::cout << i;
//    std::cout << '\n';
    return distances[stop];
}