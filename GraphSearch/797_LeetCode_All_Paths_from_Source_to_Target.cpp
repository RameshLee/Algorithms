// Link: https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        dfs(graph, 0);
        return allPaths;
    }
private:
    vector<vector<int>> allPaths; vector<int> path;

    void dfs(vector<vector<int>>& graph, int i){
        path.push_back(i); // add node in path
        if (i == graph.size()-1) allPaths.push_back(path); // append path
        for (auto j:graph[i]) dfs(graph, j); // recursive dfs
        path.pop_back(); // remove node in path
    }
};