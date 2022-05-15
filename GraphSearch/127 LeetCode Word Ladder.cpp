// Link: https://leetcode.com/problems/word-ladder/

// Approach: apply bfs from beginWord to endWord.

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // create adjacency list
        wordList.push_back(beginWord);
        for (auto& i:wordList) {
            for (auto& j:wordList)
                if (hammingDistance(i,j) == 1)
                    graph[i].insert(j), graph[j].insert(i);
        }
        if (graph.find(endWord) == graph.end()) return 0;

        // apply bfs
        queue<string> q; q.push(beginWord);
        visited.insert(beginWord);
        int breadth = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (auto loop=0; loop<sz; loop++) { // level-order-traversal/BFS
                auto curr = q.front(); q.pop();
                if (curr == endWord) return breadth;

                for (auto& neighbor:graph[curr]) {
                    if (visited.find(neighbor) == visited.end()) { // mark visited
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
            breadth++;
        }
        return 0;
    }
private:
    unordered_map<string, set<string>> graph;
    unordered_set<string> visited;

    int hammingDistance(string &A, string &B) {
        int difference = 0;
        for (auto i=0; i<A.size(); i++)
            if (A[i] != B[i])
                if (++difference > 1)
                    return difference;
        return difference;
    }
};