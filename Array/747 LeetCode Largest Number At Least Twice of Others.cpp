// Link: https://leetcode.com/problems/largest-number-at-least-twice-of-others/

// 1-pass approach
class Solution {
public:
    int dominantIndex(vector<int>& nums) {

        int index, Max = 0, SecondMax = 0;
        for (int i=0; i<nums.size(); i++) {
            if (Max == 0 || Max < nums[i]) {
                SecondMax = Max;
                Max = nums[i];
                index = i;
            }
            else if (SecondMax == 0 || SecondMax < nums[i]){
                SecondMax = nums[i];
            }
        }
        if (2*SecondMax > Max) return -1;

        return index;
    }
};

// 2-pass approach
class Solution {
public:
    int dominantIndex(vector<int>& nums) {

        int Max = -INT_MAX; int index;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > Max){
                Max = nums[i];
                index = i;
            }
        }

        for (int i=0; i<nums.size(); i++) {
            if (i != index){
                if (2*nums[i] > Max)
                    return -1;
            }
        }
        return index;
    }
};