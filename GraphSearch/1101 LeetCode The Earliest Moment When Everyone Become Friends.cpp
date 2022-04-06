// Link: https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/

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
        if (rank[i] < rank[j])          parent[i] = j;
        else if (rank[i] > rank[j])     parent[j] = i;
        else if (rank[i] == rank[j])    parent[j] = i, rank[i] += 1;
        groups--;
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {

        // sort events according to occurence time
        sort(logs.begin(), logs.end());

        // unify the sets
        DisjointSet DS;
        DS.makeset(n);
        for (auto& it:logs){
            int time=it[0], i=it[1], j=it[2];
            if (DS.find(i) != DS.find(j))  DS.unify(i,j);
            if (DS.groups == 1) return time;
        }
        return -1;
    }
};