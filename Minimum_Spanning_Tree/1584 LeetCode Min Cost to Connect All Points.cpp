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
        int x = find(i), y = find(j);

        if (rank[x] > rank[y])          parent[y] = x;
        else if (rank[x] < rank[y])     parent[x] = y;
        else                            parent[x] = y, rank[y]++;
    }
};

class Edges{
public:
    int x, y, weight;
    Edges() : x(0), y(0), weight(0){}
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


    int minCostConnectPoints(vector<vector<int>>& p) {

        vector<Edges> edges;

        // vectorize the edges
        for (int i=0; i<p.size(); i++){
            for (int j=i+1; j<p.size(); j++){
                int weight = abs(p[i][0]-p[j][0])+abs(p[i][1]-p[j][1]);
                edges.push_back(Edges(i,j,weight));
            }
        }

        // make disjointset
        DisjointSet DS;
        DS.makeset(p.size());

        // make priority queue
        priority_queue<Edges, vector<Edges>, myComparator> pq(edges.begin(), edges.end());

         // kruskal: repeatedly pick the lighest edge that doesn't produce a cycle
        int Minimum = 0, count = p.size()-1;
        while (!pq.empty() && count>0){
            Edges e = pq.top(); pq.pop();
            if ( DS.find(e.x) != DS.find(e.y) ){
                Minimum += e.weight;
                DS.unify(e.x,e.y);
                count--;
            }
        }
        return Minimum;
    }
};