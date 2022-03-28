// Link: https://leetcode.com/problems/minimum-cost-to-connect-sticks/

// TimeComplexity = O(N*logN)

class Solution {
public:
    int connectSticks(vector<int>& sticks) {

        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end()); // buildheap: O(N)
        // Two ways to build heap:
        // 1) directly build heap => T=O(N)
        // 2) add elem one-by-one => T=O(N*logN)

        int TotalCost = 0, cost, a, b;
        while(pq.size()>1){ // O(N)

            a = pq.top(); pq.pop(); // O(log N)
            b = pq.top(); pq.pop(); // O(log N)
            cost = a+b;
            TotalCost += cost;
            pq.push(cost); // O(log N)
        }
        return TotalCost;
    }
};