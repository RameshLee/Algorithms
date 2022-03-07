// Link: https://leetcode.com/problems/shortest-bridge/

//Algorithm:
//1) find any 1's from the first grid
//2) traverse on the first grid to enqueue all 1's
//3) apply multi-BFS from the first grid until reaching any 1's of the second grid
// Time complexity = O(N), where N->total cells in grid

class Solution {
public:
    int Output = 0;
    int row; int col;
    queue<pair<int,int>> q;
    vector<vector<int>> distance;
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};

    bool isSafe(int i, int j)
    {
        if (i>=0 && j>=0 && i<row && j<col) return true;
        else return false;
    }

    void BFS(vector<vector<int>>& grid)
    {
        while (!q.empty())
        {
            pair<int,int> val = q.front();
            int i = val.first;
            int j = val.second;
            q.pop();

            for (int k=0; k<4; k++)
                if (isSafe( i+x[k], j+y[k] ))
                    if (grid[i+x[k]][j+y[k]] == 1)
                    {
                        grid[i+x[k]][j+y[k]] = 2;
                        q.push(make_pair(i+x[k],j+y[k]));
                    }
        }
    }

    void multi_BFS(vector<vector<int>>& grid)
    {
        int found = 0;
        while (!q.empty())
        {
            pair<int,int> val = q.front();
            int i = val.first;
            int j = val.second;
            q.pop();

            for (int k=0; k<4; k++)
                if (isSafe( i+x[k], j+y[k] ))
                    if (grid[i+x[k]][j+y[k]] != 2)
                    {
                        if (grid[i+x[k]][j+y[k]] == 1)
                            Output = distance[i][j];

                        if (Output) return;

                        distance[i+x[k]][j+y[k]] = 1 + distance[i][j];
                        grid[i+x[k]][j+y[k]] = 2;
                        q.push(make_pair(i+x[k],j+y[k]));

                    }
        }
    }

    int shortestBridge(vector<vector<int>>& grid)
    {
        row=grid.size(); col=grid[0].size();
        distance.resize(row, vector<int>(col,0));

        //1) find any 1's from the first grid
        pair<int,int> Start;
        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
                if (grid[i][j] == 1)
                {
                    Start = make_pair(i,j);
                    goto EndOfLine;
                }
        EndOfLine:

        //2) traverse on the first grid to enqueue all 1's
        int i=Start.first;
        int j=Start.second;
        grid[i][j] = 2;
        q.push(make_pair(i,j));
        BFS(grid);

        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
                if (grid[i][j] == 2)
                    q.push(make_pair(i,j));

       //2) apply multi-BFS from the first grid until reaching any 1's of the second grid
        multi_BFS(grid);

        return Output;
    }
};