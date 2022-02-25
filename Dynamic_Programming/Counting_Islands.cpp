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
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
                printf("%d ", node[i*col+j].value);//find_parent(i*col+j));
            printf("\n");
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

    void Count_Islands()
    {
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
            {
                //check 8 corners
                //1) right
                /*if (j+1 < col && node[i*col+j].value == 1)
                    printf("right: %d\n", node[(i*col)+(j+1)].value);
                else
                    printf("right: deadend\n");*/


                //2) left
                /*if (j-1 >= 0 && node[i*col+j].value == 1)
                    printf("left: %d\n", node[(i*col)+(j-1)].value);
                else
                    printf("left: deadend\n");*/


                //3) top
                /*if ((i-1) >= 0 && node[i*col+j].value == 1)
                    printf("top: %d\n", node[((i-1)*col)+j].value);
                else
                    printf("top: deadend\n");*/

                //4) bottom
                /*if ((i+1) < row && node[i*col+j].value == 1)
                    printf("bottom: %d\n", node[((i+1)*col)+j].value);
                else
                    printf("bottom: deadend\n");*/

                //5) bottom-left
                /*if ((i+1) < row && (j-1) >= 0 && node[i*col+j].value == 1)
                    printf("bottom-left: %d\n", node[((i+1)*col)+j-1].value);
                else
                    printf("bottom-left: deadend\n");*/

                //6) bottom-right
                /*if ((i+1) < row && (j+1) < col && node[i*col+j].value == 1)
                    printf("bottom-right: %d\n", node[((i+1)*col)+j+1].value);
                else
                    printf("bottom-right: deadend\n");*/

                //7) top-left
                /*if ((i-1) >= 0 && (j-1) >= 0 && node[i*col+j].value == 1)
                    printf("top-left: %d\n", node[((i-1)*col)+j-1].value);
                else
                    printf("top-left: deadend\n");*/

                //8) top-right
                if ((i-1) >= 0 && (j+1) < col && node[i*col+j].value == 1)
                    printf("top-right: %d\n", node[((i-1)*col)+j+1].value);
                else
                    printf("top-right: deadend\n");
            }
            printf("\n");
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
    DS.Count_Islands();

    printf("\nExited the Program!\n\n");
    return 0;
}