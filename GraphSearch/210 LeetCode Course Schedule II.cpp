// Link: https://leetcode.com/problems/course-schedule-ii/

// Method: Topological Sort by Kahn's Algorithm

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(n,vector<int>()); vector<int> indegree(n,0), S,L;

        // create adjacency list & update indegrees
        for (auto ele:prerequisites) graph[ele[1]].push_back(ele[0]), indegree[ele[0]]++;

        // mark the nodes with zero indegrees
        for (auto i=0; i<n; i++) if (indegree[i]==0) S.push_back(i);

        // for every zero indegree node, reduce the indegrees of its neighbors
        while (!S.empty()){
            int i = S.back(); S.pop_back(); L.push_back(i);
            for (auto j:graph[i]) if (--indegree[j] == 0) S.push_back(j);
        }
        return (L.size() == n) ? L : vector<int>();
    }
};