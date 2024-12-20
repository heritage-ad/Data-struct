/* Program name: DFS Traversal 
Author: Heritage Adigun
Date last updated: 11/04/2024
Purpose: A program that outputs the nodes of a graph in a depth-first traversal.*/


#include <iostream> 
#include <list> 
using namespace std; 
//graph class for DFS traversal  
class DFSGraph 
{ 
int V;    // No. of vertices 
list<int> *adjList;    // adjacency list 
void DFS_util(int v, bool visited[]);  // A function used by DFS 
public: 
    // class Constructor
DFSGraph(int V)
    {
 this->V = V; 
 adjList = new list<int>[V]; 
    }
    // function to add an edge to graph 
void addEdge(int v, int w){
adjList[v].push_back(w); // Add w to v’s list.
    }
     
void DFS();    // DFS traversal function 
}; 
void DFSGraph::DFS_util(int v, bool visited[]) 
{ 
    // current node v is visited 
visited[v] = true; 
cout << v << " "; 
   
    // recursively process all the adjacent vertices of the node 
list<int>::iterator i; 
for(i = adjList[v].begin(); i != adjList[v].end(); ++i) 
if(!visited[*i]) 
DFS_util(*i, visited); 
} 
   
// DFS traversal 
void DFSGraph::DFS() 
{ 
    // initially none of the vertices are visited 
bool *visited = new bool[V]; 
for (int i = 0; i < V; i++) 
visited[i] = false; 
   
    // explore the vertices one by one by recursively calling  DFS_util
for (int i = 0; i < V; i++) 
if (visited[i] == false) 
DFS_util(i, visited); 
} 
 // main function  
int main() 
{ 
    // Create a graph
DFSGraph gdfs(5); 
gdfs.addEdge(0, 1); 
gdfs.addEdge(0, 2); 
gdfs.addEdge(0, 3);
gdfs.addEdge(1, 2); 
gdfs.addEdge(2, 4);
gdfs.addEdge(3, 3); 
gdfs.addEdge(4, 4);
 
cout << "Depth-first traversal for the given graph:"<<endl; 
gdfs.DFS(); 
   
return 0; 
}