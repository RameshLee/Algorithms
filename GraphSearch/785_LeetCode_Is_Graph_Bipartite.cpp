//Link: https://leetcode.com/problems/is-graph-bipartite/

// 2-coloring problem on graph using dfs
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vertex.resize(n, UNCOLORED);
        // apply dfs
        for (auto i=0; i<n; i++)
            if (vertex[i] == UNCOLORED)
                if (!dfs(i, RED, graph))
                    return false;
        return decision;
    }
private:
    vector<int> vertex; bool decision = true;
    enum Status{UNCOLORED, RED, BLACK};

    bool dfs(int i, int color, vector<vector<int>>& graph) {
        if (vertex[i] != UNCOLORED) return true;
        vertex[i] = color; // mark color

        for (auto j : graph[i]) { // check color violations on adj nodes
            if (vertex[j] == color)
                return false;
        }

        auto nextColor = (color==BLACK) ? RED : BLACK; // switch color
        for (auto j : graph[i]) {
            if (!dfs(j, nextColor, graph))
                return false;
        }
        return true;
    }
};
