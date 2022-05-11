// Link: https://leetcode.com/problems/edit-distance/

// Top-down DP (tabulation)

#define MIN(a,b,c) min(min(a,b),c);

class Solution {
public:
    int minDistance(string A, string B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // base-cases
        for (auto i=1; i<=n; i++) dp[i][0] = i;
        for (auto j=1; j<=m; j++) dp[0][j] = j;

        // tabulation
        for (auto i=1; i<=n; i++)
            for (auto j=1; j<=m; j++)
                dp[i][j] = (A[i-1]==B[j-1]) ? dp[i-1][j-1] : 1+MIN(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
        return dp[n][m];
    }
};