// Link: https://leetcode.com/problems/top-k-frequent-elements/
// using Hashmap + Priority Queue: TimeComplexity = O(N+k*logN), spaceComplexity=O(N)

using pi = pair<int,int>;
class myComparator{
public:
    bool operator()(pi& p1, pi& p2){
        return p1.second<p2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> ret; vector<pi> v;
        unordered_map<int,int> Map, Map2;

        for (auto& it:nums) Map[it]++; // T=O(N)
        for (auto& it:nums) if (++Map2[it] == 1) v.push_back(make_pair(it,Map[it])); // T=O(N)

        priority_queue<pi, vector<pi>, myComparator> pq(v.begin(), v.end()); // T=O(N)
        for (int i=0; i<k; i++, pq.pop()) ret.push_back(pq.top().first); // T=O(k*logN)

        return ret;
    }
};