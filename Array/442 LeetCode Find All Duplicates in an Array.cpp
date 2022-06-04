// Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/submissions/

// 1) using hashmap
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> Set;
        for (auto e:nums) if (++Map[e] == 2) Set.insert(e);
        return vector<int>(Set.begin(), Set.end());;
    }
private:
    unordered_map<int,int> Map;
};

// 2) try O(N) time, O(1) space approach