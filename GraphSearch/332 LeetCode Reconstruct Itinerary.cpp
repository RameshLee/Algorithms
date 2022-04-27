// Link: https://leetcode.com/problems/reconstruct-itinerary/

// hierholzer's algo: works if there exists atleast one eulerian path

class Solution {
public:
    void dfs(string s){
        auto& pq = graph[s];
        while (!pq.empty()){
            auto vertex = pq.top();
            pq.pop();
            dfs(vertex);
        }
        result.push_back(s);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (auto e:tickets){
            graph[e[0]].push(e[1]);
        }
        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> result;
};

