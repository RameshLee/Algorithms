// Link: https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
private:
    vector<int> output; set<int> visited, safe_nodes, cycle_nodes;
public:
    bool DFS(int i, vector<vector<int>>& graph){
        if (safe_nodes.find(i) != safe_nodes.end()) return true; //wkt safe already
        if (cycle_nodes.find(i) != cycle_nodes.end()) return false; //wkt cycle node already
        if (visited.find(i) != visited.end()) {cycle_nodes.insert(i); return false;} //cycle node found

        visited.insert(i); // mark as visited
        for (auto j:graph[i])
            if (!DFS(j,graph)){
                cycle_nodes.insert(j); //parents of cycle nodes also lead to cycle
                return false;
            }
        safe_nodes.insert(i); //if no neighbors have cycle, then whole path has safe nodes
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        for (int i=0; i<graph.size(); i++)
            if (DFS(i, graph))
                output.push_back(i);
        return output;
    }
};