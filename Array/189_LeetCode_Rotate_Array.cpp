// Link: https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); k = k%n;
        std::reverse(nums.begin(),          nums.begin()+(n-k));
        std::reverse(nums.begin()+(n-k),    nums.end());
        std::reverse(nums.begin(),          nums.end());
    }
};