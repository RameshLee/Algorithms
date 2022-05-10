// Link: https://leetcode.com/problems/house-robber-iii/

// dynamic programming: reason 1) find max, 2) current choice affects future choices.

// state variables: index i at which current house is being robbed!
// recurrence relation: dp(i) = max( dp(i-1), dp(i-2)+cost[i] );
// base-case: dp(0) = cost[0], dp(1) = max(cost[0],cost[1]);

// 1) bottom-up (recursion + memoization)
class Solution {
public:
    int rob(vector<int>& cost) {
        // corner-cases
        if (cost.size() == 1) return cost[0];
        if (cost.size() == 2) return max(cost[0],cost[1]);

        vector<int> A = vector<int>(cost.begin(),   cost.end()-1); // exclude house 1
        vector<int> B = vector<int>(cost.begin()+1, cost.end());   // exclude house n
        return max(houseRobber(A), houseRobber(B));
    }
private:
    vector<int> cost; int n; unordered_map<int,int> Memo;

    int helper(int i) {
        if (i == 0) return cost[0];
        if (i == 1) return max(cost[0], cost[1]);
        if (Memo.find(i) != Memo.end()) return Memo[i];
        return Memo[i] = max(helper(i-1), helper(i-2) + cost[i]);
    }

    int houseRobber(vector<int> cost) {
        this->cost = cost;
        this->n = cost.size();
        this->Memo.clear();
        return helper(n-1);
    }
};

// 2) top-down (tabulation)
class Solution {
public:
    int rob(vector<int>& cost) {
        // corner-cases
        if (cost.size() == 1) return cost[0];
        if (cost.size() == 2) return max(cost[0],cost[1]);

        vector<int> A = vector<int>(cost.begin(),   cost.end()-1); // exclude house 1
        vector<int> B = vector<int>(cost.begin()+1, cost.end());   // exclude house n
        return max(houseRobber(A), houseRobber(B));
    }
private:
    int houseRobber(vector<int> cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0], dp[1] = max(cost[0],cost[1]);
        for (auto i=2; i<cost.size(); i++) {
            dp[i] = max( dp[i-1], dp[i-2]+cost[i] );
        }
        return dp[n-1];
    }
};