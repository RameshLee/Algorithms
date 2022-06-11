// Link: https://leetcode.com/problems/minimum-path-sum/

// dijkstra algorithm: shortest path from top-left to bottom-right

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        this->row = grid.size(), this->col = grid[0].size();

        vector<vector<int>> distance(row, vector<int>(col,INT_MAX));
        using pr = pair<int,pair<int,int>>;
        priority_queue<pr, vector<pr>, greater<pr>> pq;

        distance[0][0] = grid[0][0];
        pq.push(make_pair(grid[0][0],make_pair(0,0)));

        while (!pq.empty()) { // dijkstra algorithm using pq
            auto currDist = pq.top().first;
            auto i = pq.top().second.first;
            auto j = pq.top().second.second; pq.pop();

            for (auto k=0; k<2; k++) {
                if (isSafe(i+x[k],j+y[k]))
                    if (distance[i+x[k]][j+y[k]] > currDist + grid[i+x[k]][j+y[k]]) {
                        distance[i+x[k]][j+y[k]] = currDist + grid[i+x[k]][j+y[k]];
                        pq.push(make_pair(distance[i+x[k]][j+y[k]],make_pair(i+x[k],j+y[k])));
                    }
            }
        }
        return distance[row-1][col-1];
    }
private:
    int row, col, x[2] = {0,1}, y[2] = {1,0};

    bool isSafe(int i, int j){
        return (i>=0 && j>=0 && i<row && j<col) ? true : false;
    }
};