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

// 2) Recursion

class Solution {
public:
    int climbStairs(int n) {
        return climb(0,n);
    }

    int climb(int i, int n){

        if (i==n) return 1;
        if (i>n) return 0;

        return climb(i+1,n) + climb(i+2,n);
    }
};

// 3) Recursion with memoization

class Solution {
public:
    unordered_map<int,int> Map;

    int climbStairs(int n) {
        return climb(0,n);
    }

    int climb(int i, int n){

        if (i==n) return 1;
        if (i>n) return 0;
        if (Map.find(i) != Map.end()) return Map[i];

        Map[i] = climb(i+1,n) + climb(i+2,n);
        return Map[i];
    }
};