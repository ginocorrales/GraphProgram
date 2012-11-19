/* Here is the file that will execute the Graph
 * includes a Menu to easy access to all functions of the class. 
 * Author: Gino P. Corrales-Delgado
 * IT 279 - 4th Programming Assignment 
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <iostream>
#include <string.h>
using namespace std;

#include "Graphs.h"

int main(int argc, char** argv)
{
  Graphs aGraph;
  int option = 1;
  string fileName;
  ifstream inStream;
  string startingNode; 
  string ansMatrix = "N";
  cout << endl << "*** For this program, only valid options 1 to 5. Thank you.  ***" << endl;
  //do
  while(option >= 1 && option <= 4) 
  { 
    cout << endl << "*********** GRAPH MENU ***********" << endl;
    cout << "*  1. Read a Graph from a File   *" <<endl;
    cout << "*  2. Topological Sort of Graph  *" <<endl;
    cout << "*  3. Shortest Path              *" <<endl;
    cout << "*  4. Minimun Spanning Tree      *" <<endl;
    cout << "*  5. Exit the Program           *" <<endl;
    cout << "**********************************" <<endl;

    cout << "*  Please, enter a option: ";
    cin >> option;
    
    switch (option)
    {
        case 1:
          // Read a graph entering the fine name by the user
          int numVertices;
          cout << endl << "Please, enter the name of the file containing the Graph: ";
          cin >> fileName;
          aGraph.ReadGraph(fileName);
          cout << endl <<"***  Thanks, file called " << fileName << " has been read.  ***" << endl;
          cout<< endl << "***  Do you want to see the matrix of the graph? Y/N : " ;
          cin >> ansMatrix;
          if(ansMatrix == "Y")
          {   
            cout << endl << "***  Here is the Matrix  ***" << endl << endl; 
            // print the matrix
            aGraph.PrintMatrix(fileName);
          }
          break;

        case 2:
          // Topological Sort
          aGraph.TopologicalSort();
          break;

        case 3: 
          // ShortestPath
          cout << endl << endl << "Please, enter the node name to get The Shortest Path: ";
          cin >> startingNode;
          aGraph.ShortestPath(startingNode);
          break;

        case 4:
          // Minimun Spanning Tree
          aGraph.MinSpanTree();
          break;
 
        default: 
           cout << endl << "***  Thank you for use my program.  ***" << endl;
          break;
      }
  }

  cout << endl <<"End of the Program!" << endl << endl; 

  return 0;
}

