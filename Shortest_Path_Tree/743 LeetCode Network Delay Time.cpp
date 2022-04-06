// Link: https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using vi = vector<int>;
        using pi = pair<int,int>;
        using vvpi = vector<vector<pi>>;

        vvpi graph(n);
        for (auto& it:times)
            graph[it[0]-1].push_back(make_pair(it[1]-1,it[2]));
        k -= 1;

        vi distance(n, INT_MAX);
        priority_queue<pi> pq;
        pq.push(make_pair(0,k)); //dist,source
        distance[k] = 0;

        while (!pq.empty()){
            // 1) get the min dist node
            int i = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            // 2) update dist of neighbor nodes
            for (auto& it:graph[i]){
                int j = it.first;
                int weight = it.second;
                if (distance[j] > dist + weight){
                    distance[j] = dist + weight;
                    pq.push(make_pair(distance[j], j));
                }
            }
        }

        int maxDist = 0;
        for (auto& it:distance)  maxDist = max(maxDist, it);

        return (maxDist == INT_MAX) ? -1 : maxDist;
    }
};