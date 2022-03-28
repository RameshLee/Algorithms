// Link: https://leetcode.com/problems/find-the-difference-of-two-arrays/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        using vi = vector<int>;
        using vvi = vector<vi>;

        unordered_map<int,int> Map1, Map2;
        set<int> set1, set2;

        for (auto& it:nums1) Map1[it]++;
        for (auto& it:nums2) Map2[it]++;

        for (auto& it:nums1) if (!Map2[it]) set1.insert(it);
        for (auto& it:nums2) if (!Map1[it]) set2.insert(it);

        return vvi({vi(set1.begin(), set1.end()), vi(set2.begin(), set2.end())});
    }
};