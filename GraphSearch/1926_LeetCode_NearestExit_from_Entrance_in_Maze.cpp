// Link: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

//Algorithm:
// 1) check the exterior of the maze: if you find an empty cell, then jump to step 2.
// 2) apply BFS from the entrance cell.
//Time complexity = O(N), where N is the total cells in the grid.

class Solution {
public:
    char wall = '+';
    char route = '.';
    int output = -1;
    int row; int col;
    vector<vector<int>> distance;
    queue<pair<int,int>> q;
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};

    bool isSafe(int i, int j)
    {
        if (i>=0 && j>=0 && i<row && j<col) return true;
        else return false;
    }

    bool isExit(int i, int j)
    {
        if (i==0 || j==0 || i==row-1 || j==col-1) return true;
        else return false;
    }

    int BFS(vector<vector<char>>& grid, vector<int>& entrance)
    {
        while (!q.empty())
        {
            pair<int,int> val=q.front();
            int i = val.first;
            int j = val.second;
            q.pop();

            // make sure it is not the entrance but exit
            if (isExit(i,j))
                if (!(i==entrance[0] && j==entrance[1]))
                    return distance[i][j];

            for (int k=0; k<4; k++)
                if (isSafe( i+x[k], j+y[k] ))
                    if (grid[i+x[k]][j+y[k]] == route)
                    {
                        grid[i+x[k]][j+y[k]] = wall;
                        distance[i+x[k]][j+y[k]] = 1 + distance[i][j];
                        q.push(make_pair(i+x[k], j+y[k]));
                    }
        }
        return -1;
    }

    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance)
    {
        row=grid.size(); col=grid[0].size();
        distance.resize(row, vector<int>(col,0));
        int i; int j;

        // Special case: check whether the maze is surrounded by walls
        j=0;
        for (int i=0; i<row; i++)
            if (grid[i][j] == route)
                goto Jump;

        j=col-1;
        for (int i=0; i<row; i++)
            if (grid[i][j] == route)
                goto Jump;

        i=0;
        for (int j=0; j<col; j++)
            if (grid[i][j] == route)
                goto Jump;

        i=row-1;
        for (int j=0; j<col; j++)
            if (grid[i][j] == route)
                goto Jump;

        Jump:
        //otherwise, apply BFS from the entrance to find the nearest exit
        i=entrance[0];
        j=entrance[1];
        q.push(make_pair(i,j));
        grid[i][j] = wall;
        return BFS(grid, entrance);
    }
};