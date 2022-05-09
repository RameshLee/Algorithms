// Link: https://leetcode.com/problems/unique-paths/

// 1) top-down DP (recursion + memoization)
// Algo: explore all possible paths from every possible path.
class Solution {
public:
    int uniquePaths(int m, int n) {
        this->m = m, this->n = n;
        return helper(0,0);
    }
private:
    int m,n; int Memo[101][101] = {0};

    int helper(int i, int j) {
        if (i>=m || j>=n) return 0;
        if (i==m-1 && j==n-1) return 1;
        if (Memo[i][j]) return Memo[i][j];
        return Memo[i][j] = helper(i+1,j) + helper(i,j+1);
    }
};