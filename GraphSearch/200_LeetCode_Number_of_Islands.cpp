// Link: https://leetcode.com/problems/number-of-islands/

// 1) using dfs: T=O(N), S=O(1)

class Solution {
private: int row,col, x[4]={1,-1,0,0}, y[4]={0,0,1,-1};
         enum Area{Water='0', Land='1', Visited='2'};
public:

    bool isSafe(int i, int j) { return (i>=0 && j>=0 && i<row && j<col) ? true : false; }

    void dfs(int i, int j, vector<vector<char>>& grid){
        if (grid[i][j] == Land){
            grid[i][j] = Visited;
            for (int k=0; k<4; k++){
                if (isSafe( i+x[k], j+y[k] ))
                    dfs(i+x[k], j+y[k], grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        row = grid.size(), col = grid[0].size();
        int count = 0;
        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
                if (grid[i][j] == Land){
                    dfs(i,j,grid); count++;
                }
        return count;
    }
};

// 1) using disjoint set: T=O(N), S=O(N)

struct Node
{
    int value; //1-land,0-water
    int rank;
    int root;

    Node(int a, int b) {value=(int)a-48; root=b; rank=0;}
    ~Node() {}
};

class Solution
{
public:
    int row, col;
    vector<Node> node;
    int x[4] = {0,0,-1,1};
    int y[4] = {-1,1,0,0};
    int TotalIslands = 0;

    bool isSafe(int i, int j)
    {
        if (i>=0 && j>=0 && i<row && j<col)
            return true;
        else
            return false;
    }

    void makeset(int n, int m, vector<vector<char>> &M)
    {
        row = n; col = m;
        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
                node.push_back(Node(M[i][j],i*col+j));
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
                if (node[i*col+j].value)
                    for (int k=0; k<4; k++) //check at 4 directions
                        if (isSafe(i+x[k],j+y[k]))
                            if (node[((i+x[k])*col)+((j+y[k]))].value == 1)
                                unify(i*col+j, ((i+x[k])*col)+(j+y[k]));


         // print the total islands
         vector<int> vec(row*col, 0);
         for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
                if (node[i*col+j].value == 1)
                {
                    if (vec[ find_parent(i*col+j) ] == 0)
                    {
                        vec[ find_parent(i*col+j) ] = 1;
                        TotalIslands++;
                    }
                }

    }

    int numIslands(vector<vector<char>>& grid) {

        row = grid.size(); col = grid[0].size();
        makeset(row, col, grid);
        Count_Islands();
        return TotalIslands;

    }
};
