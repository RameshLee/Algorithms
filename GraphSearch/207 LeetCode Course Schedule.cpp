// Link: https://leetcode.com/problems/course-schedule/

// Method: Topological Sort by Kahn's Algorithm

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {

        // adjacency list
        vector<vector<int>> graph(n, vector<int>());
        for (auto& ele:prerequisites){
            graph[ele[1]].push_back(ele[0]);
        }

        vector<int> indegree(n,0);
        for (auto& it:graph)
            for (auto ele:it)
                indegree[ele]++;

        printf("inDegree: ");for (auto i:indegree) printf("%d ", i);cout<<endl;

        vector<int> S; //nodes with indegree=0
        for (int i=0; i<n; i++)
            if (indegree[i] == 0){
                S.push_back(i);
                //break;
            }
        if (S.empty()) return false;

        vector<int> L;
        while (!S.empty()){
            int i = S.back(); S.pop_back();
            L.push_back(i);

            // for all edges
            for (auto j=0; j<graph[i].size(); j++){
                int node = graph[i][j];
                indegree[node]--;
                if (indegree[node] == 0) S.push_back(node);
            }
        }

        printf("Sorted: ");for (auto i:L) printf("%d ", i);
        for (auto i:indegree)
            if (i>0) return false;

        return true;
    }
};