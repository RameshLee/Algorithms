// Link: https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/

class Solution {
public:
    int minDeletion(vector<int>& nums) {

        int LastElem = 0;
        int size = 0;

        for (int i=0; i<nums.size(); i++){
            if (size%2 == 0 && i != nums.size()-1) {
                LastElem = nums[i]; size++;
            }
            else if (LastElem != nums[i]) {
                LastElem = nums[i];  size++;
            }
        }
        if (size%2 != 0) size--;
        return nums.size()-size;
    }
};