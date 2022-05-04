// Link: https://leetcode.com/problems/sum-of-subarray-ranges/

// 1) two cycle solution: T=O(N^2)

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0; int n=nums.size();
        for (auto i=0; i<n; i++){
            auto Min=INT_MAX, Max=INT_MIN;
            for (auto j=i; j<n; j++){
                Min=min(Min,nums[j]), Max=max(Max,nums[j]);
                sum += (Max-Min);
            }
        }
        return sum;
    }
};

// 2) Monotonic stack: T=O(N)