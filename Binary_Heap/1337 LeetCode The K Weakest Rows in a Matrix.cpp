// Link: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

using pi = pair<int,int>;
class myComparator{
public:
    bool operator()(pi &p1, pi &p2){

        if (p1.second == p2.second) return p1.first>p2.first;
        return p1.second>p2.second;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        vector<int> ret;
        vector<pi> v;

        for (int r=0; r<mat.size(); r++){ // compute the strength: O(N)
            int i=r, j=0;
            for (int c=0; c<mat[r].size(); c++, j++)
                if (mat[r][c] == 0)
                    break;
            v.push_back(make_pair(i,j));
        }
        priority_queue<pi, vector<pi>, myComparator> pq(v.begin(), v.end()); // buildheap: O(n)

        int i=0;
        while (!pq.empty() && i++<k){
            ret.push_back(pq.top().first), pq.pop(); // pop off the pq: O(k*logN)
        }

        return ret;
    }
};