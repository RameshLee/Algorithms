// Link: https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0,nums);
        return vector<vector<int>>(Set.begin(), Set.end());
    }
private:
    vector<int> vec; set<vector<int>> Set;

    void backtrack(int i, vector<int>& nums){

        if (i>nums.size()) return; // base-case
        Set.insert(vec); // update result

        for (int j=i; j<nums.size(); j++){ // for all candidates
            vec.push_back(nums[j]); // make move
            backtrack(j+1, nums); // backtrack
            vec.pop_back(); // undo move
        }
    }
};