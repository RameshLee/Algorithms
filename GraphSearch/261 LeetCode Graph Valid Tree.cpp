// Link: https://leetcode.com/problems/graph-valid-tree/


// 1) using Disjoint set

class DisjointSet{
public:
    int groups = 0;  unordered_map<int,int> parent, rank;

    DisjointSet(int n){
        for (auto i=0; i<n; i++) parent[i] = i, rank[i] = 1, groups++;
    }

    int find(int i){
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    void unify(int x, int y){
        int i=find(x), j=find(y);
        if (rank[i] < rank[j])          parent[i] = j;
        else if (rank[j] < rank[i])     parent[j] = i;
        else if (rank[i] == rank[j])    parent[j] = i, rank[i] += 1;
        groups--;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        DisjointSet DS(n);
        for (auto& it:edges){
            int i=it[0], j=it[1];
            if (DS.find(i) == DS.find(j)) return false;
            DS.unify(i,j);
        }
        return (DS.groups == 1) ? true : false;
    }
};

// 2) using DFS

/*class Solution {
public:
    bool Decision = true;
    unordered_map<int,int> recursionStack;

    void dfs(int i, vector<vector<int>>& graph, unordered_map<int,int>& visited){

        if (recursionStack.find(i) != recursionStack.end()) Decision = false;

        if (visited.find(i) == visited.end()){

            printf("explring %d\n", i);

            visited[i] = 1;
            recursionStack[i] = 1;

            for (auto& it:graph[i])
                dfs(it, graph, visited);

            recursionStack.erase(i);
        }
        else Decision = false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        // create adjacency list
        vector<vector<int>> graph(n);
        for (auto& it:edges){
            graph[it[0]].push_back(it[1]);
           // graph[it[1]].push_back(it[0]);
        }

        int i=0;
        for (auto& it:graph){
            printf("Edges %d: ", i);
            for (auto& ele:it) printf(" %d", ele); cout<<endl;
            i++;
        }

        // apply dfs to unvisited nodes
        int count = 0;
        unordered_map<int,int> visited;
        for (int i=0; i<n; i++){
            if (visited.find(i) == visited.end()){
                printf("new dfs from %d\n", i);

                dfs(i, graph, visited), count++;
                if (count > 1) Decision = false;
            }
        }
        return Decision;
    }
};*/