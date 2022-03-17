// Link: https://leetcode.com/problems/sign-of-the-product-of-an-array/

class Solution {
public:
    int arraySign(vector<int>& nums) {

        int negative = 0;
        for (auto& it:nums)
        {
            if (it == 0) return 0;
            else if (it<0) negative++;
        }
        if (negative%2 == 0) return 1;
        return -1;

    }
};