// Link: https://leetcode.com/problems/rank-transform-of-an-array/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        unordered_map<int,int> Map;
        int i=1, prev=INT_MAX;
        while(!pq.empty()){
            if (pq.top() == prev) --i;
            Map[pq.top()] = i;
            prev = pq.top();
            pq.pop(); i++;
        }

        vector<int> ret;
        for (auto& it:arr) ret.push_back(Map[it]);
        return ret;
    }
};