// Link: https://leetcode.com/problems/number-of-provinces/

class Solution
{
public:
    int Count = 0;
    vector<int> visited;

    void DFS(vector<vector<int>>& isConnected, int i)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            for (int j=0; j<isConnected[i].size(); j++)
                if (isConnected[i][j] == 1)
                    DFS(isConnected, j);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        visited.resize(isConnected.size(), 0);

        for (int i=0; i<isConnected.size(); i++)
            if (visited[i] == 0)
            {
                DFS(isConnected, i);
                Count++;
            }

        return Count;
    }
};