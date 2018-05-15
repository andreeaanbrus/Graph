//
// Created by andreea on 20.04.2018.
//

#ifndef GRAPH_CONECTEDCOMPONENTS_H
#define GRAPH_CONECTEDCOMPONENTS_H


#include "undirgraph.h"

class ConectedComponents {
public:
    ConectedComponents(){};
    static void BFS(Undirgraph g, int vertex, std::vector<int> &visited, int cnt);
    static std::vector<int> BFSConnectedComponents(Undirgraph g);
    static void DFS(Undirgraph g, int vertex, std::vector<int> &visited, int cnt);
    static std::vector<int> DFSConnectedComponents(Undirgraph g);
    ~ConectedComponents();
};


#endif //GRAPH_CONECTEDCOMPONENTS_H
