// Link: https://leetcode.com/problems/k-closest-points-to-origin/

using pi = pair<int,int>;
using ppi = pair<int,pi>;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>> ret;
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq; //based on the 1st element by default

        for (auto &it:points)
            pq.push( make_pair( pow(it[0],2) + pow(it[1],2), make_pair( it[0], it[1] ) ) );

        for (int i=0; i<k; i++, pq.pop())
            ret.push_back(vector<int>({pq.top().second.first,pq.top().second.second}));

        return ret;
    }
};