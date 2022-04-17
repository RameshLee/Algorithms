// Link: https://leetcode.com/problems/find-closest-number-to-zero/

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int Val = INT_MAX;
        vector<int> closest;

        for (auto it: nums){
            Val = min(abs(it),Val);
        }
        for (auto it: nums){
            if (abs(it) == Val)
                closest.push_back(it);
        }
        sort(closest.rbegin(), closest.rend());
        return closest[0];
    }
};