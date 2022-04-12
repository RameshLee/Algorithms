// Link: https://leetcode.com/problems/unique-paths-iii/

// Algorithm: apply dfs; If the next cell is destination, then check whether all empty cells are visited. If yes, update the number of paths.

class Solution {
public:
    int paths = 0, emptyCells = 0, visitedCells = -1, Marker = 4;
    int row,col;
    int x[4] = {0,1,0,-1};
    int y[4] = {1,0,-1,0};

    bool isSafe(int i, int j){
        if (i>=0 && j>=0 && i<row && j<col) return true;
        return false;
    }

    void backtrack(int i, int j, vector<vector<int>>& grid){

        // base-case
        if (grid[i][j] == 2){
            if (visitedCells == emptyCells) paths++;
            return;
        }

        // for all candidates
        if (grid[i][j] != Marker)
        {
            // make a move
            grid[i][j] = Marker;
            visitedCells++;

            // backtrack
            for (int k=0; k<4; k++)
                if (isSafe( i+x[k], j+y[k] ))
                    if (grid[i+x[k]][j+y[k]] != -1)
                        dfs( i+x[k], j+y[k], grid);

            // undo move
            grid[i][j] = 0;
            visitedCells--;
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        // find total empty cells and starting point
        row = grid.size(); col = grid[0].size();
        int x,y;
        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++){
                if (grid[i][j] == 1) x=i, y=j;
                if (grid[i][j] == 0) emptyCells++;
            }

        // apply dfs
        backtrack(x,y,grid);
        return paths;
    }
};