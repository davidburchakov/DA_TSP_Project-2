//
// Created by david on 5/8/23.
//

#ifndef PROJECT_2_GRAPH_H
#define PROJECT_2_GRAPH_H


#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>


#include "VertexEdge.h"

class Graph {
public:
    ~Graph();

    /**
    * Auxiliary function to find a vertex with a given ID.
    * @param id
    * @return vertex pointer to vertex with given content, or nullptr if not found
    */
    Vertex *findVertex(const std::string &id) const;

    /**
     *  Adds a vertex with a given content or info (in) to a graph (this).
     * @param id
     * @return true if successful, and false if a vertex with that content already exists.
     */
    bool addVertex(const std::string &id);

    /**
     * Adds an edge to a graph (this), given the contents of the source and
     * destination vertices and the edge weight (w).
     * @param sourc
     * @param dest
     * @param w
     * @return true if successful, and false if the source or destination vertex does not exist.
     */
    bool addEdge(const std::string &sourc, const std::string &dest, double d);




    [[nodiscard]] int getNumVertex() const;

    [[nodiscard]] std::vector<Vertex *> getVertexSet() const;

    /**
     * prints the graph
     */
    void print() const;



    bool TSP(std::vector<Vertex *> &shortestPath, double &shortestPathCost);


    bool hasHamiltonianCycle(std::vector<Vertex *> &path, double &pathCost);

protected:
    std::vector<Vertex *> vertexSet;    // vertex set

    double **distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall



    bool isIn(std::string n, std::vector<std::string> vec);

    /**
     * delete a vertex from the graph, making a subgraph from a graph
     * @param name
     */
    void deleteVertex(std::string name);

    double getPathCost(const std::vector<Vertex *> &path);

    bool TSPUtil(Vertex *v, std::vector<Vertex *> &path, std::vector<Vertex *> &shortestPath, double &shortestPathCost,
                 int &numOfPossiblePaths);

    double hasHamiltonianCycleUtil(Vertex *v, std::vector<Vertex *> &path, double &pathCost);
};

void deleteMatrix(int **m, int n);

void deleteMatrix(double **m, int n);


#endif //PROJECT_2_GRAPH_H
