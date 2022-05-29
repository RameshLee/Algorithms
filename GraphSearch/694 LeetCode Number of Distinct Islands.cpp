// Link: https://leetcode.com/problems/number-of-distinct-islands/

// apply dfs and use hashset to avoid duplicate island structures
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (grid[i][j]) {
                    // apply dfs
                    island.clear();
                    dfs(i,j,0,0,grid);

                    // add island into islandSet
                    std::sort(island.begin(), island.end());
                    string s;
                    for (auto e:island) {
                        s += "(" + to_string(e.first) + "," + to_string(e.second) + ")";
                    }
                    islandSet.insert(s);
                }
            }
        }
        return islandSet.size();
    }
private:
    enum Status{LAND=1, WATER=0}; int row, col, dir[5]={1,0,-1,0,1};
    unordered_set<string> islandSet; vector<pair<int,int>> island;

    bool isSafe(int i, int j, int x, int y) {
        return (i>=0 && j>=0 && i<row && j<col) ? true : false;
    }

    void dfs(int i, int j, int x, int y, vector<vector<int>>& grid) {
        if (grid[i][j] == WATER) return;

        grid[i][j] = WATER;
        island.push_back(make_pair(x,y));

        for (int k=0; k<4; k++)
            if (isSafe( i+dir[k], j+dir[k+1], x+dir[k], y+dir[k+1]))
                dfs(i+dir[k], j+dir[k+1], x+dir[k], y+dir[k+1], grid);
    }
};