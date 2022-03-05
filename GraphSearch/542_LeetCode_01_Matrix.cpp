// Link: https://leetcode.com/problems/01-matrix/

class Solution {
public:
    int Marker;
    int row; int col;
    vector<vector<int>> output;
    vector<vector<int>> distance;
    queue<pair<int,int>> q;
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};

    bool isSafe(int i, int j)
    {
        if (i>=0 && j>=0 && i<row && j<col) return true;
        else return false;
    }

    void BFS(vector<vector<int>>& grid)
    {
        while(!q.empty())
        {
            pair<int,int> val = q.front();
            int i = val.first;
            int j = val.second;
            q.pop();

            for (int k=0; k<4; k++)
                if (isSafe( i+x[k], j+y[k] ))
                    if (grid[i+x[k]][j+y[k]] == 1)
                    {
                        q.push(make_pair(i+x[k],j+y[k]));
                        distance[i+x[k]][j+y[k]] = 1 + distance[i][j];
                        grid[i+x[k]][j+y[k]] = 0;
                        output[i+x[k]][j+y[k]] = distance[i+x[k]][j+y[k]];
                    }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& grid)
    {
        row=grid.size(); col=grid[0].size();
        distance.resize(row, vector<int>(col,0));
        output.resize(row, vector<int>(col,0));

        // 1) store all the starting points
        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
                if (grid[i][j] == 0)
                {
                    output[i][j] = 0;
                    q.push(make_pair(i,j));
                }

        // 2) multi-start BFS from all 0's towards all 1's
        BFS(grid);

        return output;
    }
};