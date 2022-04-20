// Link: https://leetcode.com/problems/climbing-stairs/

//1) Dynamic programming approach

class Solution {
public:
    int climbStairs(int n){
        long dp[60];
        dp[0] = 1;
        dp[1] = 2;
        for (int i=2; i<n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n-1];
    }
};

// 2) Recursion with memoization


class Solution {
    int memo[100] = {0};
public:
    int climbStairs(int n, int i=0){

        if (i==n) return 1;
        if (i>n) return 0;
        if (memo[i]>0) return memo[i];

        memo[i] = climbStairs(n,i+1) + climbStairs(n,i+2);
        return memo[i];
    }
};