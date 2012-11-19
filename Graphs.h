/* Declaration of a Graph Class using an adjacency matrix 
 * Author: Gino P. Corrales-Delgado
 * IT 279 - 4th Programming Assignment 
 */
#ifndef GRAPHS_H
#define GRAPHS_H

class Graphs
{
  public:     																																			
    // Constructor
    Graphs();
    
    // Copy Constructor
    Graphs(const Graphs &orig);
    
    // Destructor
     ~Graphs();
    
    // Reads input file with a Graph
    void ReadGraph(string fileName);
    
    // Gives the Topological Sort - Putting in order all nodes of the Grapg
    void TopologicalSort();
    
    // Gives the Shortest Path of the Graph using Dijkstra's algorithm
    void ShortestPath(string startingNode);
    
    // Gives the Minimun Spanning of Tree of the Graph
    void MinSpanTree();

    // Print the Matrix - enter the file
    void PrintMatrix(string fileName);
    
    // Convert to INdex in the matrix
    int convertToIndex(string node);
    
    // Overload Assign Operator
    Graphs& operator=(const Graphs &rhs); 

    // Verifies if Graph is empty
    bool isEmpty();


  private:
    // This graph use an Adjacency Matrix with a bidimensional matrix
    int** adjacencyMatrix;
    
    // Array of incoming edges
    int* incomingEdges;

    // Stores the Number of Vertices
    int numOfVertices;
    
    // Stores the Number of Edges
    int numOfEdges;
    
    // Array of Egde's Names 
    string* arrayOfNames;

    // Method used by the copy constructor
    void copy(const Graphs &rhs);
    
    // Help for the assigment operator
    void Clear();
    
    // other arrays that will need for shortest path 
    bool flaged[100];
	  int distance[100];
	  int prev[100];
	  int source;

};		
																																										
#endif

