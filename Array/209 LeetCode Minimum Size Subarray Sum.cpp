// Link: https://leetcode.com/problems/minimum-size-subarray-sum/submissions/

// Two-pointer approach: T=O(n), S=O(1)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int l=0, r=0, sum=nums[0], len=INT_MAX;
        while (1){
            if (sum >= target) {
                len = min(len, 1+r-l);
                sum -= nums[l];
                l++;
            }
            else {
                r++;
                if (r<nums.size()) sum += nums[r];
            }

            if (r>=nums.size() && sum<target) break;
        }
        return (len == INT_MAX) ? 0 : len;
    }
};