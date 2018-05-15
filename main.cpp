#include <iostream>
#include "graph.h"
#include "edge.h"
#include "digraph.h"
#include "ConectedComponents.h"
#include "Lowest_Cost_Walk.h"
#include "DAG.h"

using namespace std;

//void printMenu();
//
//int main() {
//    int command = 0;
//    DirGraph g(0);
//
//    while (true) {
//        try {
//            printMenu();
//            cin >> command;
//            if (command == 0)
//                return false;
//
//            if (command == 1) {
//                g.removeAll();
//                std::cout << "Give the number of vertices n= ";
//                int n, m, start, stop, cost;
//                std::cin >> n;
//                g.setNrVertices(n);
//                g.setVertexIn(n);
//                g.setVertexOut(n);
//                std::cout << "Give the number of edges m= ";
//                std::cin >> m;
//                for (int i = 0; i < m; i++) {
//                    std::cout << "Give the start vertex, the stop vertex and the cost of the edge";
//                    std::cin >> start;
//                    std::cin >> stop;
//                    std::cin >> cost;
//                    g.addEdge(Edge(start, stop, cost));
//                    g.addIntoList(Edge(start, stop, cost));
//                }
//            }
//
//            if (command == 2) {
//                g.removeAll();
//                std::string s = "graph.txt";
////            std::cout << "Give the file name\n";
////            cin>>s;
//                g.readFromFile(s);
//            }
//
//            if (command == 3)
//                g.print();
//
//            if (command == 4)
//                std::cout << g.getNrVertices() << '\n';
//
//            if (command == 5) {
//                int start, stop, cost;
//                std::cout << "The starting point: ";
//                std::cin >> start;
//                std::cout << "The ending point: ";
//                std::cin >> stop;
//                std::cout << "The new cost: ";
//                std::cin >> cost;
//                g.changeCost(start, stop, cost);
//                std::cout << "The change was made!\n";
//            }
//            if (command == 6) {
//                int start, stop;
//                std::cout << "Give the start vertex: ";
//                std::cin >> start;
//                std::cout << "Give the stop vertex: ";
//                std::cin >> stop;
//                g.findEdge(start, stop).printEdge();
//                if (g.findEdge(start, stop) == Edge(-1, -1, -1))
//                    std::cout << "There is not an edge between the given vertices\n";
//                else
//                    std::cout << "There is an edge between the given vertices\n";
//            }
//            if (command == 7) {
//                int vertex;
//                std::cout << "Give the vertex: ";
//                std::cin >> vertex;
//                unsigned long degreeIn = g.getDegreeIn(vertex);
//                unsigned long degreeOut = g.getDegreeOut(vertex);
//                std::cout << "The degree in is: " << degreeIn << " The degree out is: " << degreeOut << '\n';
//            }
//            if (command == 8) {
//                int vertex;
//                std::cout << "Give the vertex: ";
//                std::cin >> vertex;
//                //inbound
//                Iterator inbound(g, vertex, 1);
//                Iterator outbound(g, vertex, -1);
//                std::cout << "The inbound of the vertex: ";
//                while (inbound.valid()) {
//                    std::cout << inbound.getCurrent() << ' ';
//                    inbound.next();
//                }
//                std::cout << '\n';
//                std::cout << "The outbound of the vertex: ";
//                while (outbound.valid()) {
//                    std::cout << outbound.getCurrent() << ' ';
//                    outbound.next();
//                }
//                std::cout << '\n';
//            }
//            if (command == 9) {
//                Undirgraph g1(0);
//                g1.removeAll();
//                std::string filename;
//                std::cout << "Give the file name: ";
//                std::cin >> filename;
//                g1.readFromFile(filename);
//                std::vector<int> components = ConectedComponents::BFSConnectedComponents(g1);
//                for (int i = 0; i < ConectedComponents::BFSConnectedComponents(g1).size(); i++)
//                    std::cout << i << " is in the component nr " << ConectedComponents::BFSConnectedComponents(g1)[i]
//                              << '\n';
//                std::cout << "\n";
//                std::vector<int> components1 = ConectedComponents::DFSConnectedComponents(g1);
//                for (int i = 0; i < ConectedComponents::DFSConnectedComponents(g1).size(); i++)
//                    std::cout << i << " is in the component nr " << ConectedComponents::DFSConnectedComponents(g1)[i]
//                              << '\n';
//                std::cout << "\n";
//
//            }
//            if (command == 10) {
//                int start, stop;
//                std::cout << "Give the start vertex: ";
//                std::cin >> start;
//                std::cout << "Give the stop vertex: ";
//                std::cin >> stop;
//                if(start >= g.getNrVertices() || start < 0)
//                    throw "Invalid start";
//                if(stop >= g.getNrVertices() || stop < 0)
//                    throw "Invalid stop";
//                Lowest_Cost_Walk::LowestCostWalk(g, start, stop);
//            }
//        }
//
//        catch (const char *s) {
//            std::cout << s << '\n';
//        }
//    }
//}
//
//void printMenu() {
//
//    std::cout << "1 -> Read graph from console\n";
//    std::cout << "2 -> Read graph from file\n";
//    std::cout << "3 -> Print graph\n";
//    std::cout << "4 -> Get the number of vertices\n";
//    std::cout << "5 -> Modify the cost of an edge\n";
//    std::cout << "6 -> Check if there is an edge between 2 vertices\n";
//    std::cout << "7 -> Get degree in and degree out of a vertex\n";
//    std::cout << "8 -> Get the inboud and outbound of a vertex\n";
//    std::cout << "9 -> Read undirected graph and see connected components\n";
//    std::cout << "10 -> Find the lowest cost walk between 2 vertices\n";
//    std::cout << "0 -> Exit\n";
//
//}
int main() {
    DirGraph G;
    G.readFromFile("DAG2.txt");
    // am schimbat in cod
    std::vector<int> v = DAG::topologicalSort(G);
    std::cout << DAG::highestCostPath(G, 1 ,3);
    return 0;
}