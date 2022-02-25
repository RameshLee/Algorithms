// C++ program for counting islands problem using Disjoint set algorithm

#include <iostream>
#include <vector>
using namespace std;

#define max(a,b) a>b?a:b

struct Node
{
    int value; //1-land,0-water
    int rank;
    int root;

    Node(int a, int b) {value=a; root=b; rank=0;}
    ~Node() {}
};

struct DisjointSet
{
    vector<Node> node;
    int row; int col;

    void makeset(int n, int m, vector<vector<int>> M)
    {
        row = n; col = m;
        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
                node.push_back(Node(M[i][j],i*col+j));
    }

    void print()
    {
        for (int i=0; i<row*col; i++)
        {
            if (i> 1 && i%col == 0)
                printf("\n");
            //printf("%d ", node[i].value);
            printf("%d ", find_parent(i));
        }
    }

    int find_parent(int i)
    {
        while(node[i].root != i)
        {
            node[i].root = node[ node[i].root ].root;
            i = node[i].root;
        }
        return i;
    }

    void unify(int i, int j)
    {
        int x = find_parent(i);
        int y = find_parent(j);

        if (node[x].rank > node[y].rank)
            node[y].root = x;
        else if (node[x].rank < node[y].rank)
            node[x].root = y;
        else if (node[x].rank == node[y].rank)
        {
            node[x].root = y;
            node[y].rank++;
        }
    }

};

int main()
{
    int row = 5; int col = 5;
     vector<vector<int>> Matrix = {{1, 1, 0, 0, 0},
                         {0, 1, 0, 0, 1},
                         {1, 0, 0, 1, 1},
                         {0, 0, 0, 0, 0},
                         {1, 0, 1, 0, 1}};

    DisjointSet DS;
    DS.makeset(row, col, Matrix);
    DS.print();

    printf("\nExited the Program!\n\n");
    return 0;
}