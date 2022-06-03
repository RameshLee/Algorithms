// Link: https://leetcode.com/problems/minimize-product-sum-of-two-arrays/

// 1) comparative sort
class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.rbegin(), nums2.rend());
        int sum = 0;
        for (auto i=0; i<nums1.size(); i++) {
            sum += (nums1[i] * nums2[i]);
        }
        return sum;
    }
};

// 2) other methods: priority queue (T=O(N*logN), S=O(N)), counting sort (T=O(N), S=O(1);