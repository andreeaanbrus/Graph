//
// Created by andreea on 30.04.2018.
//
#include <vector>
#include <iostream>
#include <utility>
#include <fstream>

#include "Lowest_Cost_Walk.h"

const int INF = 2000000000;

int min(int x, int y) {
    if (x < y)
        return x;
    return y;
}

bool CheckNegativeCycle(const std::vector < std::vector <int> > &d, int n) {
    //checks if there exists a negative cycle
    for (int i = 0; i < n; ++i) {
        if (d[n*n-1][i] != d[n*n-2][i])
            return true;
    }
    return false;
}
void PrintPath(std::vector <int>& Path, int current, int stop) {
    //prints the path recursively from a current node to stop
    if (Path[current] == -1 || Path[current] == current){
        std::cout << current << " -> ";
        return;
    }
    PrintPath(Path, Path[current], stop);
    std::cout << current;
    if (current != stop) {
        std::cout << " -> ";
    }
}

void Lowest_Cost_Walk::LowestCostWalk(DirGraph &g, const int &start, const int &stop) {
    // d[x,k]=the cost of the lowest cost walk from s to x and of length equal to k, where s is the starting vertex.
    int n = g.getNrVertices();
    std::vector <std::vector <int> > d(static_cast<unsigned long>((n-1) * (n-1)), std::vector <int> (n , INF));
    d[0][start] = 0;
    std::vector <int> Path(static_cast<unsigned long>(n + 1));
    for (int k = 1; k < (n-1)*(n-1); ++k) {    // k iterations
        for (int x = 0; x < n; ++x) {  // x current node
            int best_from_outside = INF;
            for (auto &y  : g.getInbound(x)) { // y neighbor {node, cost}
                if (best_from_outside > d[k-1][y] + g.findEdge(y, x).getCost()) {
                    best_from_outside = d[k-1][y] + g.findEdge(y, x).getCost();
                    Path[x] = y;
                }
            }
            if (best_from_outside > d[k-1][x]) {
                Path[x] = x;
            }
            d[k][x] = min(d[k-1][x], best_from_outside);
        }
    }
//
//    for (const auto &i : d) {
//        for (auto j : i) {
//            if (j == INF) {
//                std::cout << "INF" << ' ';
//            } else
//                std::cout << j << ' ';
//        }
//        std::cout << '\n';
//    }
//

    if (CheckNegativeCycle(d, n-1)) {
        throw "Negative cycle!";
    }
    if (d[(n-1) * (n-1) - 1][stop] == INF) {
        throw "No path from start to stop!";
    }
    std::cout << "The cost is: " << d[n-1][stop];
    std::cout << '\n';
    PrintPath(Path, stop, stop);
    std::cout << '\n';
}