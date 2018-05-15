//
// Created by andreea on 20.04.2018.
//

#include "ConectedComponents.h"
#include <queue>
void ConectedComponents::BFS(Undirgraph g, int vertex, std::vector<int> &visited, int cnt) {
    {
        /*
         * The Breadth First Search Aglorithm
         * If the vertex is not visited, add into the queue its unvisited adiacent vertices
         * Mark as visited the vertex from the front of the queue and pop
         * */
        std::queue<int> Q;
        Q.push(vertex);
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            visited[x] = cnt;
            for (int j = 0; j != g.getNeighbour(x).size(); ++j) {
                if (visited[g.getNeighbour(x)[j]] == 0 ) {
                    Q.push(g.getNeighbour(x)[j]);
                }
            }
        }
    }
}

std::vector<int> ConectedComponents::BFSConnectedComponents(Undirgraph g) {
    /*
     * returns the visited vector -> v[index] = the number of the connected component
     */
    std::vector<int> visited;
    for(int i = 0; i < g.getNrVertices(); i++)
        visited.push_back(0);
    int cnt = 1;
    for (int i = 0; i < visited.size(); ++i) {
        if (visited[i] == 0) {
            BFS(g, i, visited, cnt);
            cnt++;
        }
    }
    return visited;
}

void ConectedComponents::DFS(Undirgraph g, int vertex, std::vector<int> &visited, int cnt) {
    visited[vertex] = cnt;
    for(int i = 0; i < g.getNeighbour(vertex).size(); i++)
        if(!visited[g.getNeighbour(vertex)[i]])
            DFS(g, g.getNeighbour(vertex)[i], visited, cnt);
}

std::vector<int> ConectedComponents::DFSConnectedComponents(Undirgraph g) {
    /*
     * returns the visited vector -> v[index] = the number of the connected component
     */
    int cnt = 1;
    std::vector<int> visited;
    for(int i = 0; i < g.getNrVertices(); i++)
        visited.push_back(0);
    for(int i = 0; i < g.getNrVertices(); i++)
        visited[i] = 0;
    for(int i = 0; i < g.getNrVertices(); i++)
        if(!visited[i])
            DFS(g, i, visited, cnt), cnt++;
    return visited;
}

