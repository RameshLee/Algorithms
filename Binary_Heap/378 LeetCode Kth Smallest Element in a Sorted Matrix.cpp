// Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

// 1) breadth first search + priority queue: timecomplexity = O(k*logN), spaceComlexity = O(n)

using pi = pair<int,int>;
using ppi = pair<pi,int>;

class myComparator{
public:
    bool operator()(ppi& p1, ppi& p2){
        return p1.second>p2.second;
    }
};

class Solution {
public:
    int row, col;
    int x[2] = {1,0};
    int y[2] = {0,1};

    bool isSafe(int i, int j){ if(i<row && j<col) return true; return false; }

    int bfs(vector<vector<int>>& mat, int k){

        priority_queue<ppi, vector<ppi>, myComparator> pq;
        pq.push( make_pair( make_pair(0,0), mat[0][0] ) );
        mat[0][0] = INT_MAX;

        int i=0;
        while(!pq.empty()){

            pi index = pq.top().first;
            int val = pq.top().second;
            pq.pop();

            if (++i >= k) return val; //return the kth smallest ele

            int i=index.first, j=index.second;
            for (int k=0; k<2; k++)
                if (i+x[k] < mat.size() && j+y[k] < mat[0].size() )
                    if (mat[i+x[k]][j+y[k]] != INT_MAX){
                        pq.push( make_pair( make_pair(i+x[k],j+y[k]), mat[i+x[k]][j+y[k]] )  );
                        mat[i+x[k]][j+y[k]] = INT_MAX;
                    }
        }

        return 0;
    }

    int kthSmallest(vector<vector<int>>& mat, int k) {
        row=mat.size(); col=mat[0].size();
        return bfs(mat,k);
    }
};


// 2) priority_queue approach: time complexity = O(N*logN + k*logN) = O((N+k)*logN), spaceComlexity = O(n)

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& it:mat)
            for (auto& ele:it)
                pq.push(ele);

        int i=0;
        while(++i<k){
             pq.pop();
        }
        return pq.top();
    }
};