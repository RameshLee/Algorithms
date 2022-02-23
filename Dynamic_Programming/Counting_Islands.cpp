// C++ program for counting islands problem using Disjoint set algorithm

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct node
{
    pair<int,int> index;
    pair<int,int> root;
    int rank;

    node() {rank=0;}
    ~node() {}

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

    pair parent(pair i)
    {
        //find parent
        while (i.first != Node[i].root.first)
        {
            Node[i].root = Node[ Node[i].root ].root;
            i = Node[i].root;
        }
        return i;
    }

    void unify(int i, int j)
    {
        // "path-compression" can be used to further improve the time complexity of Union-Find
        if (Node[parent(i)].rank > Node[parent(j)].rank) //parent of i will point to parent of j
            Node[parent(j)].root = i;
        else if (Node[parent(i)].rank < Node[parent(j)].rank) //parent of j will point to parent of i
            Node[parent(i)].root = parent(j);
        else if (Node[parent(i)].rank == Node[parent(j)].rank)
        {
            Node[parent(i)].root = parent(j);
            Node[parent(j)].rank += 1;
        }
    }
};