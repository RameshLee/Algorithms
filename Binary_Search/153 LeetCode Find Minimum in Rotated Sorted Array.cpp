// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {

        // corner-cases
        if (nums[0] < nums[nums.size()-1]) return nums[0];
        if (nums.size() == 1) return nums[0];

        // binary search: find the rotationIndex
        int l=0, r=nums.size()-1;
        while (l<=r){
            int i = l + rand()%(r-l+1);
            if (nums[i] > nums[nums.size()-1]) {
                if (i+1<nums.size() && nums[i] > nums[i+1]) return nums[i+1];
                l = i+1;
            }
            else if (nums[i] < nums[0]) {
                if (i-1>=0 && nums[i-1] > nums[i]) return nums[i];
                r = i-1;
            }
        }
        return 0;
    }
};