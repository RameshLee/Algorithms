// Link: https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0, sum2=0;
        for (auto i=0; i<=nums.size(); i++) sum += i;
        for (auto elem:nums)                sum2 += elem;
        return sum-sum2;
    }
};