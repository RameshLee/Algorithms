// Link: https://leetcode.com/problems/sort-colors/submissions/

// 1) Counting sort: linear time, constant space
class Solution {
public:
    void sortColors(vector<int>& nums) {

        // count number of 0's,1's,2's
        vector<int> count(3,0);
        for (auto i:nums) count[i]++;

        // recreate the vector
        nums.clear();
        for (auto i=0; i<=2; i++) {
            for (auto j=0; j<count[i]; j++) {
                nums.push_back(i);
            }
        }
    }
};

// 2) Simple approach: linear time, linear space
class Solution {
public:
    void sortColors(vector<int>& nums) {

        vector<int> result;
        for (auto i=0; i<=2; i++) {
            for (auto j:nums) {
                if (j == i) {
                    result.push_back(j);
                }
            }
        }
        nums = result;
    }
};