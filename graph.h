//
// Created by Andreea on 3/7/2018.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <vector>
#include <unordered_map>
#include "edge.h"

class Graph {
private:
    int NrEdges;
    std::vector <Edge> Edges;
protected:

    int NrVertices;
public:
    explicit Graph(int _NrVertices = 0);

    virtual ~Graph();

    Graph(const Graph& g);

    int getNrVertices();

    int getNrEdges();

    void setNrVertices(int value);

    int setNrEdges(int value);

    void addEdge(const Edge &_edge);

    void removeEdge(const Edge &_edge);

    void print() const;

    void removeAll();

    virtual void changeCost(int start, int stop, int cost);


};


#endif //GRAPH_GRAPH_H
