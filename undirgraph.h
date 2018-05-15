//
// Created by andreea on 19.04.2018.
//

#ifndef GRAPH_UNDIRGRAPH_H
#define GRAPH_UNDIRGRAPH_H


#include "graph.h"

class Undirgraph : public Graph{
private:
    std::vector <std::vector<int> > Neighbour;
public:
    Undirgraph() = default;
    Undirgraph(int NrVerices);
    void readFromFile(std::string s);
    ~Undirgraph() override{} ;
    void addIntoList(Edge e);
    std::vector<int> getNeighbour(int vertex);
    void setNeighbour(int n);

};


#endif //GRAPH_UNDIRGRAPH_H
