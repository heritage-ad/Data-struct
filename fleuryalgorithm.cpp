/* Program name: Fleury's Algorithm 
Author: Heritage Adigun
Date last updated: 11/06/2024
Purpose: A program that implements Fleury's Algorithm.*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// Graph class to represent an undirected graph
class Graph {
    int V; // Number of vertices
    list<int> *adj; // Pointer to adjacency list

public:
    Graph(int V); // Constructor
    void addEdge(int u, int v); // Function to add an edge to the graph
    void removeEdge(int u, int v); // Function to remove an edge from the graph
    void printEulerPath(); // Function to print the Eulerian path or circuit

private:
    void DFS(int v, vector<bool>& visited); // Depth-first search helper function
    bool isBridge(int u, int v); // Function to check if an edge is a bridge
    int degree(int v); // Function to get the degree of a vertex
    int findStartVertex(); // Function to find the starting vertex
};

// Constructor
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

// Function to add an edge to the graph
void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Since it's an undirected graph
}

// Function to remove an edge from the graph
void Graph::removeEdge(int u, int v) {
    adj[u].remove(v);
    adj[v].remove(u);
}

// Depth-First Search (DFS) to check connectivity
void Graph::DFS(int v, vector<bool>& visited) {
    visited[v] = true;

    for (auto i : adj[v])
        if (!visited[i])
            DFS(i, visited);
}

// Function to check if removing an edge will disconnect the graph 
bool Graph::isBridge(int u, int v) {
    // Count reachable vertices before removing edge u-v
    vector<bool> visited(V, false);
    int count1 = 0;
    DFS(u, visited);

    // Remove the edge and count reachable vertices again
    removeEdge(u, v);
    visited.assign(V, false);
    int count2 = 0;
    DFS(u, visited);

    // Re-add the edge
    addEdge(u, v);

    // Edge u-v is a bridge if the count of reachable vertices decreases
    return (count1 > count2);
}

// Function to find the degree of a vertex
int Graph::degree(int v) {
    return adj[v].size();
}

// Function to find a valid starting vertex for the Eulerian path/circuit
int Graph::findStartVertex() {
    int start = 0;
    for (int i = 0; i < V; i++) {
        // Start from a vertex with an odd degree if available
        if (degree(i) % 2 == 1)
            return i;
        // Otherwise, any vertex with a non-zero degree will do
        if (degree(i) > 0)
            start = i;
    }
    return start;
}

// Function to print the Eulerian path or circuit using Fleury's Algorithm
void Graph::printEulerPath() {
    int u = findStartVertex(); 
    cout << "Eulerian Path or Circuit: ";
    
    while (degree(u) > 0) {
        for (auto v : adj[u]) {
            if (degree(u) == 1 || !isBridge(u, v)) {
                cout << u << " - " << v << "  ";
                removeEdge(u, v);
                u = v;
                break;
            }
        }
    }
    cout << endl;
}

// Main function
int main() {
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    g.printEulerPath(); // Print the Eulerian path or circuit

    return 0;
}
