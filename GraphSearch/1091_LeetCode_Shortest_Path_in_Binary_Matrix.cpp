// Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution {
public:
    int row; int col;
    vector<pair<int,int>> q;
    vector<vector<int>> distance;
    int x[8] = {1,-1,0,0,1,1,-1,-1};
    int y[8] = {0,0,1,-1,1,-1,1,-1};

    bool isSafe(int i, int j)
    {
        if (i>=0 && j>=0 && i<row && j<col)
            return true;
        else return false;
    }

    void BFS(vector<vector<int>>& grid)
    {
        while (!q.empty())
        {
            int i=q[0].first;
            int j=q[0].second;
            q.erase(q.begin());

            for (int k=0; k<8; k++)
                if (isSafe( i+x[k], j+y[k] ))
                    if (grid[i+x[k]][j+y[k]] == 0)
                        if (distance[i+x[k]][j+y[k]] == -1)
                        {
                            distance[i+x[k]][j+y[k]] = 1 + distance[i][j];
                            q.push_back( make_pair(i+x[k], j+y[k]) );
                        }
        }
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        row = grid.size(); col = grid[0].size();
        if (grid[0][0] == 1 || grid[row-1][col-1] == 1) return -1;
        distance.resize(row, vector<int>(col,-1));

        //bfs from top-left to bottom-right
        q.push_back(make_pair(0,0));
        distance[0][0] = 0;
        BFS(grid);

        if (distance[row-1][col-1] == -1) return -1;
        else return 1+distance[row-1][col-1];
    }
};