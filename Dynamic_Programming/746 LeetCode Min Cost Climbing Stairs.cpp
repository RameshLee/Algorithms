// 1) Top-down DP: Recursion with Memoization

// Dynamic programming: (reason: find minimum, future decisions are affected by current decisions)

// state variables: taking a current step at index i
// recurrence relation: dp(i) = cost[i] + min(dp(i-1),dp(i-2)); // reach current from previous or prev-to-prev step.
// base-case: dp(0)=cost[0], dp(1)=cost[1];

// 1) top-down dynamic programming

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(helper(0, cost), helper(1, cost));
    }
private:
    int memo[100000] = {0};
    int helper(int i, vector<int>& cost){
        if (i>=cost.size()) return 0;
        if (memo[i]) return memo[i];
        return memo[i] = cost[i] + min(helper(i+1,cost), helper(i+2,cost));
    }
};

// 2) bottom-up dynamic programming

/*class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n =cost.size();
        vector<int> dp(n);
        dp[0] = cost[0]; dp[1] = cost[1];
        for (int i=2; i<n; i++)
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        return min(dp[n-1],dp[n-2]);
    }

};*/

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