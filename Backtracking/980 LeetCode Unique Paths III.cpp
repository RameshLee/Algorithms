// Link: https://leetcode.com/problems/unique-paths-iii/

// Algorithm: apply dfs; If the next cell is destination, then check whether all empty cells are visited. If yes, update the number of paths.

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        // find total empty cells and starting point
        row = grid.size(); col = grid[0].size();

        // find robot position & compute total emptyCells
        int x,y;
        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++){
                if (grid[i][j] == SOURCE) x=i, y=j;
                if (grid[i][j] == EMPTY) emptyCells++;
            }

        // apply dfs
        backtrack(x,y,grid);
        return count;
    }
private:
    enum Cells{SOURCE=1, DESTINATION=2, EMPTY=0, OBSTACLE=-1, MARKER=INT_MAX};
    int count = 0, emptyCells = 0, visitedCells = -1;
    int row,col, x[4] = {0,1,0,-1}, y[4] = {1,0,-1,0};

    bool isSafe(int i, int j){
        return (i>=0 && j>=0 && i<row && j<col) ? true : false;
    }

    void backtrack(int i, int j, vector<vector<int>>& grid){

        // base-cases
        if (grid[i][j] == DESTINATION){
            if (visitedCells == emptyCells) count++;
            return;
        }
        if (grid[i][j] == OBSTACLE) return;
        if (grid[i][j] == MARKER) return;


        // make a move
        grid[i][j] = MARKER, visitedCells++;

        // for all candidates: backtrack
        for (int k=0; k<4; k++)
            if (isSafe( i+x[k], j+y[k] ))
                backtrack( i+x[k], j+y[k], grid);

        // undo move
        grid[i][j] = EMPTY, visitedCells--;
    }
};