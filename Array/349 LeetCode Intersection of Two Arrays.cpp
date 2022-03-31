// Link: https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> Set;
        unordered_map<int,int> Map;
        for (auto& it:nums1) Map[it]++;
        for (auto& it:nums2) if (Map[it] > 0) Set.insert(it);

        return vector<int>(Set.begin(), Set.end());
    }
};