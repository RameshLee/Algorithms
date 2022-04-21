// Link: https://leetcode.com/problems/longest-common-subsequence/

// Dynamic programming (reason: longest, optimal substructure exists!)

// state variables: index i & j that represents characters at text1 and text2
// recurrence: dp[i][j] = (X[i-1]==Y[j-1]) ? ( 1 + dp[i-1][j-1]) : (max(dp[i-1][j], dp[i][j-1]));
// base-case: dp(i,j) = 0; if (i<0 || j<0)


// 1) top-down DP (recursion + memoization)

class Solution {
public: string X,Y; int n,m; int Memo[1001][1001] = {0};
    int helper(int i, int j){
        // base-case
        if (i<=0 || j<=0) return 0;
        if (Memo[i][j]) return Memo[i][j];

        // recurrence-relation
        return Memo[i][j] = (X[i-1]==Y[j-1]) ? 1+helper(i-1,j-1) : max(helper(i-1,j), helper(i,j-1));
    }

    int longestCommonSubsequence(string X, string Y) {
        this->X = X, this->Y = Y;
        n = X.size(), m = Y.size();
        return helper(n,m);
    }
};


// 2) bottom-up DP (tabulation)


class Solution {
public:
    int longestCommonSubsequence(string X, string Y) {

        int n = X.size(), m = Y.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (auto i=1; i<=n; i++)
            for (auto j=1; j<=m; j++)
                dp[i][j] = (X[i-1]==Y[j-1]) ? ( 1 + dp[i-1][j-1]) : (max(dp[i-1][j], dp[i][j-1]));
        return dp[n][m];
    }
};
