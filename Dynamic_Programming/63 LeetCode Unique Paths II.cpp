// Link: https://leetcode.com/problems/unique-paths-ii/

// Before reaching any cell we would have the number of ways of reaching the predecessor cells. This is what makes it a Dynamic Programming.

// 1) top-down DP (recursion + memoization)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        this->row = grid.size(), this->col = grid[0].size();
        if (grid[0][0] == 1 || grid[row-1][col-1] == 1) return 0;
        return helper(0,0,grid);
    }
private:
    int row,col,Memo[101][101] = {0};

    int helper(int i, int j, vector<vector<int>>& grid) {
        if (i>=row || j>=col) return 0;
        if (i==row-1 && j==col-1) return 1;
        if (grid[i][j] == 1) return 0;
        if (Memo[i][j]) return Memo[i][j];
        return Memo[i][j] = helper(i+1,j,grid) + helper(i,j+1,grid);
    }
};

// 2) bottom-up DP (tabulation)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        this->row = grid.size(), this->col = grid[0].size();
        if (grid[0][0] == 1 || grid[row-1][col-1] == 1) return 0;

        vector<vector<int>> dp(row+1, vector<int>(col+1,0));
        dp[0][1] = 1;
        for (auto i=1; i<=row; i++)
            for (auto j=1; j<=col; j++)
                if (!grid[i-1][j-1])
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[row][col];
    }
private:
    int row,col;
};