// Link: https://leetcode.com/problems/fibonacci-number/

// Recursive approach with memoization: top-down DP

class Solution {
    int memo[1000];
public:
    int fib(int n) {

        if (n == 0) return 0;
        if (n == 1) return 1;
        if (memo[n] > 0) return memo[n];

        memo[n] = fib(n-1)+fib(n-2);
        return memo[n];
    }
};


/*
// bottom-up DP approach
class Solution {
public:
    int fib(int n) {
        int dp[1000];
        dp[0] = 0;
        dp[1] = 1;
        for (int i=2; i<=n; i++)
            dp[i] = dp[i-1] + dp[i-2];

        return dp[n];
    }
};*/