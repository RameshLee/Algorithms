// Link: https://leetcode.com/problems/maximum-product-after-k-increments/

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        for (int i=0; i<k; i++){
            int val = pq.top();
            pq.pop();
            pq.push(val+1);
        }

        int mod = 1e9+7;
        long ret = 1;
        while (!pq.empty()){
            ret = (pq.top()*ret) % mod;
            pq.pop();
        }
        return (int)ret;
    }
};