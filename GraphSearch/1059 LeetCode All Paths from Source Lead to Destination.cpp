// Link: https://leetcode.com/problems/all-paths-from-source-lead-to-destination/

class Solution {
public:
    bool decision = true;

    void dfs(int i, vector<vector<int>>& graph, unordered_map<int,int>& recursionStack, int &dest){

        if (!decision) return;

        // detect graph cycle
        if (recursionStack[i] == 2) decision = false;
        recursionStack[i]++;

        // recursively explore
        for (auto& it:graph[i])
            dfs(it, graph, recursionStack, dest);

        // ensure whether the terminal node is the destination node.
        if (graph[i].empty())
            if (i != dest)
                decision = false;

        recursionStack.erase(i);
    }

    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {

        // make adjacency list
        vector<vector<int>> graph(n);
        for (auto& it:edges) graph[it[0]].push_back(it[1]);

        // apply dfs
        unordered_map<int,int> recursionStack;
        dfs(source, graph, recursionStack, destination);

        return decision;
    }
};