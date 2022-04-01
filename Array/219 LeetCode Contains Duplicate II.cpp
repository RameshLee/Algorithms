// Link: https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int,vector<int>> Map; //val, indices
        for (int i=0; i<nums.size(); i++){
            if (Map.find(nums[i]) != Map.end()){ // check if val is repeated!
                vector<int> vec = Map[nums[i]]; // collect all indices of val
                for (auto& j:vec){
                    if (abs(j-i) <= k) // check condition
                        return true;
                }
            }
            Map[nums[i]].push_back(i);
        }
        return false;
    }
};