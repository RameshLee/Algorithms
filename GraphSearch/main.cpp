// C++ main program

#include <iostream>
#include <vector>
using namespace std;

#include "graph.h"

// Driver Code 
int main() 
{ 

    Graph g(6);
    g.Add_Edge(1,0);
    g.Add_Edge(1,2);
    g.Add_Edge(1,3);
    g.Add_Edge(1,4);
    g.Add_Edge(0,5);

    g.print();

    g.BFS(1);

    printf("Exiting program! \n\n");

    return 0; 
} 
