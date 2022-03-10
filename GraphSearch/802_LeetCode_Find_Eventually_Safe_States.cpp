// Link: https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
public:
    vector<int> output;
    unordered_set<int> visited;
    unordered_set<int> safe_nodes;
    unordered_set<int> cycle_nodes;

    bool DFS(vector<vector<int>>& graph, int i)
    {
        if (safe_nodes.find(i) != safe_nodes.end()) return true;
        if (cycle_nodes.find(i) != cycle_nodes.end()) return false;

        if (visited.find(i) != visited.end()) {cycle_nodes.insert(i); return false;}

        visited.insert(i);

        for (auto& it:graph[i])
            if (!DFS(graph, it))
            {
                cycle_nodes.insert(it);
                return false;
            }

        safe_nodes.insert(i);

        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {

        for (int i=0; i<graph.size(); i++)
            if (DFS(graph, i))
                output.push_back(i);

        return output;
    }
};