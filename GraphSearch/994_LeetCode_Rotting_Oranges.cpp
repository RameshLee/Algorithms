// Link: https://leetcode.com/problems/rotting-oranges/

class Solution
{
public:
    int ElapsedTime = -1;
    int row; int col;
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
        while (!q.empty())
        {
            int size = q.size();
            for (int level=0; level<size; level++)
            {
                pair<int,int> val = q.front();
                int i = val.first;
                int j = val.second;
                q.pop();

                for (int k=0; k<4; k++)
                    if (isSafe( i+x[k],j+y[k] ))
                        if (grid[i+x[k]][j+y[k]] == 1)
                        {
                            grid[i+x[k]][j+y[k]] = 2;
                            q.push(make_pair(i+x[k],j+y[k]));
                        }
            }
            ElapsedTime++;
        }
    }

    int orangesRotting(vector<vector<int>>& grid)
    {
        row=grid.size(); col=grid[0].size();

        //enqueue all rotten oranges
        int found_FreshOranges = 0;
        int found_EmptyCells = 0;
        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
            {
                if (grid[i][j] == 2) q.push(make_pair(i,j));
                else if (!found_FreshOranges && grid[i][j] == 1) found_FreshOranges = 1;
                else if (!found_EmptyCells) found_EmptyCells = 1;
            }

        //corner-case
        if (q.empty())
        {
            if (found_EmptyCells && !found_FreshOranges) return 0;
            else if (!found_EmptyCells && found_FreshOranges) return -1;
        }

        // apply multi-BFS from all rotten oranges
        BFS(grid);

        // recheck whether all oranges had got rotten!
        for (auto& row:grid)
            for (auto& elem:row)
                if (elem == 1) return -1;

        return ElapsedTime;
    }
};