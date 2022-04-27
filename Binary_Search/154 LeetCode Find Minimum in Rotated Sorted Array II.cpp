// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while (l<=r){
            int i = l + (r-l)/2;
            if (nums[i] < nums[r]){
                r = i;
            }
            else if (nums[i] > nums[r]){
                l = i+1;
            }
            else r--;
        }
        return nums[l];
    }
};
