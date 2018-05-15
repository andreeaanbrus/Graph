//
// Created by Andreea on 3/7/2018.
//
#include "graph.h"
#include <iostream>
#include <algorithm>


Graph::Graph(int _NrVertices){
    NrVertices = _NrVertices;
    NrEdges = 0;
    Edges = std::vector <Edge>(0);
}

Graph::~Graph() = default;

int Graph::getNrVertices(){
    //getter for the number of vertices
    return NrVertices;
}

int Graph::getNrEdges() {
    return NrEdges;
}

void Graph::setNrVertices(int value){
    //setter for the number of vertices
    NrVertices = value;
}

int Graph::setNrEdges(int value) {
    this -> NrEdges = value;
}

void Graph::addEdge(const Edge& _edge){

    Edges.push_back(_edge);
    NrEdges ++;
}

void Graph::removeEdge(const Edge& _edge){
    /*removes an edge from the graph
     * */
    if(std::find(Edges.begin(), Edges.end(), _edge) != Edges.end()){
        Edges.erase(std::find(Edges.begin(), Edges.end(), _edge));
        NrEdges --;
    }

}
void Graph::print() const{
    /*
     * printing the graph
     * */
    for (const Edge &e: Edges)
        e.printEdge();
}

void Graph::removeAll(){
    /*
     * removes everything in the graph
     * used when reading a new file
     * */
    NrVertices = 0;
    Edges.clear();
}

void Graph::changeCost(int start, int stop, int cost)
{
    /*
     * changes the cost of an edge
     * start = the starting point
     * stop = the end point
     * */
    bool found = false;
    Edge ed = Edge(start, stop, cost);
    for(Edge& e : Edges){
        if (e == ed)
            e.setCost(cost), found = true;
    }
    if(!found)
        throw "Invalid edge!";

}

Graph::Graph(const Graph &g) {
    this -> NrVertices = g.NrVertices;
    this -> NrEdges = g.NrEdges;
    this -> Edges = g.Edges;
}



