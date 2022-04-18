// Link: https://leetcode.com/problems/redundant-connection/

// Detect first cycle in the graph using Disjoint Set Algorithm

class DisjointSet{
public:
    int groups; unordered_map<int,int> parent, rank;

    void makeset(int n){
        for (int i=0; i<n; i++) parent[i] = i, rank[i] = 1, groups++;
    }

    int find(int i){
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    void unify(int x, int y){
        int i=find(x), j=find(y);
        if (rank[i] < rank[j])          parent[i] = j;
        else if (rank[j] < rank[i])     parent[j] = i;
        else if (rank[j] == rank[i])    parent[j] = i, rank[i] += 1;
        groups--;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet DS;
        DS.makeset(n);

        for (auto e:edges){
            int i=e[0], j=e[1];
            if (DS.find(i) == DS.find(j)) return vector<int>({i,j});
            DS.unify(i,j);
        }
        return vector<int>();
    }
};