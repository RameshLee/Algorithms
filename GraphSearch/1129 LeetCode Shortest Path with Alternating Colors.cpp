// Link: https://leetcode.com/problems/shortest-path-with-alternating-colors/

using vvi = vector<vector<int>>;
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vvi& redEdges, vvi& blueEdges) {
        enum Status{RED, BLUE, UNCOLORED};
        vector<vector<pair<int,int>>> graph(n);
        bool visitedEdge[101][101][3] = {false};
        vector<int> result(n,-1);

        // create adjacency list
        for (auto e:redEdges)  {
            graph[e[0]].push_back(make_pair(e[1], RED));
        }
        for (auto e:blueEdges) {
            graph[e[0]].push_back(make_pair(e[1], BLUE));
        }

        // apply bfs
        queue<vector<int>> q; q.push(vector<int>({0,0,UNCOLORED})); // (node,dist,edgecolor)
        for (auto breadth=0; !q.empty(); breadth++) { // bfs/level-order-traversal
            int sz = q.size();
            for (auto loop=0; loop<sz; loop++) {
                auto curr = q.front(); q.pop();
                if (result[curr[0]] == -1) result[curr[0]] = curr[1]; // update result

                for (auto e : graph[curr[0]]) { // explore neighbors
                    auto j = e.first, edgeColor = e.second;
                    if (curr[2] != edgeColor && visitedEdge[curr[0]][j][edgeColor] == false) {
                        q.push(vector<int>({j, breadth+1, edgeColor}));
                        visitedEdge[curr[0]][j][edgeColor] = true;
                    }
                }
            }
        }
        return result;
    }
};