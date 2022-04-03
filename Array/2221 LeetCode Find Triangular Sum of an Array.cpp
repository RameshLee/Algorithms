// Link: https://leetcode.com/contest/biweekly-contest-75/problems/find-triangular-sum-of-an-array/

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<vector<int>> vec(nums.size());
        vec[0] = nums;

        for (int i=1; i<vec.size(); i++){

            vec[i].resize(vec[i-1].size()-1);
            for (int j=0; j<vec[i].size(); j++) {
                vec[i][j] = (vec[i-1][j] + vec[i-1][j+1]) % 10;
            }
        }
        return vec[nums.size()-1][0];
    }
};