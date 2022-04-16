// Link: https://leetcode.com/problems/01-matrix/

class Solution {
private: int row, col, Marker, x[4]={1,-1,0,0}, y[4]={0,0,1,-1};
public:
    bool isSafe(int i, int j){ return (i>=0 && j>=0 && i<row && j<col) ? true : false; }

    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        row=grid.size(); col=grid[0].size();
        vector<vector<int>> distance(row, vector<int>(col,0));
        queue<pair<int,int>> q;

        // 1) store all the starting points
        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
                if (grid[i][j] == 0)
                    q.push(make_pair(i,j));

        // 2) multi-start BFS from all 0's towards all 1's
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second; q.pop();

            for (int k=0; k<4; k++)
                if (isSafe( i+x[k], j+y[k] ))
                    if (grid[i+x[k]][j+y[k]] == 1){
                        q.push(make_pair(i+x[k],j+y[k]));
                        distance[i+x[k]][j+y[k]] = 1 + distance[i][j];
                        grid[i+x[k]][j+y[k]] = 0;
                    }
        }
        return distance;
    }
};