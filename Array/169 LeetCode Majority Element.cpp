// Link: https://leetcode.com/problems/majority-element-ii/

// 1) One-pass algorithm: T=O(N*logN), S=O(1) ==> constant-space

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0, prev = nums[0];
        for (auto i : nums) {
            if (prev == i) count++;
            else {
                prev = i;
                count = 1;
            }
            if (count > n/2) return prev;
        }
        return -1;
    }
};