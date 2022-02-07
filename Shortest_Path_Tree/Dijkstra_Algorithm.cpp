// C++ program for building Heap from Array 

#include <iostream>
#include <vector>
using namespace std;

class edge
{
public:
    int start_node;
    int end_node;
    int weight;

    edge(int a=0, int b=0, int w=0) {start_node = a; end_node = b, weight = w;}
    ~edge() {}

    void update(edge Edge) {start_node = Edge.start_node; end_node = Edge.end_node, weight = Edge.weight;}

    void print()
    {
        printf("Edge[%d][%d]=%d\n", start_node, end_node, weight);
    }
};

class vertex
{
public:
    int ID;
    vector<edge> Edge;
};

struct Graph
{
    vertex *Vertex;
    int n;

    Graph() {}

    ~Graph() {delete[] Vertex;}

    void Add_Vertices(int total_vertices)
    {
        n = total_vertices;
        Vertex = new vertex[n];
        for (int i=0; i<n; i++)
            Vertex[i].ID = i;
    }

    void Add_Edge(int a, int b, int value)
    {
        Vertex[a].Edge.push_back(edge(a,b,value));
        Vertex[b].Edge.push_back(edge(b,a,value));
    }

    void print()
    {
        printf("Total Vertices: %d\n", n);
        for (int i=0; i<n; i++)
            for (int j=0; j<Vertex[i].Edge.size(); j++)
                printf("Edge: [%d,%d]=%d\n", Vertex[i].Edge[j].start_node,Vertex[i].Edge[j].end_node, Vertex[i].Edge[j].weight);
    }
};

class Dijkstra
{
public:
    Graph *g;

    Dijkstra() {g = new Graph;}
    ~Dijkstra() {delete g;}

    void solve()
    {

    }

};

// Driver Code 
int main() 
{ 
    Dijkstra dijkstra;
    dijkstra.g[0].Add_Vertices(4);
    dijkstra.g[0].Add_Edge(0,1,10);
    dijkstra.g[0].Add_Edge(0,2,21);
    dijkstra.g[0].Add_Edge(1,2,18);
    dijkstra.g[0].Add_Edge(1,3,22);
    dijkstra.g[0].Add_Edge(2,3,13);

    dijkstra.g[0].print();
    dijkstra.solve();

    printf("\nExiting program! \n\n");

    return 0; 
} 
