//
// Created by andreea on 10.05.2018.
//

#ifndef GRAPH_DAG_H
#define GRAPH_DAG_H


#include "digraph.h"

class DAG {
public:
    static std::vector<int> topologicalSort(DirGraph &G);
    static int highestCostPath(DirGraph&G, int start, int stop);
};


#endif //GRAPH_DAG_H
