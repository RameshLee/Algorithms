// Link: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

class Solution
{
public:
    vector<vector<int>> undirectedConnections;
    vector<int> visited;

    vector<vector<int>> validity;

    int ReversibleEdges = 0;

    void DFS(vector<vector<int>>& connections, int i)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;

            //printf("visited: %d\n", i);

            for (auto& it:undirectedConnections[i])
            {
                //printf("    InvestigatingEdge: (%d,%d):\n", i,it);
                /*int found = 0;
                for (auto& elem:connections)
                {
                    if (elem[0] == i && elem[1] == it)
                        if (visited[it] == 0)
                        {
    printf("    ----Checking: (%d,%d): Found (%d,%d)\n",i,it,elem[0],elem[1]);
                             found = 1;
                             goto Jump;
                        }
                }
                Jump:
                if (found) ReversibleEdges++;
                */


                if (visited[it] == 0)
                    if (validity[i][it])
                    {
                       // printf("validity[%d][%d]=1\n", i,it);
                        ReversibleEdges++;
                    }


               // printf("ReversibleEdges=%d\n",ReversibleEdges );
                DFS(connections, it);
            }
        }

    }

    int minReorder(int n, vector<vector<int>>& connections)
    {
        undirectedConnections.resize(n, vector<int>());
        validity.resize(n,vector<int>(n,0));
        visited.resize(n,0);

        for (auto& edge:connections)
        {
            int a = edge[0];
            int b = edge[1];

            validity[a][b] = 1;

            undirectedConnections[a].push_back(b);
            undirectedConnections[b].push_back(a);
        }

        //print undirected graph
        /*for (int i=0; i<undirectedConnections.size(); i++)
        {
            printf("FOR i=%d: ", i);
            for (auto& it:undirectedConnections[i])
                printf("%d ", it);
            printf("\n");
        }*/

        /*for (int i=0; i<validity.size(); i++)
            for (int j=0; j<validity[i].size(); j++)
                if (validity[i][j])
                    printf("validity[%d][%d]=1\n", i,j);*/


        DFS(connections, 0);

        return ReversibleEdges;
    }
};