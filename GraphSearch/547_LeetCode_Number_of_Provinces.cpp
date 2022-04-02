// Link: https://leetcode.com/problems/number-of-provinces/

class Solution {
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