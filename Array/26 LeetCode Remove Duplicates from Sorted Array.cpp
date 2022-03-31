// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// 1) One-pass approach: T=O(n), S=O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i=0;
        while (1) {
            if (i>=nums.size()) break;
            if (i>0){
                if (nums[i] == nums[i-1]){
                    nums.erase(nums.begin()+i); i--;
                }
            }
            i++;
        }
        return nums.size();
    }
};

// 2) Using hashmap, however, S will become O(n).