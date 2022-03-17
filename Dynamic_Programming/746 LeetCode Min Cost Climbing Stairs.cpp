// 1) Top-down DP: Recursion with Memoization

class Solution {
public:
    int n;
    int Memo[1000];
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        return min(climb(0,n, cost), climb(1,n,cost));
    }

    int climb(int i, int n, vector<int>& cost){
        if (i == n) return 0;
        if (i>n) return INT_MAX-2000;
        if (Memo[i] != 0) return Memo[i];

        Memo[i] = min(cost[i] + climb(i+1,n,cost), cost[i] + climb(i+2,n,cost));
        return Memo[i];
    }
};

// 2) Bottom-up DP: Dynamic Programming
// Intuition: recursive approach only cares about 2 steps below the current step

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n =cost.size();
        vector<int> dp(n);
        dp[0] = cost[0]; dp[1] = cost[1];
        for (int i=2; i<n; i++)
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        return min(dp[n-1],dp[n-2]);
    }

};