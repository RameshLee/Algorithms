// C++ program for Dijikstra Algorithm

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
    int visited;
    int prev_node;
    int dist;
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
        {
            Vertex[i].ID = i;
            Vertex[i].visited = 0;
            Vertex[i].prev_node = i;
            Vertex[i].dist = INT_MAX;
        }
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

    void full_print()
    {
        for (int i=0; i<n; i++)
        {
            printf("Vertex[%d].dist = %d, visited(%d) from %d\n", i, Vertex[i].dist, Vertex[i].visited, Vertex[i].prev_node);
        }
    }
};

class Dijkstra
{
public:
    Graph *g;

    Dijkstra() {g = new Graph;}
    ~Dijkstra() {delete g;}

    int find_next_node_to_traverse_with()
    {
        // use priority queue here for better time complexity

        int min_dist = 0;
        int min_k;
        for (int i=0; i<g[0].n; i++)
            if (g[0].Vertex[i].visited == 0)
                if (min_dist == 0 || g[0].Vertex[i].dist < min_dist)
                {
                    min_dist = g[0].Vertex[i].dist;
                    min_k = i;
                }

        return min_k;
    }

    void solve(int starting_node)
    {
        // 1) make a priority queue using min heap with all vertices

        // 2) for loop: each unvisited vertex with min dist
            // update costs of the neighboring unvisited nodes
            // select the shortest path neighbor node as visited
            // decrease-key in the heap

        g[0].Vertex[starting_node].visited = 1;
        g[0].Vertex[starting_node].dist = 0;
        for (int i=0; i<g[0].n; i++)
        {
            // 1) pick the min dist valued unvisited node
            int k;
            if (i == 0)
                k = starting_node;
            else
                k = find_next_node_to_traverse_with();
            printf("Next_traversal_node = %d\n", k);
            g[0].full_print();

            // 2) visit the neighbor nodes
            for (int j=0; j<g[0].Vertex[k].Edge.size(); j++)
            {
                int neighbor = g[0].Vertex[k].Edge[j].end_node;
                printf("    neighbor: %d\n", neighbor);
                if (g[0].Vertex[neighbor].visited == 0)
                {
                    if (g[0].Vertex[k].dist + g[0].Vertex[k].Edge[j].weight < g[0].Vertex[neighbor].dist)
                    {
                        g[0].Vertex[neighbor].dist = g[0].Vertex[k].dist + g[0].Vertex[k].Edge[j].weight;
                        g[0].Vertex[neighbor].prev_node = k;
                    }
                }
            }

            // 3) mark the current node k as visited
            g[0].Vertex[k].visited = 1;
        }

    }

};

// Driver Code 
int main() 
{ 
    Dijkstra dijkstra;
    /*dijkstra.g[0].Add_Vertices(5);
    dijkstra.g[0].Add_Edge(0,1,3);
    dijkstra.g[0].Add_Edge(0,2,1);
    dijkstra.g[0].Add_Edge(1,2,7);
    dijkstra.g[0].Add_Edge(1,3,5);
    dijkstra.g[0].Add_Edge(2,3,2);
    dijkstra.g[0].Add_Edge(1,4,1);
    dijkstra.g[0].Add_Edge(3,4,7);*/

    dijkstra.g[0].Add_Vertices(5);
    dijkstra.g[0].Add_Edge(0,4,1);
    dijkstra.g[0].Add_Edge(0,1,6);
    dijkstra.g[0].Add_Edge(4,1,2);
    dijkstra.g[0].Add_Edge(4,3,1);
    dijkstra.g[0].Add_Edge(1,3,2);
    dijkstra.g[0].Add_Edge(1,2,5);
    dijkstra.g[0].Add_Edge(3,2,5);
    //ANS: dist=[0,3,7,1,2] for source node 0

    dijkstra.g[0].print();
    int starting_node = 0;
    dijkstra.solve(starting_node);

    printf("\nExiting program! \n\n");

    return 0; 
} 
