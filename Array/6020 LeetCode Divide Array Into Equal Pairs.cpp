// Link: https://leetcode.com/contest/biweekly-contest-74/problems/divide-array-into-equal-pairs/

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        if (nums.size()%2 != 0) return false;
        
        unordered_map<int,int> Map;
        for (auto& it:nums){
            Map[it]++;
        }
        
        for (auto& it:nums)
            if (Map[it]%2 != 0)
                return false;
        
        return true;
        
    }
};