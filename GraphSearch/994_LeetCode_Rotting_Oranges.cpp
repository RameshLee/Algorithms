// Link: https://leetcode.com/problems/rotting-oranges/

// Approach: bfs => T=O(N), S=O(1)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        row=grid.size(), col=grid[0].size();
        queue<pair<int,int>> q;

        // enqueue all rotten oranges: T=O(N)
        auto freshOranges = 0;
        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++) {
                if (grid[i][j] == ROTTEN)       q.push(make_pair(i,j));
                else if (grid[i][j] == FRESH)   freshOranges++;
            }

        // edge-case
        if (q.empty()) return (freshOranges) ? -1 : 0;

        // apply multistart BFS from all rotten oranges: T=O(N)
        for (ElapsedTime; !q.empty(); ElapsedTime++) {
            auto sz = q.size();
            for (auto loop=0; loop<sz; loop++) {
                auto i = q.front().first;
                auto j = q.front().second; q.pop();

                for (int k=0; k<4; k++)
                    if (isSafe( i+dir[k],j+dir[k+1] ))
                        if (grid[i+dir[k]][j+dir[k+1]] == FRESH) {
                            q.push(make_pair(i+dir[k],j+dir[k+1]));
                            grid[i+dir[k]][j+dir[k+1]] = ROTTEN;
                            freshOranges--;
                        }
            }
        }
        return (freshOranges) ? -1 : ElapsedTime;
    }
private:
    int row, col, dir[5] = {1,0,-1,0,1}, ElapsedTime = -1;
    enum State{EMPTY=0, FRESH=1, ROTTEN=2};

    bool isSafe(int i, int j) {
        return (i>=0 && j>=0 && i<row && j<col) ? true : false;
    }

};