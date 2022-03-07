// Link: https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution
{
public:
    vector<vector<int>> output;
    vector<int> traversal;

    void DFS(vector<vector<int>>& graph, int i)
    {
        traversal.push_back(i);

        if (i == graph.size()-1)
            output.push_back(traversal);

        for (int j=0; j<graph[i].size(); j++)
            DFS(graph, graph[i][j]);

        traversal.pop_back();

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        DFS(graph, 0);
        return output;
    }
};