// Link: https://leetcode.com/problems/find-peak-element/

// Binary search: T=O(log N), S=O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int l=0, r=nums.size()-1;
        bool leftCond = false, rightCond = false; int left,right;
        while (l<=r){

            int i = l + rand()%(r-l+1);
            if (nums[i] < target) l = i+1;
            else if (nums[i] > target) r = i-1;
            else if (nums[i] == target){
                if (i==0) leftCond = true, left = i; // target starts at the beginning
                if (i-1>=0 && nums[i-1] < target)  leftCond = true, left = i; // target starts in middle
                if (i==nums.size()-1) rightCond = true, right = i; // target ends at the end
                if (i+1<nums.size() && nums[i+1] > target)  rightCond = true, right = i; // target ends in middle
            }
            if (leftCond && rightCond) return vector<int>({left,right});
        }
        return vector<int>({-1,-1});
    }
};