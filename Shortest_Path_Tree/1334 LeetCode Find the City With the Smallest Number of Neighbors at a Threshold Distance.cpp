// Link:

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        this->threshold = threshold; this->n = n;

        // create adjacency list
        for (auto e:edges) {
            graph[e[0]].push_back(e[1]), graph[e[1]].push_back(e[0]);
            weight[e[0]][e[1]] = e[2], weight[e[1]][e[0]] = e[2];
        }

        // apply dijsktra algorithm
        auto city = 0, reached = INT_MAX;
        for (auto i=0; i<n; i++) {
            auto val = dijkstra(i);
            if (reached >= val) {
                reached = val, city = i;
            }
        }
        return city;
    }
private:
    int dijkstra(int i) {
        vector<int> distance(n, INT_MAX);
        using pi = pair<int,int>;
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        distance[i] = 0;
        pq.push(make_pair(distance[i],i));

        while (!pq.empty()) { // dijkstra
            auto curr = pq.top().second; pq.pop();
            for (auto j:graph[curr])
                if (distance[j] > distance[curr] + weight[curr][j]) {
                    distance[j] = distance[curr] + weight[curr][j];
                    pq.push(make_pair(distance[j],j));
                }
        }

        int reached = 0;
        for (auto i=0; i<n; i++) { // update output
            if (distance[i]!=0 && distance[i] <= threshold)
                reached++;
        }
        return reached;
    }

private:
    int threshold, n, weight[101][101] = {INT_MAX};
    unordered_map<int,vector<int>> graph;
};