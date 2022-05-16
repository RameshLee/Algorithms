// Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/

// apply bfs from top-left to bottom-right
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        this->row = grid.size(), this->col = grid[0].size();
        if (grid[0][0] == 1 || grid[row-1][col-1] == 1) return -1;

        //bfs from top-left to bottom-right
        queue<pair<int,int>> q({make_pair(0,0)});
        grid[0][0] = 1; // update the distance
        while (!q.empty()) {
            auto i=q.front().first, j=q.front().second; q.pop();

            for (int k=0; k<8; k++)
                if (isSafe( i+dir[k], j+dir[k+1] ))
                    if (grid[i+dir[k]][j+dir[k+1]] == 0) {
                        grid[i+dir[k]][j+dir[k+1]] = 1 + grid[i][j];
                        q.push( make_pair(i+dir[k], j+dir[k+1]) );
                    }
        }
        return (grid[row-1][col-1]==0) ? -1 : grid[row-1][col-1];
    }
private:
    int row, col, dir[9] = {1,0,-1,0,1,-1,-1,1,1};

    bool isSafe(int i, int j) {
        return (i>=0 && j>=0 && i<row && j<col) ? true : false;
    }