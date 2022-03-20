// Link: https://leetcode.com/problems/richest-customer-wealth/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

        int val = 0;
        for (auto& it:accounts){
            int sum = 0;
            for (auto& ele:it) sum += ele;
            val = max(val,sum);
        }
        return val;
    }
};