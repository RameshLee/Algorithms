// C++ main program

#include <iostream>
#include <vector>
using namespace std;

#include "graph.h"

// Driver Code 
int main() 
{ 

    Graph g(100);
    g.Add_Edge(1,0);
    g.Add_Edge(1,2);
    g.Add_Edge(1,3);
    g.Add_Edge(1,4);
    g.Add_Edge(0,5);
    g.Add_Edge(2,7);
    g.Add_Edge(2,8);
    g.Add_Edge(2,9);
    g.print();

    //g.BFS(1);
    g.DFS(1); //argument is source node
    //g.print_DFS();


    return 0; 
} 
