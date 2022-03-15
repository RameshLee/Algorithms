// Link: https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> Map;
        
        for (auto& it:nums) if (++Map[it] > 1) return true;
        
        return false;
        
    }
};