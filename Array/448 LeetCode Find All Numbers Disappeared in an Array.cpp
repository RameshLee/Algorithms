// Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        unordered_map<int,int> Map;
        for (auto& it:nums) Map[it]++;

        vector<int> vec;
        for (int i=1; i<=nums.size(); i++){
            if (Map.find(i) == Map.end())
                vec.push_back(i);
        }
        return vec;
    }
};