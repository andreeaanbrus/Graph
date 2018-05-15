//
// Created by Andreea on 3/3/2018.
//

#include "digraph.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>


DirGraph::DirGraph(int N) : Graph(N) {
    VertexIn = std::vector<std::vector<int> >((unsigned int)N, std::vector<int>());
    VertexOut = std::vector<std::vector<int> >((unsigned int)N, std::vector<int>());
}

void DirGraph::readFromFile(std::string s) {
    /* reads graph from file
     * s is the name of the file
     */
    std::ifstream fin;
    fin.open(s);
    int start, stop, cost, n = 100 ,m=10;
    fin >> n >> m;
    setNrVertices(n);
    setVertexOut(n);
    setVertexIn(n);
    for(int i = 0; i < m; i++){
        fin >> start >> stop >> cost;
        addEdge(Edge(start, stop, cost));
        addIntoList(Edge(start, stop, cost));
    }

    fin.close();
}

void DirGraph::addIntoList(Edge e) {
    /*
     * adds an edge into the vectors of neighbours
     *  adds the edge e into the map
     *  the map key is start * size + stop
     *  O(1)
     */
    this->EdgeMap[e.getStart() * this->NrVertices + e.getStop()] = e;
    VertexOut[(unsigned int)e.getStart()].push_back(e.getStop());
    VertexIn[(unsigned int)e.getStop()].push_back(e.getStart());
}

void DirGraph::setVertexOut(int nrVertices) {
    /*
     * sets the vertex out vector
     * O(1)*/
    VertexOut = std::vector<std::vector<int> >((unsigned int)nrVertices, std::vector<int>());

}

void DirGraph::setVertexIn(int nrVertices) {
    /*
     * sets the vertex in vector
     * O(1)
     * */
    VertexIn = std::vector<std::vector<int> >((unsigned int)nrVertices, std::vector<int>());
}

Edge DirGraph::findEdge(int start, int stop) {
    /*
     * input: start - the starting vertex
     *         stop = the ending vertex
     * O(deg(start)
     * output: Edge if found
     *          Edge(-1, -1, -1)
     * O(1)
     */
    Edge e  = this -> EdgeMap[start * this -> NrVertices + stop];
    return e;
}

unsigned long DirGraph::getDegreeOut(int vertex) {
    /*
     * returns the degree in of the given vertex
     * O(1)
     */
    return VertexOut[vertex].size();
}

unsigned long DirGraph::getDegreeIn(int vertex) {
    /*
     * returns the degree in of the given vertex
     * O(1)
     */
    return VertexIn[vertex].size();
}

void DirGraph::changeCost(int start, int stop, int cost) {
    /*
     * Changes the costs in the map
     * O(1);
     * */
    Graph::changeCost(start, stop, cost);
    Edge e(start, stop, cost);
    EdgeMap[start * getNrVertices() + stop] = e;
}

std::vector<int> DirGraph::getInbound(int vertex) {
    /*
     * returns the inbound of the vertex
     * O(1)
     */
    return this->VertexIn[vertex];
}

std::vector<int> DirGraph::getOutbound(int vertex) {
    /*
     * returns the inbound of the vertex
     * O(1)
     */
    return VertexOut[vertex];
}

DirGraph &DirGraph::operator=(const DirGraph& g) {
    this -> NrVertices = g.NrVertices;
    this -> VertexIn = g.VertexIn;
    this -> VertexOut = g.VertexOut;
    this -> EdgeMap = g.EdgeMap;
    return *this;
}

DirGraph::DirGraph(const DirGraph &graph) {
    this -> NrVertices = graph.NrVertices;
    this -> VertexIn = graph.VertexIn;
    this -> VertexOut = graph.VertexOut;
    this -> EdgeMap = graph.EdgeMap;
}

//int DirGraph::BFSConnectedComponents() {
//    std::queue<int> Q;
//    std::vector<int> visited;
//    for(int i = 0; i < NrVertices; i++)
//        visited.push_back(0);
//    int cnt = 0;
//    for (int i = 0; i < visited.size(); ++i) {
//        if (visited[i] == 0) {
//            BFS(i, visited);
//            cnt++;
//        }
//    }
//    return cnt;
//}
//
//void DirGraph::BFS(int vertex, std::vector<int>& visited){
//    std::queue<int> Q;
//    Q.push(vertex);
//    while (!Q.empty()) {
//        int x = Q.front();
//        Q.pop();
//        visited[x] = 1;
//        for (int j = 0; j != getOutbound(x).size(); ++j) {
//            if (visited[getOutbound(x)[j] == 0]) {
//                Q.push(getOutbound(x)[j]);
//            }
//        }
//    }
//}
//
//int DirGraph::DFSConnectedComponents() {
//    int cnt = 0;
//    int visited[NrVertices];
//    for(int i = 0; i < NrVertices; i++)
//        visited[i] = 0;
//    for(int i = 0; i < NrVertices; i++)
//        if(!visited[i])
//            DFS(i, visited), cnt++;
//    return cnt;
//}
//
//void DirGraph::DFS(int vertex, int* visited) {
//    visited[vertex] = 1;
//    for(int i = 0; i < getOutbound(vertex).size(); i++)
//        if(!visited[getOutbound(vertex)[i]])
//            DFS(getOutbound(vertex)[i], visited);
//}
//

DirGraph::DirGraph() = default ;
//    VertexIn = std::vector<std::vector<int> > (0, std::vector<int>(0));
//    VertexOut = std::vector<std::vector<int> >(0), std::vector<int>();



DirGraph::~DirGraph() = default;


int Iterator::getCurrent() {
    if(in_out == 1)
        return g.getInbound(vertex)[current];
    if(in_out == -1)
        return g.getOutbound(vertex)[current];
}

bool Iterator::valid() {
    if(in_out == 1)
        return current < g.getInbound(vertex).size();
    if(in_out == -1)
        return current < g.getOutbound(vertex).size();
}

void Iterator::next() {
    current ++;
}
