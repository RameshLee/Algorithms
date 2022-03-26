// Link: https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq;
        for (auto& it:stones) pq.push(it);

        while (!pq.empty()){
            if (pq.size() < 2) break;

            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();

            if (b>a) pq.push(b-a);
            else if (a>b) pq.push(a-b);
        }
        if (pq.empty()) return 0;
        return pq.top();
    }
};