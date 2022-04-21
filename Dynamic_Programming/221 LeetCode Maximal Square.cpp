// Link: https://leetcode.com/problems/maximal-square/

// Dynamic programming (reason: 1) find largest, 2) optimal substructure)

// state variables: row i and col j
// recurrence relation: dp(i,j) = 1 + min(dp(i-1,j-1), dp(i-1,j), dp(i,j-1)); => if (mat[i][j] == 1)
// base-case: dp(i,j) = 0; if (i<0 || j<0)


// 1) bottom-up DP (tabulation)

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int result = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for (auto i=1; i<=n; i++)
            for (auto j=1; j<=m; j++)
                if (matrix[i-1][j-1] == '1'){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    result = max(result, dp[i][j]);
                }
        return result*result;
    }
};

// 2) top-down DP (recursion + memoization)

/*
class Solution {
public:
    int result;

    int helper(int i, int j, vector<vector<char>>& mat){
        // base-case
        if (i<1 || j<1) return 0;

        // recurrence-relation
        if (mat[i-1][j-1] == '1') {
            int val = min(helper(i-1,j-1,mat), min(helper(i-1,j,mat),helper(i,j-1,mat))) + 1;
            result = max(result, val);
            return val;
        }
        return 0;
    }

    int maximalSquare(vector<vector<char>>& matrix) {

        int n = matrix.size(), m = matrix[0].size();
        return helper(n,m,matrix);
        return result*result;
    }
};
*/