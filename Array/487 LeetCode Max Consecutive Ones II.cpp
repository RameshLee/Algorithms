// Link: https://leetcode.com/problems/max-consecutive-ones-ii/

// One-pass algorithm: T=O(n), S=O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int l = 0, r = 0, maxCount = -INT_MAX;
        for (int i=0; i<nums.size(); i++){

            if (nums[i] == 1) l++; // aggregate all 1's on the left.
            else {
                int index; // new index to traverse on the right-side

                r = 0;
                for (index=i+1; index<nums.size(); index++){ // sweep right to find all 1's.
                    if (nums[index] == 0) break;
                    r++;
                }

                maxCount = max(maxCount, 1+l+r);
                l = r; // rightOnes for this zero is leftOnes for the next zero.

                i = index-1; // jump ahead in the loop after sweeping right. Hence, T=O(n).
            }
        }
        return (maxCount == -INT_MAX) ? nums.size() : maxCount;
    }
};