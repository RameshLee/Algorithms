// Link: https://leetcode.com/problems/find-pivot-index/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int sum = 0;
        for (auto& it:nums) sum += it;

        int sum2 = 0;
        for (int i=0; i<nums.size(); i++){

            sum -= nums[i];
            if (i>0) sum2 += nums[i-1];

            if (sum == sum2) return i;
        }

        return -1;
    }
};