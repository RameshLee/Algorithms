// Link: https://leetcode.com/problems/number-of-provinces/

// 1) using Disjoint-set

class DisjointSet{
public:
    unordered_map<int,int> parent; // node, (parent)
    unordered_map<int,int> rank; // node, (rank)

    void makeset(int n){
        for (int i=0; i<n; i++) parent[i] = i, rank[i] = 1;
    }

    int findParent(int i){
        if (i == parent[i]) return i;
        return parent[i] = findParent(parent[i]);
    }

    void unify(int x, int y){
        int i = findParent(x), j = findParent(y);

        if (rank[i] > rank[j])          parent[j] = i;
        else if (rank[i] < rank[j])     parent[i] = j;
        else                            parent[i] = j, rank[j] += 1;
    }

    void updateParents(){
        for (int i=0; i<parent.size(); i++) parent[i] = findParent(i);
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        // makeset
        DisjointSet DS;
        DS.makeset(isConnected.size());

        // for all edges, unify set
        for (int i=0; i<isConnected.size(); i++)
            for (int j=0; j<isConnected[i].size(); j++)
                if (isConnected[i][j] == 1)
                    if ( DS.findParent(i) != DS.findParent(j) )
                        DS.unify(i, j);

        // ensure parents are upto date
        DS.updateParents();

        // count unique provinces
        set<int> Provinces;
        for (auto it=DS.parent.begin(); it!=DS.parent.end(); it++)
            Provinces.insert( (*it).second );

        return Provinces.size();
    }
};

// 2) using DFS


class Solution{
public:
    void DFS(vector<vector<int>>& isConnected, vector<int>& visited, int i){
        if (visited[i] == 0){
            visited[i] = 1;
            for (int j=0; j<isConnected[i].size(); j++)
                if (isConnected[i][j] == 1)
                    DFS(isConnected, visited, j);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected){
        vector<int> visited(isConnected.size(), 0);
        int Provinces = 0;
        for (int i=0; i<isConnected.size(); i++)
            if (visited[i] == 0){
                DFS(isConnected, visited, i);
                Provinces++;
            }
        return Provinces;
    }
};
