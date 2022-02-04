// C++ program for building Heap from Array 

#include <iostream>
#include <vector>
using namespace std;

class edge
{
public:
    int node;
    int weight;

    edge(int n, int w) {node = n; weight = w;}
    ~edge() {}

    void refurbish(int n, int w) {node = n; weight = w;}
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

    Graph(int total_vertices)
    {
        n = total_vertices;
        Vertex = new vertex[n];
        for (int i=0; i<n; i++)
            Vertex[i].ID = i;
    }

    ~Graph() {delete[] Vertex;}

    void Add_Edge(int a, int b, int value)
    {
        Vertex[a].Edge.push_back(edge(b,value));
        Vertex[b].Edge.push_back(edge(a,value));
    }

    void print()
    {
        printf("Total Vertices: %d\n", n);
        for (int i=0; i<n; i++)
            for (int j=0; j<Vertex[i].Edge.size(); j++)
                printf("Edge: [%d,%d]=%d\n", i,Vertex[i].Edge[j].node, Vertex[i].Edge[j].weight);
    }
};


class UnionFind
{
public:
    int n;
    int *group;
    int Next_available_group_id;

    UnionFind()
    {
        Next_available_group_id = 1;
        group = new int[n];
    }

    ~UnionFind() {delete[] group;}

    void makeset()
    {
        for (int i=0; i<n; i++)
            group[i] = 0; //0-no group has been alloted yet
    }

    int find(int v)
    {
        return group[v];
    }

    void unify(int v, int w)
    {
        if (find(v) == 0 && find(w) == 0) //both v & w doesn't have a group
        {
            group[v] = Next_available_group_id;
            group[w] = Next_available_group_id;
            Next_available_group_id++;
        }
        else if (find(v) == 0 && find(w) > 0)//v doesn't have a group
            group[v] = group[w];
        else if (find(v) > 0 && find(w) == 0)//w doesn't have a group
            group[w] = group[v];
        else if (find(v) > 0 && find(w) > 0 && find(v) != find(w))//v & w in diff group
        {
            int label_1 = find(v);
            int label_2 = find(w);
            //merge all elements in both groups into a single group
            for (int i=0; i<n; i++)
                if (group[i] == label_2)
                    group[i] = label_1;
        }

    }
};

void Kruskal()
{

}

// Driver Code 
int main() 
{ 
    Graph g(9);
    g.Add_Edge(1,0,12);
    g.Add_Edge(1,2,20);
    g.Add_Edge(1,3,21);
    g.Add_Edge(1,4,19);
    g.print();


    printf("Exiting program! \n\n");

    return 0; 
} 
