// Link: https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int Max=0, count = 0;
        for (auto& it:nums){
            count = (it == 1) ? ++count : 0;
            Max=max(Max,count);
        }
        return Max;
    }
};