//
// Created by Andreea on 3/5/2018.
//

#include <iostream>
#include "edge.h"

Edge::Edge(int _start, int _stop, int _cost){
    start = _start;
    stop = _stop;
    cost = _cost;
}
//Destructor
Edge::~Edge() = default;

//Getter
void Edge::setStart(int _start){
    start = _start;
}
int Edge::getStart() const{
    return start;
}
void Edge::setStop(int _stop){
    stop = _stop;
}
int Edge::getStop() const{
    return stop;
}
void Edge::setCost(int _cost){
    cost = _cost;
}
int Edge::getCost() const{
    return cost;
}

bool Edge::operator == (const Edge& _edge) const{
    //overloading == operator
    //for find function
    return start == _edge.getStart() && _edge.getStop() == stop;
}

bool Edge::operator < (const Edge& _edge) const{
    //overloading the < operator
    if (cost == _edge.getCost())
        return cost < _edge.getCost();
    if (start == _edge.getStart())
        return start < _edge.getStart();
    return cost < _edge.getCost();
}

void Edge::printEdge() const {
    //printing for debugging
    std :: cout << start << ' ' << stop << ' ' << cost << '\n';
}

