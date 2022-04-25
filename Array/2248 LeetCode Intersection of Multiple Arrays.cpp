// Link: https://leetcode.com/problems/intersection-of-multiple-arrays/

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> Map;
        for (auto& row:nums)
            for (auto e:row)
                Map[e]++;

        vector<int> vec;
        for (auto it=Map.begin(); it!=Map.end(); it++)
            if (it->second >= nums.size())
                vec.push_back(it->first);
        sort(vec.begin(), vec.end());
        return vec;
    }
};