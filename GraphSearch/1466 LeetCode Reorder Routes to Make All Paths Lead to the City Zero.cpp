// Link: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // create adjacency list
        for (auto e:connections) {
            string s = to_string(e[0]) + "," + to_string(e[1]);
            edgeSet.insert(s);
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        // apply dfs from zero
        dfs(0, -1);
        return result;
    }
private:
    void dfs(int curr, int prev) {
        if (visited.count(curr)) return; // base-case
        visited.insert(curr);

        string s = to_string(curr) + "," + to_string(prev);
        if (!edgeSet.count(s)) result++; // update result

        for (auto j : graph[curr]) { // recursion
            dfs(j,curr);
        }
    }
private:
    unordered_set<string> edgeSet;
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    int result = -1;
};