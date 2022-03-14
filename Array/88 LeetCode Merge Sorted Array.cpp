// Link: https://leetcode.com/problems/merge-sorted-array/

// Two pointer approach with O(m+n) time complexity

class Solution {
public:
    vector<int> vec;
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i=0;
        int j=0;

        while (1){
            if (i>=m && j>=n) break;
            else if (i>=m) {vec.push_back(nums2[j]); j++;}
            else if (j>=n) {vec.push_back(nums1[i]); i++;}
            else if (nums1[i]<nums2[j]) {vec.push_back(nums1[i]); i++;}
            else {vec.push_back(nums2[j]); j++;}
        }

        nums1 = vec;

    }
};