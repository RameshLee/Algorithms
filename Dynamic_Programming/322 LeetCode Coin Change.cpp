// Link: https://leetcode.com/problems/coin-change/

// Dynamic programming: (reason: 1) find minimum, 2) overlapping subproblems)
// state variables: choice of coins at index i
// recurrence relation: dp(amount) = 1 + { min(dp(amount-coins[i]) ; for all i in coins }
// base-case: dp(i) = 0, if amount=0, and dp(i)=huge_value, if amount<0.

// 1) Recursion with memoization

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        this->coins = coins;
        int result = helper(amount);
        return (result > 999999) ? -1 : result;
    }
private:
    vector<int> coins;
    unordered_map<int,int> Memo;

    int helper(int amount){
        // base-case
        if (amount == 0) return 0;
        if (amount < 0) return 999999;
        if (Memo[amount]) return Memo[amount];

        // recurrence
        int ans = INT_MAX;
        for (auto i=0; i<coins.size(); i++){
            ans = min(ans, 1+helper(amount-coins[i]));
        }
        return Memo[amount] = ans;
    }
};