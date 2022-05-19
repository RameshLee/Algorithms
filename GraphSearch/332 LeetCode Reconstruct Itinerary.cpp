// Link: https://leetcode.com/problems/reconstruct-itinerary/

// hierholzer's algo: works if there exists atleast one eulerian path

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // create adjacency list
        for (auto e:tickets){
            graph[e[0]].push(e[1]);
        }
        // apply dfs
        dfs("JFK");
        std::reverse(result.begin(), result.end()); // reverse to get the correct sequence
        return result;
    }
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> result;

    void dfs(string s){
        auto& pq = graph[s];
        while (!pq.empty()){
            auto node = pq.top(); pq.pop();
            dfs(node);
        }
        result.push_back(s); // when there are no more neighbors to visit, add it into the result
    }
};


