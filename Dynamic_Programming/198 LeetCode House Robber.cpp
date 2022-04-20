// Link: https://leetcode.com/problems/house-robber/

// Dynamic Programming
// 1) state variable: whether or not rob the current house at index i
// 2) recurrence relation: dp(i) = max( dp(i-1) , nums[i] + dp(i-2) )
// 3) base case: dp(0) = 1, dp(1) = 2;

class Solution {
public:
    unordered_map<int,int> Memo;

    int helper(int i, vector<int>& nums){
        // base-case
        if (i == 0) return nums[0];
        if (i == 1) return max(nums[0], nums[1]);
        if (Memo.find(i) != Memo.end()) return Memo[i];

        // recurrence relation
        return Memo[i] = max(helper(i-1,nums), nums[i] + helper(i-2, nums));
    }

    int rob(vector<int>& nums) {
        return helper(nums.size()-1, nums);
    }
};