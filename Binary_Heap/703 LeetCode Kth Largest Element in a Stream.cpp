// Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto i:nums) pq.push(i);
        while (pq.size() > k) pq.pop();
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k) pq.pop();
        return pq.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq;  int k;
};