// Link: https://leetcode.com/problems/find-if-path-exists-in-graph/

class Solution {
public:
    bool decision = false;
    int dest;

    void dfs(int i, vector<vector<int>>& graph, unordered_map<int,int>& visited){
        if (visited.find(i) == visited.end()){
            if (i == dest) decision = true;

            visited[i] = 1;
            for (auto& it:graph[i])
                dfs(it, graph, visited);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (auto &it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        dest = destination;
        unordered_map<int,int> visited;
        dfs(source, graph,visited);
        return decision;
    }
};