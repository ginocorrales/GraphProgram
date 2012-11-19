/* Here is the implementation of a Graph class
 * Author: Gino P. Corrales-Delgado
 * IT 279 - 4th Programming Assignment 
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <string.h>
#include <iterator>
using namespace std;

#include "Graphs.h"

#define INFINITE_NUM 99999999

// Gets the closest node for Shortest Path
int ClosestFalseNodes(int numOfVertices, bool flaged[], int distance[]);
// Print the Shortest Path 
void printPath(int node, int source, int prev[], string * arrayOfNames);

Graphs::Graphs() 
{
  this -> adjacencyMatrix = NULL;
  this -> arrayOfNames = NULL;
  this -> incomingEdges = NULL;
  this -> numOfVertices = 0;
  this -> numOfEdges = 0;
}

Graphs::Graphs(const Graphs &orig)
{
  this -> copy(orig);
}

void Graphs::copy(const Graphs &rhs)
{
  if(rhs.adjacencyMatrix == NULL)
  {
    this -> adjacencyMatrix = NULL;
    this -> arrayOfNames = NULL;
    this -> incomingEdges = NULL;
    this -> numOfVertices = 0;
    this -> numOfEdges = 0;
  }
  else
  {
    int** currAM = rhs.adjacencyMatrix;
    while(currAM)
    {
      for(int x = 0 ; x < numOfVertices ; x++)
      {
        for(int y = 0 ; y < numOfVertices ; y++)
          currAM[x][y] = adjacencyMatrix[x][y];
      }  
    }
  }
}

Graphs& Graphs::operator =(const Graphs &rhs)
{
  if(this != &rhs)
  {
    if(!this -> isEmpty())
      this -> Clear();

    this -> copy(rhs);
  }
  return *this;
}

void Graphs::Clear()
{
  while(!this -> isEmpty())
  {
    for (int i = 0; i < numOfVertices; i++)
    {
      delete[] adjacencyMatrix[i];
      delete[] adjacencyMatrix;
    }       
  }
}


bool Graphs::isEmpty()
{
  bool isEmpty = false;
  if(this -> adjacencyMatrix == NULL)
    isEmpty = true;

  return isEmpty;
}


Graphs::~Graphs()
{
  for (int i = 0; i < numOfVertices; i++)
  {
    delete[] adjacencyMatrix[i];
    delete[] adjacencyMatrix;
  }
}

// Function that read a graph
void Graphs::ReadGraph(string fileName) 
{
  ifstream inStream;
  int numVertices;

  inStream.open(fileName.c_str());
  inStream >> numOfVertices;
  
  //store the name of the vertices
  arrayOfNames = new string [numOfVertices];
  
  //creation of a bidimensional array
  adjacencyMatrix = new int *[numOfVertices];

  for(int j = 0; j < numOfVertices; j++)
    adjacencyMatrix[j] = new int[numOfVertices];
  
  for(int i= 0; i < numOfVertices ; i++)
    inStream >> arrayOfNames[i];
  
  for(int x = 0 ; x < numOfVertices ; x++)
  {
     for(int y = 0 ; y < numOfVertices ; y++)
		   adjacencyMatrix[x][y] = 0; 
  }

  inStream >> numOfEdges;
  string fromNode, toNode;
  int cost;
  for(int i= 0; i < numOfEdges ; i++)
  {
    inStream >> fromNode;
    inStream >> toNode;
    inStream >> cost;
    adjacencyMatrix[convertToIndex(fromNode)][convertToIndex(toNode)] = cost;  
  }
  inStream.close();  

}

void Graphs::PrintMatrix(string fileName)
{
  // print the matrix
  for(int x = 0 ; x < numOfVertices ; x++)
  {
    cout<< arrayOfNames[x] << " ";
    for(int y = 0 ; y < numOfVertices ; y++)
      cout << adjacencyMatrix[x][y] << " ";

     cout << endl;
  } 
}

int Graphs::convertToIndex(string node)
{
  int index=0;
  for(int i=0; i < numOfVertices ; i++)
  {
    if(arrayOfNames[i] == node)
      index = i;
  }
  return index;
}
  
void Graphs::TopologicalSort()
{
  incomingEdges= new int[numOfVertices];
  
  //initialize all array with 0s
  for(int i = 0 ; i < numOfVertices ; i++)
     incomingEdges[i]=0;
  for(int x = 0 ; x < numOfVertices ; x++)
  {
    for(int y = 0 ; y < numOfVertices ; y++)
    {   
      if(adjacencyMatrix[x][y] > 0)
        incomingEdges[y]++;
    }
  }
 
  queue<int> topologicalSortQueue;  // using the STL
  for(int x = 0 ; x < numOfVertices ; x++)
  {
     if(incomingEdges[x] == 0)
       topologicalSortQueue.push(x);
  }
  cout << endl;

  // entering to the queue only the index 
  if(!topologicalSortQueue.empty())
  {
    cout<< endl << "The Topological Sort is: "<<endl;
    while(!topologicalSortQueue.empty())
    {  
      int currIndex = topologicalSortQueue.front();
      topologicalSortQueue.pop();

      cout << arrayOfNames[currIndex] << " ";
      for(int x = 0 ; x < numOfVertices ; x++)  
      {
        if(adjacencyMatrix[currIndex][x] > 0)
        { 
          incomingEdges[x]--;  
          if(incomingEdges[x] == 0)
            topologicalSortQueue.push(x);
        }
      }
    } 
    cout << endl;
  }
  else
    cout<< endl << "***  Error: It is not possible a Topological Sort with this graph  ***" << endl;
  
  delete[] incomingEdges;
}

int ClosestFalseNodes(int numOfVertices, bool flaged[], int distance[]) 
{  
	int minDistance = INFINITE_NUM;
	int unflagNodes;
	for(int i=0; i < numOfVertices; i++) 
  {
		if((!flaged[i]) && ( minDistance >= distance[i])) 
    {
			minDistance = distance[i];
			unflagNodes = i;
		}
	}
	return unflagNodes;
}

void printPath(int node, int source, int prev[], string* arrayOfNames)
{
    if(node == source)
      cout << arrayOfNames[node] << " -- ";
    else if(prev[node] == -1)
      cout<<" "<<endl;
    else 
    {
        printPath(prev[node], source, prev,arrayOfNames);
        cout << arrayOfNames[node] << " -- ";
    }
}

void Graphs::ShortestPath(string startingNode)
{	
	int inicial = 0;
	for (int i=0; i< numOfVertices; i++)
  {
		if (startingNode == arrayOfNames[i])
    {
			inicial = i;
			break;
		}
  } 
	source = inicial;
 
  for(int x = 0 ; x < numOfVertices ; x++)
  {
    for(int y = 0 ; y < numOfVertices ; y++)
    {
		  if(adjacencyMatrix[x][y] == 0)
		    adjacencyMatrix[x][y] = INFINITE_NUM;
    }
  }	
  
	for(int i=0; i < numOfVertices; i++) 
  {
		flaged[i] = false;
		prev[i] = -1;
		distance[i] = INFINITE_NUM;
	}
	distance[source]= 0;
  
  int count = 0;
	int minDistance = INFINITE_NUM;
	int unflagNodes;
	
	while(count < numOfVertices) 
  {
	  unflagNodes = ClosestFalseNodes(numOfVertices, flaged, distance);
	  flaged[unflagNodes] = true;
	  for(int i=0;i<numOfVertices;i++) 
    {
      if((!flaged[i]) && (adjacencyMatrix[unflagNodes][i] > 0)) 
      {
        if(distance[i] > distance[unflagNodes] + adjacencyMatrix[unflagNodes][i]) 
        {
					distance[i] = distance[unflagNodes] + adjacencyMatrix[unflagNodes][i];
					prev[i] = unflagNodes;
				}
			}
		}
		count++;
	}	
  
  if(distance[numOfVertices-1] != INFINITE_NUM)
  {
    
  // Printing the Shortest Path
	cout<< endl << "The Shortest Path using Dijkstra is: ";
  cout<< distance[numOfVertices-1] << "   - Here is how: " << endl;

  for(int i=0; i < numOfVertices; i++)  //-1
  {
    if(i == source)
      cout << "";    
    else if(distance[i]!= INFINITE_NUM) 
    {
      printPath(i, source, prev, arrayOfNames);   
      cout << " -> " << distance[i] << endl;
    }
  }
  }
  else
    cout << endl << "It is NOT a shortest Path from this Node" << endl;
}

void Graphs::MinSpanTree()
{
	// Mirrow the matrix
	for(int i=0; i < numOfVertices; i++)
  { 
		for(int j=0;j < numOfVertices;j++)
    { 
	    if(adjacencyMatrix[j][i] != INFINITE_NUM)
		    adjacencyMatrix[i][j] = adjacencyMatrix[j][i];
	  }
  }	
	
  int** adjacent = adjacencyMatrix; 
	int totalWeightMST = 0;
  int sameSetTree[100][100];

  // to identify which nodes belong to each set
  int* sameSet = new int[numOfVertices]; 
 
  for(int i = 0; i < numOfVertices; i++)
  {
    for(int j = 0 ;  j<numOfVertices; j++) 
		  sameSetTree[i][j] = INFINITE_NUM;
    
    sameSet[i] = i;
  }

  int nodoA, nodoB;
  int tempEdges = 1;
  while(tempEdges < numOfVertices)
  {
    // Find the min node that do not belong to the set and store the weight
    int min = INFINITE_NUM;
    for(int i = 0; i < numOfVertices; i++)
    {
      for(int j = 0; j < numOfVertices; j++)
      {
        if(min > adjacent[i][j] && sameSet[i] != sameSet[j])
        {
          min = adjacent[i][j];
          nodoA = i;
          nodoB = j;
        }
      } 
    cout << "";
    }
    
    // if the nodes do not belong to the same tree, add to the min tree
    if(sameSet[nodoA] != sameSet[nodoB])
    {
      sameSetTree[nodoA][nodoB] = min;
      sameSetTree[nodoB][nodoA] = min;
 
      // All nodes from node B's tree, now belong to the node A
      int temp = sameSet[nodoB];
      sameSet[nodoB] = sameSet[nodoA];
      for(int k = 0; k < numOfVertices; k++)
      {
        if(sameSet[k] == temp)
          sameSet[k] = sameSet[nodoA];
      }
      tempEdges++;
    }
  }
  
  //print the MST 
  cout << endl << endl << "The Minimun Spanning Tree (MST) is: " << endl;
	for(int i = 0; i < numOfVertices; i++)
  {
    for(int j = i ;  j<numOfVertices; j++) 
    {
		  if (sameSetTree[i][j] != INFINITE_NUM)
      {
			  totalWeightMST = totalWeightMST + sameSetTree[i][j];
        cout << arrayOfNames[i] << " -- " << arrayOfNames[j] << " -> " << sameSetTree[i][j] << endl;
        
      }
    }
  }
  cout << endl << "***  MST's Total weight is: " << totalWeightMST << "  ***" << endl; 

  delete[] sameSet;    
}


