// Link: https://leetcode.com/problems/graph-valid-tree/

// 1) using Disjoint set


class DisjointSet{
public:
    int groups = 0;
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;

    void makeset(int n){
        for (int i=0; i<n; i++) parent[i] = i, rank[i] = 1, groups++;
    }

    int find(int i){
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    void unify(int x, int y){
        int i=find(x), j=find(y);

        if (rank[i] < rank[j]) parent[i] = j;
        else if (rank[j] < rank[i]) parent[j] = i;
        else if (rank[i] == rank[j]) parent[j] = i; rank[i] += 1;

        groups--;
    }

    void updateParents(){
        for (int i=0; i<parent.size(); i++) parent[i] = find(i);
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        DisjointSet DS;
        DS.makeset(n);
        for (auto& it:edges){
            int i=it[0], j=it[1];
            if (DS.find(i) == DS.find(j)) return false;
            DS.unify(i,j);
        }
        DS.updateParents();

        // ensure all nodes have a common parent
        if (DS.groups == 1) return true;
        return false;
    }
};