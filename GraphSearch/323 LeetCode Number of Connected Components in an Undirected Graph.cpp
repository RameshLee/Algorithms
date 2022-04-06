// Link: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

// 1) using disjoint set

// 1) using disjoint set

class DisjointSet {
public:
    int groups = 0;
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;

    void makeset(int n){
        for (int i=0; i<n; i++) parent[i] = i, rank[i] = 1, groups++;
    }

    int find(int i){
        if (i==parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    void unify(int x, int y){
        int i=find(x), j=find(y);

        if (rank[i] < rank[j])          parent[i] = j;
        else if (rank[i] > rank[j])     parent[j] = i;
        if (rank[i] == rank[j])         parent[j] = i; rank[i] +=1;

        groups--;
    }

    void updateParent(){
        for (int i=0; i<parent.size(); i++) parent[i] = find(i);
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        DisjointSet DS;
        DS.makeset(n);
        for (auto& it:edges){
            int i=it[0], j=it[1];
            if (DS.find(i) != DS.find(j))
                DS.unify(i,j);
        }
        DS.updateParent();
        return DS.groups;
    }
};

// 2) using dfs

class Solution {
public:
    void dfs(int i, vector<vector<int>>& graph, unordered_map<int,int>& visited){
        if (visited.find(i) == visited.end()){
            visited[i] = 1;
            for (auto& it:graph[i])
                dfs(it, graph, visited);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        // create adjacency list
        vector<vector<int>> graph(n);
        for (auto& it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        // apply dfs to unvisited nodes
        int count = 0;
        unordered_map<int,int> visited;
        for (int i=n-1; i>=0; i--){
            if (visited.find(i) == visited.end())
                dfs(i, graph, visited), count++;
        }
        return count;
    }
};
