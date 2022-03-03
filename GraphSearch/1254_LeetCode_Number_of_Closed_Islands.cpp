// Link: https://leetcode.com/problems/number-of-closed-islands/

class Solution {
public:
    int IslandCount = 0;
    int foundIsland = 0;
    vector<vector<int>> visited;
    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,1,-1};
    int row;
    int col;

    bool isSafe(int i, int j)
    {
        if (i>=0 && j>=0 && i<row && j<col)
            return true;
        else
            return false;
    }

    bool isCornerDetected(int i, int j)
    {
        if (i-1<0 || j-1<0 || i+1>=row || j+1>=col)
            return true;
        else
            return false;
    }

    void DFS(vector<vector<int>>& grid, int i, int j)
    {
        if (visited[i][j] == 0)
        {
            if ( isCornerDetected(i,j) )
                foundIsland = 0;

            visited[i][j] = 1;
            for (int k=0; k<4; k++)
                if ( isSafe(i + x[k], j + y[k]) )
                    if (grid[i + x[k]][j + y[k]] == 0)
                        DFS(grid, i+x[k], j+y[k]);
        }
    }

    int closedIsland(vector<vector<int>>& grid)
    {
        row = grid.size(); col = grid[0].size();
        visited.resize(grid.size(), vector<int>(grid[0].size(), 0));

        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[0].size(); j++)
                if (!grid[i][j] && !visited[i][j])
                {
                    foundIsland = 1;
                    DFS(grid, i, j);
                    IslandCount += foundIsland;
                }

        return IslandCount;
    }
};