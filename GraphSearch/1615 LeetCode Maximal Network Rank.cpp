// Link: https://leetcode.com/problems/maximal-network-rank/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // add edges
        for (auto e:roads) {
            Edges[e[0]][e[1]] = 1;
            Edges[e[1]][e[0]] = 1;
        }

        // compute node degrees
        vector<int> degrees(n,0);
        for (auto i=0; i<n; i++)
            for (auto j=0; j<=100; j++)
                if (Edges[i][j])
                    degrees[i]++;

        // compute result
        int result = 0;
        for (auto i=0; i<n; i++)
            for (auto j=0; j<n; j++)
                if (i != j)
                    result = max(result, degrees[i] + degrees[j] - Edges[i][j]);
        return result;
    }
private:
    int Edges[101][101] = {0};
};