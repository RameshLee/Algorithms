// Link: https://leetcode.com/problems/parallel-courses/

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {

        // g->adjacency list, S->nodes with zero indegree, L->toplogically sorted list
        vector<vector<int>> graph(n, vector<int>());
        vector<int> indegree(n,0), S, L;

        // create adjacency list & update indegrees
        for (auto& e:relations) e[0]--,e[1]--;
        for (auto& e:relations) graph[e[0]].push_back(e[1]), indegree[e[1]]++;

        // mark the nodes with zero indegrees
        for (int i=0; i<n; i++) if (indegree[i] == 0) S.push_back(i);

        // bfs/topological sort
        int courses=0, semesters=0;
        while (!S.empty()){

            semesters++; // update semesters

            vector<int> temp;
            for (auto i:S){ // for all zero indegree nodes
                courses++;
                for (auto j:graph[i])
                    if (--indegree[j] == 0)
                        temp.push_back(j); // inject neighbors with updated indegree as zero
            }

            S=temp;
        }
        return (courses == n) ? semesters : -1;
    }
};