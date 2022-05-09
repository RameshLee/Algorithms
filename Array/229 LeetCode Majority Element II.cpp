// Link: https://leetcode.com/problems/majority-element-ii/

// Using hashmap

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        unordered_map<int,int> Map;
        for (auto i:nums) {
            Map[i] = (Map.find(i) == Map.end()) ? 1 : Map[i]+1;
        }
        for (auto it=Map.begin(); it!=Map.end(); it++) {
            if (it->second > floor(nums.size()/3) )
                result.push_back(it->first);
        }
        return result;
    }
};