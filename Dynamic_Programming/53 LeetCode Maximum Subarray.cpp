// Link: https://leetcode.com/problems/maximum-subarray/

// Kadane's algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0], sum = nums[0];
        for (int i=1; i<nums.size(); i++){
            sum = max(sum+nums[i],nums[i]);
            ret = max(ret, sum);
        }
        return ret;
    }
};
