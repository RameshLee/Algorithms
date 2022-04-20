// Link: https://leetcode.com/problems/n-th-tribonacci-number/

// 1) top-down dynamic programming (recursive + memoization)

// state variables: current fibonnaci number at index i
// recurrence relation: dp(i) = dp(i-1) + dp(i-2) + dp(i-3)
// base-case: dp(0)=0, dp(1)=1, dp(2)=1

class Solution {
public:
    unordered_map<int,int> Memo;

    int tribonacci(int n) {
        // base-case
        if (n==0) return 0;
        if (n==1 || n==2) return 1;
        if (Memo.find(n) != Memo.end()) return Memo[n];

        // recurrence relation
        return Memo[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};

// 2) bottom-up dynamic programming (tabulation)

/*
class Solution {
public:
    int tribonacci(int n) {
        int dp[40];
        dp[0]=0; dp[1]=1; dp[2]=1;
        for (int i=3; i<=n; i++)
            dp[i] = dp[i-3]+dp[i-2]+dp[i-1];
        return dp[n];
    }
};
*/