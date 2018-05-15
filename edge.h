//
// Created by Andreea on 3/7/2018.
//

#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H
#define inf 2147483647

class Edge {
private:
    int start;
    int stop;
    int cost;
public:
    //Constructor
    explicit Edge(int _start = -1, int _stop = -1, int _cost = inf);

    //Destructor
    ~Edge();

    //Getter

    void setStart(int _start);

    int getStart() const;

    void setStop(int _stop);

    int getStop() const;

    void setCost(int _cost);

    int getCost() const;


    bool operator==(const Edge &_edge) const;

    bool operator<(const Edge &_edge) const;

    void printEdge() const;
};


#endif //GRAPH_EDGE_H
