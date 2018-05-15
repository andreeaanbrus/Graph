//
// Created by andreea on 19.04.2018.
//

#include <fstream>
#include <queue>
#include "undirgraph.h"

void Undirgraph::setNeighbour(int n) {
    Neighbour = std::vector<std::vector<int> >((unsigned int)n, std::vector<int>());

}

void Undirgraph::addIntoList(Edge e) {
    Neighbour[(unsigned int)e.getStart()].push_back(e.getStop());
}

std::vector<int> Undirgraph::getNeighbour(int vertex) {
    return Neighbour[vertex];
}

void Undirgraph::readFromFile(std::string s) {
    /* reads graph from file
     * s is the name of the file
     */
    std::ifstream fin;
    fin.open(s);
    int start, stop, cost=0, n = 100 ,m=10;
    fin >> n >> m;
    setNrVertices(n);
    setNeighbour(n);
    for(int i = 0; i < m; i++){
        fin >> start >> stop >> cost;
        addEdge(Edge(start, stop, cost));
        addEdge(Edge(stop, start, cost));
        addIntoList(Edge(start, stop, cost));
        addIntoList(Edge(stop, start, cost));
    }

    fin.close();
}

Undirgraph::Undirgraph(int NrVerices) : Graph(NrVerices) {
    Neighbour = std::vector<std::vector<int> >((unsigned int)NrVerices, std::vector<int>());

}