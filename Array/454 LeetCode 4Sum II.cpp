// Link: https://leetcode.com/problems/4sum-ii/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)     {
        unordered_map<int,int> Map, Map2;

        // combine the first two vecs
        for (auto i:nums1)
            for (auto j:nums2)
                Map[i+j]++;

        // combine the second two vecs
        for (auto i:nums3)
            for (auto j:nums4)
                Map2[i+j]++;

        // record count if the sum of first & second vecs leads to target
        int count = 0;
        for (auto it=Map.begin(); it!=Map.end(); it++){
            int complement = (-1) * it->first;
            if (Map2.find(complement) != Map2.end())
                count += (it->second * Map2[complement]);
        }
        return count;
    }
};