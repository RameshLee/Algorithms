//Link: https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    int n;
    vector<int> color;

    bool Decision = true;
    int CurrColor = 0;

    bool CheckViolations(vector<vector<int>>& graph, int i)
    {
        //violation: if two adj nodes have same color
        for (int j=0; j<graph[i].size(); j++)
            if (color[i] == color[graph[i][j]])
            {
                Decision = false;
                return true;
            }

        return false;
    }

    void DFS(vector<vector<int>>& graph, int i)
    {
        if (color[i] == -1)
        {
            color[i] = CurrColor;
            CurrColor = abs(CurrColor-1);

            if (CheckViolations(graph,i))
                return;

            //explore recursively
            for (int j=0; j<graph[i].size(); j++)
                DFS(graph, graph[i][j]);

            CurrColor = abs(CurrColor-1);
        }

    };

    bool isBipartite(vector< vector<int> >& graph)
    {
        n = graph.size();
        color.resize(n,-1);

        //2-graph coloring using dfs
        DFS(graph, rand()%n);

        // make sure all nodes are already explored!
        for (int i=0; i<n; i++)
            if (color[i] == -1)
                DFS(graph, i);

        return Decision;
    }
};
