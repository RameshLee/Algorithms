// Link: https://leetcode.com/problems/sliding-window-maximum/

// Using deque: T=O(N)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        std::deque<int> q; // store k indices
        for (auto i=0; i<nums.size(); i++) {
            if (!q.empty() && q.front() == i-k) q.pop_front(); // maintain deque size <= k
            while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back(); // delete elements lesser than current
            q.push_back(i); // insert current element
            if (i>=k-1) result.push_back(nums[q.front()]); // append answer
        }
        return result;
    }
};