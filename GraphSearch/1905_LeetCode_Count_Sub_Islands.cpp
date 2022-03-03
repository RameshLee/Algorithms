// Link: https://leetcode.com/problems/count-sub-islands/

class Solution {
public:
    int SubIslandFound = 0;
    int TotalSubIslands = 0;
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

    int DFS(vector<vector<int>>& grid_1, vector<vector<int>>& grid, int i, int j)
    {
        if (grid[i][j])
        {
            if (grid[i][j] != grid_1[i][j]) //check overlap of lands
                SubIslandFound = 0;

            grid[i][j] = 0; //mark as visited
            for (int k=0; k<4; k++)
                if ( isSafe(i + x[k], j + y[k]) )
                    DFS(grid_1, grid, i+x[k], j+y[k]);
        }

        return SubIslandFound;
    }

    int countSubIslands(vector<vector<int>>& grid_1, vector<vector<int>>& grid)
    {
        // As we traverse the grid2, check whether land(1) is present on grid1 during each full DFS traversal

        row = grid.size(); col = grid[0].size();

        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
                if (grid[i][j])
                {
                    SubIslandFound = 1;
                    TotalSubIslands += DFS(grid_1, grid, i, j);
                }
        return TotalSubIslands;
    }
};