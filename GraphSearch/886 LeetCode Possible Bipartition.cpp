// Link: https://leetcode.com/problems/possible-bipartition/

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // create adj list
        vertex.resize(n+1, UNCOLORED);
        graph.resize(n+1, vector<int>());
        for (auto e : dislikes) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        // isgraphBipartite?
        for (auto i=1; i<=n; i++) {
            if (vertex[i] == UNCOLORED)
                if (!dfs(i, RED))
                    return false;
        }
        return true;
    }
private:
    enum Colors{RED, BLUE, UNCOLORED};
    vector<vector<int>> graph; vector<int> vertex;

    bool dfs(int i, int color) {
        if (vertex[i] != UNCOLORED) return true;
        vertex[i] = color;

        for (auto j : graph[i])  // check bipartite
            if (vertex[j] == color)
                return false;

        auto nxtColor = (color == RED) ? BLUE : RED;
        for (auto j : graph[i])
            if (!dfs(j, nxtColor))
                return false;2

        return true;
    }
};