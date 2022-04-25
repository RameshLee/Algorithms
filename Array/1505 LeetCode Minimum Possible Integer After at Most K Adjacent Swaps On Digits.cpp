// Link: https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/

// TLE

class Solution {
public:
    string minInteger(string nums, int k) {
        if (k==0) return nums; // no swap is possible

        int n = nums.size();
        if (k>=n*(n+1)/2){ // possible to find optimum
            sort(nums.begin(), nums.end());
            return nums;
        }

        // repeatedly find the min number, move it to front, and update possible swaps k
        for (int i=0; i<=9; i++){ // 9 numbers are possible
            int pos = nums.find(to_string(i));
            if (pos>=0 && pos<=k){ // found
                return nums[pos] + minInteger(nums.substr(0,pos)+nums.substr(pos+1), k-pos);
            }
        }
        return nums;
    }
};