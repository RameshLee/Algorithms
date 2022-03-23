// Link: https://leetcode.com/problems/min-cost-to-connect-all-points/

class DisjointSet{
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;

    void makeset(int n){
        for (int i=0; i<n; i++) parent[i] = i, rank[i] = 0;
    }

    int find(int i){
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unify(int i, int j){
        int x = find(i);
        int y = find(j);

        if (x != y){
            if (rank[x] > rank[y]) parent[y] = x;
            else if (rank[x] < rank[y]) parent[x] = y;
            else parent[x] = y, rank[y]++;
        }
    }
};

class Edges{
public:
    int x, y, weight;
    Edges(int _x, int _y, int _weight):x(_x),y(_y),weight(_weight){}
};

class myComparator{
public:
    bool operator()(Edges &e1, Edges &e2){
        return (e1.weight > e2.weight);
    }
};

class Solution {
public:
    vector<Edges> edges;
    DisjointSet DS;
    priority_queue<Edges, vector<Edges>, myComparator> pq;

    int minCostConnectPoints(vector<vector<int>>& p) {

        // vectorize the edges
        int n = p.size();
        for (int i=0; i<p.size(); i++){
            for (int j=i+1; j<p.size(); j++){
                int weight = abs(p[i][0]-p[j][0])+abs(p[i][1]-p[j][1]);
                edges.push_back(Edges(i,j,weight));
            }
        }

        // make disjointset
        DS.makeset(n);
        for (auto& it:edges) pq.push(it);

        // kruskal: repeatedly pick the lighest edge that doesn't produce a cycle
        int Minimum = 0;
        while (!pq.empty()){
            Edges e = pq.top();
            if ( DS.find(e.x) != DS.find(e.y) ){
                Minimum += e.weight;
                DS.unify(e.x,e.y);
            }
            pq.pop();
        }
        return Minimum;
    }
};