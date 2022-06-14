// Link: https://leetcode.com/problems/loud-and-rich/

// algorithm: dfs + memoization
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        // preprocessing
        int n = quiet.size();
        this->quiet = quiet;
        result.resize(n,0);
        for (auto i=0; i<n; i++) {
            result[i] = i;
            quietMap[quiet[i]] = i;
        }

        // create adjacency list
        vector<int> indegree(n,0);
        graph.resize(n,vector<int>());
        for (auto e : richer) {
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }

        // apply dfs from all root nodes
        for (auto i=0; i<n; i++) {
            if (indegree[i] == 0)
                dfs(i);
        }
        return result;
    }
private:
    int dfs(int i) {
        if (Memo.count(i)) return Memo[i];

        int val = quiet[i];
        for (auto j : graph[i]) {
            val = min(val, dfs(j));
        }
        result[i] = quietMap[val];
        return Memo[i] = val;
    }
private:
    vector<int> result, quiet;
    vector<vector<int>> graph; // adj list
    unordered_map<int,int> quietMap; // (quiet,node)
    unordered_map<int,int> Memo; // (node, optimal)
};