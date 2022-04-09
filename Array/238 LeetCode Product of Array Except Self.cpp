// Link: https://leetcode.com/problems/product-of-array-except-self/

// 1) Linear search (without using division): T=O(n), S=O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> prefixProd(nums.size(),0);
        vector<int> suffixProd(nums.size(),0);

        prefixProd[0] = 1;
        for (int i=1; i<nums.size(); i++)
            prefixProd[i] = nums[i-1]*prefixProd[i-1];

        suffixProd[nums.size()-1] = 1;
        for (int i=nums.size()-2; i>=0; i--)
            suffixProd[i] = nums[i+1]*suffixProd[i+1];

        vector<int> ret;
        for (int i=0; i<nums.size(); i++)
            ret.push_back(prefixProd[i] * suffixProd[i]);
        return ret;
    }
};


// 2) Linear search (using division): T=O(n), S=O(1)

/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> vec;

        int prod = 1; int nonZeroCount = 0, zeroCount = 0;
        for (auto& it:nums) {
            prod *= it;
            if (it > 0) nonZeroCount++;
            if (it == 0) zeroCount++;
        }

        // take care of edge cases
        if (zeroCount > 1){
            for (auto& it:nums) vec.push_back(0);
        }
        else if (zeroCount && nonZeroCount){
            prod = 1; for (auto& it:nums) if (it != 0) prod *= it;
            for (auto& it:nums) vec.push_back((it==0) ? prod : 0);
        }
        else{
            for (auto& it:nums) vec.push_back(prod/it);
        }
        return vec;
    }
};
*/