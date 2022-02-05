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

struct node
{
    int ID;
    int rank;
    int root;

    void initialize(int i)
    {
        ID = i;
        root = i;
        rank = 0;
    }
};

class UnionFind
{
public:
    int n;
    node *Node;
    int Next_available_group_id;

    UnionFind(int size)
    {
        n = size;
        Next_available_group_id = 1;
        Node = new node[n];
    }

    ~UnionFind() {delete[] Node;}

    void makeSet()
    {
        for (int i=0; i<n; i++)
            Node[i].initialize(i); //0-no group has been alloted yet
    }

    int parent(int i)
    {
        //find parent
        while (i != Node[i].root)
        {
            Node[i].root = Node[ Node[i].root ].root;
            i = Node[i].root;
        }
        return i;
    }

    void unify(int i, int j)
    {
        if (Node[i].rank > Node[j].rank) //i will become parent of j
        {
            Node[parent(j)].root = i;
            Node[i].rank += 1;
        }
        else //j will become parent of i
        {
           Node[parent(i)].root = j;
           Node[j].rank += 1;
        }
    }
};


class Kruskal
{
public:
    Graph *g;

    Kruskal() {g = new Graph;}
    ~Kruskal() {delete g;}

    void solve()
    {
        //1) find total edges
        int total_edges = 0;
        for (int i=0; i<g[0].n; i++)
            total_edges += (int)g[0].Vertex[i].Edge.size();

        //2) store edges in an array
        edge *Edges = new edge[total_edges];
        int edge_number = 0;
        for (int i=0; i<g[0].n; i++)
        {
            for (int j=0; j<g[0].Vertex[i].Edge.size(); j++)
            {
                Edges[edge_number].update(g[0].Vertex[i].Edge[j]);
                edge_number++;
            }
        }

        //3) Remove self loops
        

        // 3) insertion sort
        for (int i=0; i<total_edges; i++)
            for (int j=i; j<total_edges; j++)
                if (Edges[i].weight > Edges[j].weight)
                {
                    edge Temp = Edges[i];
                    Edges[i] = Edges[j];
                    Edges[j] = Temp;
                }

        printf("Sorted Edges:\n");
        for (int i=0; i<total_edges; i++)
            Edges[i].print();

        // 4) kruskal algorithm

            vector<edge> MST_Edges;
            // 4.1) makeset()
            UnionFind UF(g[0].n);
            UF.makeSet();

            // 4.2) for loop in sorted edge order
            for (int i=0; i<total_edges; i++)
            {
                int u = Edges[i].start_node; int v = Edges[i].end_node;
                if (UF.parent(u) != UF.parent(v))
                {
                    MST_Edges.push_back(Edges[i]);
                    UF.unify(u,v);
                }
            }

            // 4.3) calculate MST length
            int MST_Length = 0;
            for (int i=0; i<MST_Edges.size(); i++)
                MST_Length += MST_Edges[i].weight;

            printf("MST Edges:\n");
            for (int i=0; i<MST_Edges.size(); i++)
                MST_Edges[i].print();
            printf("MST Length: %d\n", MST_Length);

        delete[] Edges;
    }

};

// Driver Code 
int main() 
{ 
    Kruskal krusk;
    krusk.g[0].Add_Vertices(4);
    krusk.g[0].Add_Edge(0,1,10);
    krusk.g[0].Add_Edge(0,2,21);
    krusk.g[0].Add_Edge(1,2,18);
    krusk.g[0].Add_Edge(1,3,22);
    krusk.g[0].Add_Edge(2,3,13);
    //MST=41

    /*krusk.g[0].Add_Vertices(6);
    krusk.g[0].Add_Edge(0,1,4);
    krusk.g[0].Add_Edge(0,2,4);
    krusk.g[0].Add_Edge(1,2,2);
    krusk.g[0].Add_Edge(2,3,3);
    krusk.g[0].Add_Edge(2,4,2);
    krusk.g[0].Add_Edge(2,5,4);
    krusk.g[0].Add_Edge(3,5,3);
    krusk.g[0].Add_Edge(4,5,3);*/
    //MST=14

    /*krusk.g[0].Add_Vertices(5);
    krusk.g[0].Add_Edge(0,1,1);
    krusk.g[0].Add_Edge(0,2,7);
    krusk.g[0].Add_Edge(0,3,10);
    krusk.g[0].Add_Edge(0,4,5);
    krusk.g[0].Add_Edge(1,2,3);
    krusk.g[0].Add_Edge(2,3,4);
    krusk.g[0].Add_Edge(3,4,2);*/
    //MST=10

    /*krusk.g[0].Add_Vertices(6);
    krusk.g[0].Add_Edge(4,3,9);
    krusk.g[0].Add_Edge(4,0,4);
    krusk.g[0].Add_Edge(3,0,1);
    krusk.g[0].Add_Edge(3,2,5);
    krusk.g[0].Add_Edge(3,1,3);
    krusk.g[0].Add_Edge(0,1,2);
    krusk.g[0].Add_Edge(2,1,3);
    krusk.g[0].Add_Edge(2,5,8);
    krusk.g[0].Add_Edge(1,5,7);*/
    //MST=17


    krusk.g[0].print();

    krusk.solve();


    printf("\nExiting program! \n\n");

    return 0; 
} 
