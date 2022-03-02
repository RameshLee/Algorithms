// C++ Program to check Bipartite graph using DFS at O(V+E) complexity

// Problem statement: Refer 785. Is Graph Bipartite?
//Link: https://leetcode.com/problems/is-graph-bipartite/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> vec;
    int visited[1000];
    int color[1000];
    int total_visited = 0;

    bool Decision = true;
    int current_color = 0;

    void DFS(vector<vector<int>>& graph, int i)
    {
        if (visited[i] == 0)
        {
            printf("Entering at i=%d (%d)\n", i, current_color);
            vec.push_back(i);
            total_visited++;
            visited[i] = 1;
            color[i] = current_color;

            for (int j=0; j<graph[i].size(); j++)
                if (color[i] == color[graph[i][j]])
                    Decision = false;

            current_color = (current_color == 1) ? 0 : 1;

            for (int j=0; j<graph[i].size(); j++) //adjacent nodes
                DFS(graph, graph[i][j]);

            current_color = (current_color == 1) ? 0 : 1;
            printf("Ending for loop for i=%d (%d)\n", i, current_color);
        }

    };

    void DFS_traversal(vector< vector<int> >& graph)
    {

        for (int i=0; i<100; i++)
        {
            visited[i] = 0;
            color[i] = -1;
        }

        int source = 0;
        if (graph[source].size() == 0)
            for (int i=1; i<graph.size(); i++)
                if (graph[i].size() > 0)
                {
                    source = i;
                    break;
                }
        printf("source: %d\n", source);
        DFS(graph, source);

        while (total_visited != graph.size())
        {
            int s = rand() % graph.size();
            DFS(graph, s);
        }
    }

    bool isBipartite(vector< vector<int> >& graph)
    {
        DFS_traversal(graph);

        for (int i=0; i<vec.size(); i++)
            printf("%d -", vec[i]);


        return Decision;
    }
};

// Driver Code 
int main() 
{
    vector< vector<int> > graph = {{},{2,4,6},{1,4,8,9},{7,8},{1,2,8,9},{6,9},{1,5,7,8,9},{3,6,9},{2,3,4,6,9},{2,4,5,6,7,8}};

    Solution Sol;
    bool Decision = Sol.isBipartite(graph);
    printf("Is it Bipartite?: %s\n", (Decision)? "True" : "False");
    return 0; 
} 
