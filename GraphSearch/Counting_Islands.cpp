// C++ program for counting islands problem using Disjoint set algorithm with O(log(n)) worst-case time complexity

#include <iostream>
#include <vector>
using namespace std;

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

    void print(int perform = 0)
    {
        // print value
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
                printf("%d ", node[i*col+j].value);//find_parent(i*col+j));
            printf("\n");
        }
        printf("\n");

        // print index
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
                printf("%d ", i*col+j);//find_parent(i*col+j));
            printf("\n");
        }
        printf("\n");

    }

    int find_parent(int i)
    {
        while(node[i].root != i) //with path compression
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

        if (x != y)
        {
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
    }

    void Count_Islands()
    {
        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
            {
                //check at 8 directions
                //1) right
                if (j+1 < col && node[i*col+j].value == 1)
                    if (node[(i*col)+(j+1)].value == 1)
                        unify(i*col+j, (i*col)+(j+1));

                //2) left
                if (j-1 >= 0 && node[i*col+j].value == 1)
                    if (node[(i*col)+(j-1)].value == 1)
                        unify(i*col+j, (i*col)+(j-1));

                //3) top
                if ((i-1) >= 0 && node[i*col+j].value == 1)
                    if (node[((i-1)*col)+j].value == 1)
                        unify(i*col+j, ((i-1)*col)+j);

                //4) bottom
                if ((i+1) < row && node[i*col+j].value == 1)
                    if (node[((i+1)*col)+j].value == 1)
                        unify(i*col+j, ((i+1)*col)+j);

                //5) bottom-left
                if ((i+1) < row && (j-1) >= 0 && node[i*col+j].value == 1)
                    if (node[((i+1)*col)+j-1].value == 1)
                        unify(i*col+j, ((i+1)*col)+j-1);

                //6) bottom-right
                if ((i+1) < row && (j+1) < col && node[i*col+j].value == 1)
                    if (node[((i+1)*col)+j+1].value == 1)
                        unify(i*col+j, ((i+1)*col)+j+1);

                //7) top-left
                if ((i-1) >= 0 && (j-1) >= 0 && node[i*col+j].value == 1)
                    if (node[((i-1)*col)+j-1].value == 1)
                         unify(i*col+j, ((i-1)*col)+j-1);

                //8) top-right
                if ((i-1) >= 0 && (j+1) < col && node[i*col+j].value == 1)
                    if (node[((i-1)*col)+j+1].value == 1)
                         unify(i*col+j, ((i-1)*col)+j+1);
            }


          // print utility
          /*for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
                if (node[i*col+j].value == 1)
                    printf("(%d,%d): node[%d].root = %d, value=%d\n",i,j,i*col+j,node[i*col+j].root, node[i*col+j].value);
           */

         // print the total islands
         int TotalIslands = 0;
         vector<int> vec(row*col, 0);
         for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
                if (node[i*col+j].value == 1)
                {
                    if (vec[ node[i*col+j].root ] == 0)
                    {
                        vec[ node[i*col+j].root ] = 1;
                        TotalIslands++;
                    }
                }
         printf("Total Islands: %d\n", TotalIslands);


    }

};

int main()
{
    /*int row = 5; int col = 5;
    vector<vector<int>> Matrix = {
                         {1, 1, 0, 0, 0},
                         {0, 1, 0, 0, 1},
                         {1, 0, 0, 1, 1},
                         {0, 0, 0, 0, 0},
                         {1, 0, 1, 0, 1}};*/
                         //TotalIslands: 5

    int row = 10; int col = 10;
    vector<vector<int>> Matrix = {
                        { 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
                        { 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
                        { 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
                        { 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
                        { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
                        { 0, 1, 0, 1, 0, 0, 1, 1, 1, 1 },
                        { 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
                        { 0, 0, 0, 1, 0, 0, 1, 1, 1, 0 },
                        { 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
                        { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 }};
                        //TotalIslands: 5

    DisjointSet DS;
    DS.makeset(row, col, Matrix);
    DS.print();
    DS.Count_Islands();

    printf("\nExited the Program!\n\n");
    return 0;
}