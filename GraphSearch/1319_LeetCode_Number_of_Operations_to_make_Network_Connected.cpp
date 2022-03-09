// Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution
{
public:
    vector<vector<int>> graph;
    vector<int> visited;

    void DFS(int node)
    {
        visited[node] = true;

        for(int i=0;i<graph[node].size();i++)
            if(visited[graph[node][i]] == 0)
                DFS(graph[node][i]);
    }

    int makeConnected(int n, vector<vector<int>>& connections)
    {

        // total edges count
        int Cables = connections.size();

        // if total edge count < n-1 then conenction not possible
        if(Cables<n-1) return -1;

        // graph adjacency list
        graph.resize(n, vector<int>());
        visited.resize(n,0);

        // populate graph adjacency list
        for(int i=0;i<connections.size();i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }

        // run DFS on unvisited nodes to find total connected components
        int Clusters = 0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                DFS(i);
                Clusters++;
            }
        }

        return Clusters-1;
    }
};