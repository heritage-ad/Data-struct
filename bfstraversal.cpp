/* Program name: BFS Traversal
Author: Heritage Adigun
Date last updated: 11/04/2024
Purpose: A program that outputs the nodes of a graph in a breadth-first traversal.*/

#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph {
    int numVertices;
    vector<list<int>> adjList;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(numVertices);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
    }

    void BFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> bfsQueue;

        visited[startVertex] = true;
        bfsQueue.push(startVertex);

        while (!bfsQueue.empty()) {
            int currVertex = bfsQueue.front();
            bfsQueue.pop();

            cout << currVertex << " ";

            for (int neighbor : adjList[currVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    bfsQueue.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    cout << "Breadth-First Traversal: ";
    graph.BFS(0);
    cout << endl;

    return 0;
}