#include <iostream>

class Sample{
public:
    vector<string> solve(string first, string second, unordered_set<string>& dict) {
        // edge-case
        if (!dict.count(first) || !dict.count(second)) return result;

        // bfs
        queue<string> q; q.push(first); dict.erase(first);
        int distance = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (auto loop=0; loop<sz; loop++) { // level-order-traversal
                auto curr = q.front(); q.pop(); // curr node in queue

                if (curr == second) { // termination criterion --> valid graph (path from first to second)
                    graph[neighbor] = second;
                    goto NextStep;
                }

                // curr ->> all feasible neighbors

                // generate neighbors
                for (auto c='a'; c<'z'; c++) {
                    for (int j=0; j<curr.size(); j++) {
                        if (curr[j] == c) continue; // diff b/w curr & neighbor is 0.
                        auto neighbor = curr;
                        neighbor[j] = c; // difference of distance b/w curr & neighbor is 1.
                        if (dict.count(neighbor)) { // feasible neighbor
                            q.push(neighbor);
                            dict.erase(neighbor);
                            graph[neighbor] = curr; // create adjacency list (bfs)
                        }
                    }
                }
            }
            distance++; // increments the distance
        }
    Next Step:
        return computePath(second); // retrieve the shortest path
    }
private:
    unordered_map<string,string> graph; // (curr -> all neighbors) // avg: T=O(1) // hashmap... worstcase: T=O(N)

    vector<string> computePath(string curr) {
        vector<string> result;
        queue<string> q; q.push(curr);
        while (!q.empty()) { // bfs from second to first.
            auto curr = q.front(); q.pop();
            result.push_back(curr); // append to result -->final path from first to second
            q.push(graph[curr]);
        }
        return result;
    }
};

// create adjacency list
// edge "cat": bat, cot
// edge "dog":. .....

0        1   1   1
(1) --> (2),(3),(4) --> (2->6), (3->7)

// cat, (a to z)at, c(a to z)t
// algo: BFS (shortest path finding)

int main() {
    Sample S;
    S.solve(start, end, dictionary);
    return 0;
}

