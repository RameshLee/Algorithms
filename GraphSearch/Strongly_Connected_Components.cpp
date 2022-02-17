// C++ Program to print Strongly Connected Components (SCC) in a Graph using Kosaraju Algorithm at O(E+V) time complexity

#include <iostream>
#include <vector>
using namespace std;

#include "graph.h"

// Driver Code 
int main() 
{
    /*Graph g(50);
    g.Add_Edge(0,1);
    g.Add_Edge(1,2);
    g.Add_Edge(2,3);
    g.Add_Edge(3,0);
    g.Add_Edge(2,4);
    g.Add_Edge(4,5);
    g.Add_Edge(5,6);
    g.Add_Edge(6,4);
    g.Add_Edge(6,7);
    g.print();
    g.print_SCC();*/
    //Ans: {0,3,2,1},{4,6,5},{7}

    /*Graph g(50);
    g.Add_Edge(0,1);
    g.Add_Edge(1,2);
    g.Add_Edge(2,0);
    g.Add_Edge(2,3);
    g.Add_Edge(3,4);
    g.Add_Edge(4,5);
    g.Add_Edge(4,7);
    g.Add_Edge(5,6);
    g.Add_Edge(6,4);
    g.Add_Edge(6,7);
    g.print();
    g.print_SCC();*/
    //Ans: {0,2,1},{3},{4,6,5},{7}


    Graph g(50);
    g.Add_Edge(0,1);
    g.Add_Edge(1,2);
    g.Add_Edge(2,0);
    g.Add_Edge(2,4);
    g.Add_Edge(3,4);
    g.Add_Edge(4,5);
    g.Add_Edge(5,3);
    g.print();
    g.print_SCC();

    printf("\nExiting program! \n\n");

    return 0; 
} 
