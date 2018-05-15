//
// Created by andreea on 30.04.2018.
//

#ifndef GRAPH_LOWEST_COST_WALK_H
#define GRAPH_LOWEST_COST_WALK_H

#include <vector>
#include "digraph.h"

class Lowest_Cost_Walk {
public:
    Lowest_Cost_Walk() = default;

    static void LowestCostWalk(DirGraph &g, const int &start, const int & stop);
    ~Lowest_Cost_Walk() = default;;

};

void PrintPath(std::vector <int>&, int, int);
#endif //GRAPH_LOWEST_COST_WALK_H
