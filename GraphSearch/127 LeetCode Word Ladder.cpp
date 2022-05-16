// Link: https://leetcode.com/problems/word-ladder/

// 1) BFS: Without using adjcency list (more-efficient)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // store all words in dictSet for O(1) access time
        unordered_set<string> dictSet(wordList.begin(), wordList.end());
        if (!dictSet.count(endWord)) return 0;

        // apply bfs
        int breadth = 1;
        queue<string> q({beginWord});
        while (!q.empty()) {
            int sz = q.size();
            for (auto loop=0; loop<sz; loop++) { // level-order-traversal/BFS
                auto curr = q.front(); q.pop();
                if (curr == endWord) return breadth;

                // goto neighbors by modifying each letter of the original word => more-efficient
                for (auto c='a'; c<='z'; c++) {
                    for (int i=0; i<curr.size(); i++) {
                        auto neighbor = curr; neighbor[i] = c;
                        if (dictSet.count(neighbor))
                            q.push(neighbor), dictSet.erase(neighbor); // mark as visited.
                    }
                }
            }
            breadth++;
        }
        return 0;
    }
};


// 2) BFS: Using adjancency list: apply bfs from beginWord to endWord.
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