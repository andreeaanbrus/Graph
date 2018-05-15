//
// Created by Andreea on 3/7/2018.
//
#ifndef GRAPH_DIGRAPH_H
#define GRAPH_DIGRAPH_H


#include "graph.h"
#include "edge.h"
#include <algorithm>
#include <string>

class DirGraph : public Graph{
private:
    std::vector <std::vector<int> > VertexIn;
    std::vector <std::vector<int> > VertexOut;
    std::unordered_map <int, Edge> EdgeMap;
public:

    void setVertexIn(int nrVertices);

    void setVertexOut(int nrVertices);

    DirGraph();

    DirGraph(const DirGraph & graph);

    explicit DirGraph(int NrVertices);

    ~DirGraph() override;

    void readFromFile(std::string s);

    void addIntoList(Edge e);

    Edge findEdge(int, int);

    unsigned long getDegreeIn(int);

    unsigned long getDegreeOut(int);

    std::vector<int> getInbound(int);

    std::vector<int> getOutbound(int);

    void changeCost(int start, int stop, int cost);

    DirGraph &operator= (const DirGraph &g);

    int BFSConnectedComponents();

    int DFSConnectedComponents();
    void DFS(int vertex, int* visited);
    void BFS(int vertex, std::vector<int>& visited);
};

class Iterator {
private:
    DirGraph g; //& - sintaxa initializare
    int vertex;
    int in_out; // 1- inb, -1 -out
    int current;
public:
    Iterator(const DirGraph &g1, int _vertex, int _in_out) {g = g1, vertex = _vertex, in_out = _in_out, current = 0;} // varf - inbound, outbound
    int getCurrent();
    bool valid();
    void next();
};

#endif //GRAPH_DIGRAPH_H
