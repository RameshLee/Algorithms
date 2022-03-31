// Link: https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int i=0;
        while(1){
            if (i >= nums.size()) break;
            if (nums[i] == val) nums.erase(nums.begin()+i), i--;
            i++;
        }
        return i;
    }
};