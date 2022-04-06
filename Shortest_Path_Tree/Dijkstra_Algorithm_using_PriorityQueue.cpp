// C++ program to find shortest distance from source to all vertices
// Dijkstra Algorithm with Priority Queue

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvpi = vector<vector<pair<int,int>>>;
using pr = pair<int,int>;

class Solution{
public:
    priority_queue<pr> pq; //compares the first element of pair by default

    void dijkstra(vvpi &graph, int n){
        int sc = 0;
        vi distance(n,INT_MAX);
        distance[sc] = 0;
        pq.push(make_pair(0,sc));

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

        // print utility
        printf("Shortest Dist:\n"); int i=0;
        for (auto& it:distance){
            printf("vertex %d -> distance: %d\n", i++, it);
        }
    }

};

int main(){



   //vvi edges = {{0,1,3},{0,2,1},{1,2,7},{1,3,5},{1,4,1},{2,3,2},{3,4,7}};
    vvi edges = {{0,4,1},{0,1,6},{4,1,2},{4,3,1},{1,3,2},{1,2,5},{3,2,5}};
    int n = 5;

    vvpi graph(n);
    for (auto& it:edges){
        graph[it[0]].push_back(make_pair(it[1],it[2]));
    }
    Solution S;
    S.dijkstra(graph, n);

    return 0;
}
