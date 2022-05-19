// Link: https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // based on 1st elemnt by default

        // add elemns to priority queue
        for (auto e:points) {
            auto x = e[0], y = e[1];
            auto distance = x*x + y*y;
            pq.push(vector<int>({distance,x,y}));
        }

        // fetch k-closest elems
        vector<vector<int>> result;
        while(k-- > 0 && !pq.empty()) {
            result.push_back(vector<int>({pq.top()[1],pq.top()[2]}));
            pq.pop();
        }
        return result;
    }
};