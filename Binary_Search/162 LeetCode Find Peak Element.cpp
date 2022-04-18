// Link: https://leetcode.com/problems/find-peak-element/

// 1) Linear scan: T=O(n), S=O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();
        for (int i=1; i<n-1; i++){
            if (nums[i-1] < nums[i] && nums[i] > nums[i+1])
                return i;
        }
        return (nums[0] > nums[n-1]) ? 0 : n-1;
    }
};