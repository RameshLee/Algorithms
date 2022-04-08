// Link: https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int sum=0, sum2=0, n=nums.size();
        for (int i=0; i<=n; i++) sum += i;
        for (int i=0; i<nums.size(); i++) sum2 += nums[i];

        return sum-sum2;

    }
};