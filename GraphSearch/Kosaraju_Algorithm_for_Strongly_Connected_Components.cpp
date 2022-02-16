// C++ Program to find the Strongly Connected Components (SCC) in a Graph using Kosaraju Algorithm with O(E+V) time complexity

#include <iostream>
#include <vector>
using namespace std;

#include "graph.h"

class Kosaraju
{
public:
    vector< vector<int> > Connected_Components;
    vector<int> stack;
    Graph g;

    Kosaraju() {}
    ~Kosaraju() {}

    void Reverse_the_Graph()
    {

    }

    void solve()
    {
        // 1) perform DFS from a source node
        int s = 0;
        g.DFS_array.clear();
        g.DFS(s);

        vector<int> visited_set = g.DFS_array;

        // 2) backtrack DFS_array and fill the stack
        while(g.DFS_array.size() != g.V)
        {
            int node = visited_set.back(); //return last element
            visited_set.pop_back(); //delete last element
            stack.push_back(node);
            g.DFS(node);

        }
    }

};


// Driver Code 
int main() 
{ 
    Kosaraju Kosa;

    Kosa.g.Allocate(100);
    Kosa.g.Add_Edge(0,1);
    Kosa.g.Add_Edge(1,2);
    Kosa.g.Add_Edge(2,3);
    Kosa.g.Add_Edge(3,0);
    Kosa.g.Add_Edge(2,4);
    Kosa.g.Add_Edge(4,5);
    Kosa.g.Add_Edge(5,6);
    Kosa.g.Add_Edge(6,4);
    Kosa.g.Add_Edge(6,7);
    Kosa.g.print();

    Kosa.g.DFS(0);
    Kosa.g.Destroy();

    printf("\nExiting program! \n\n");

    return 0; 
} 
