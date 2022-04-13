// Link: https://leetcode.com/problems/jump-game-ii

// Dynamic Programming:
// 1) Traverse from right to left.
// 2) For every node, update minSteps to reach the final node (NOTE: reaching final node is guaranteed in this problem!)
// 3) Return the minSteps to reach finalnode at index 0.

class Solution {
public:
    int jump(vector<int>& nums) {
        
        vector<int> ret(nums.size(), INT_MAX);
        ret[nums.size()-1] = 0;
        
        for (int i=nums.size()-2; i>=0; i--)
            for (int steps=1; steps<=nums[i]; steps++)
                if (i+steps < nums.size())
                    if (ret[i+steps] != INT_MAX) 
                        ret[i] = min(ret[i], 1 + ret[i+steps]);
        
        return ret[0];
    }
};