//
// Created by david on 5/8/23.
//

#ifndef PROJECT_2_CPHEADQUARTERS_H
#define PROJECT_2_CPHEADQUARTERS_H


#include "Graph.h"
#include "Establishment.h"

class CPheadquarters {
    Graph graph;
    unordered_map<string, Establishment> stations;
public:

    void read_edges(std::string path);

    void read_establishments(std::string path);


    Graph getGraph() const;

    /**
     * Initial part of the algorithm, finds the route of the vertex with the given id, calling the recursive function
     * @param route
     * @param nodesVisited
     * @param totalDistance
     * @param id
     */
    void heuristic(string path[], unsigned int &nodesVisited, double &totalDistance, string id);

    /**
     * Recursive part of the heuristic that looks for the closest vertex to the actual one,
     * the closest vertex is determine using the angle, so this heuristic uses geological information from the vertex
     * @param v
     * @param route
     * @param currentIndex
     * @param distance
     * @param nodesVisited
     * @param totalDistance
     * @attention the time complexity of this part of the heuristic is O(E)
     */
    void heuristicRec(Vertex *v, string path[], unsigned int currentIndex, double distance, unsigned int &nodesVisited, double &totalDistance);

    /**
     * Iterates through all vertex to determine with which one to starts
     * @note this algorithm only work when it starts in some specifics vertex
     * so that's the reason it needs to go through all possible nodes to choose the one who satisfies the needs of the problem
     * @attention since this parte of the heuristic iterates through all vertex and call the recursive part from the algorithm that is O(E) the time complexity is O(EV)
     */
    void chooseRoute();


    /**
     * Use a backtracking exhaustive approach for TSP
     * Applicable only for very small graphs
     */
    void backtrack();

    void hamiltonianCycle();
};


#endif //PROJECT_2_CPHEADQUARTERS_H
