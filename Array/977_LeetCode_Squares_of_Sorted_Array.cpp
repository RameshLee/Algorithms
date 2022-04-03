// Link: https://leetcode.com/problems/squares-of-a-sorted-array/


// One-pass algorithm: Find the middle element, and merge the two sorted arrays going in opp directions.
// T=O(n), S=O(n)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums){

        vector<int> ret(nums.size());

        // find the first indices (l,r) for two vectors going in opposite direction
        int l=-1;
        for (int i=0; i<nums.size(); i++) if (nums[i] < 0) l = i;
        int r=l+1;

        // square all numbers
        for (auto& it:nums) it=pow(it,2);

        // similar to merging two sorted vectors
        int index = 0;
        while (l>=0 || r<nums.size()){
            if (l<0)                        ret[index++] = nums[r], r++;
            else if (r>=nums.size())        ret[index++] = nums[l], l--;
            else if (nums[l] < nums[r])     ret[index++] = nums[l], l--;
            else                            ret[index++] = nums[r], r++;
        }
        return ret;
    }
};