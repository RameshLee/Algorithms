// Link: https://leetcode.com/problems/as-far-from-land-as-possible/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int MaxDistance = -1;
    queue<pair<int,int>> q;
    vector<vector<int>> distance;
    int row; int col;
    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,1,-1};

    bool isSafe(int i, int j)
    {
        if (i>=0 && j>=0 && i<row && j<col)
            return true;
        else return false;
    }

    void multi_start_BFS(vector<vector<int>>& grid)
    {
        int i; int j;
        while (!q.empty())
        {
            pair<int,int> val = q.front();
            i = val.first;
            j = val.second;
            q.pop();

            for (int k=0; k<4; k++)
                if (isSafe( i+x[k], j+y[k] ) && distance[i+x[k]][j+y[k]] == -1)
                {
                    q.push(make_pair(i+x[k],j+y[k]));
                    distance[i+x[k]][j+y[k]] = 1 + distance[i][j];
                    MaxDistance = max(MaxDistance, distance[i+x[k]][j+y[k]]);
                }
        }


    }

    int maxDistance(vector<vector<int>>& grid)
    {
        row = grid.size(); col = grid[0].size();
        distance.resize(row, vector<int>(col,0-1));

        int isThereLand = 0;
        int isThereWater = 0;

        // 1) store all the starting points
        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
                if (grid[i][j] == 1)
                {
                    q.push(make_pair(i,j));
                    distance[i][j] = 0;
                    isThereLand = 1;
                }
                else
                    isThereWater = 1;

        if (!isThereLand || !isThereWater)
            return -1;

        // 2) perform multi-start BFS to compute the distance values
        multi_start_BFS(grid);

        return MaxDistance;
    }
};

int main()
{
    //vector<vector<int>> grid = {{1,0,0},{1,0,0},{0,0,0}};
    //vector<vector<int>> grid = {{0,0,1,1,1},{0,1,1,0,0},{0,0,1,1,0},{1,0,0,0,0},{1,1,0,0,1}};
    vector<vector<int>> grid = {{1,0,0,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,1,1,1,0,0,1,0,1,0,1,0,1,0,1,0,1,1,0,0,1,0,1,1,0,1,1,1,1,1,0,0,1,0,0,1,1,1,0,0,1,1,1,1,1,0,0,1,0,0,0,1,0,1,0,1,0,1,1,1,1,0,0,1,0,0,1,0,1,0,0,0,1,1,1,1,1,0,1,1,0,0,1},{0,0,0,1,1,0,1,0,0,1,0,1,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,1,0,0,0,1,0,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,1,0,0,1,1,1,1,1,1,1,0,1,1,0,1,1,0,0,1,0,0,1,1,0,0,1,0,0,0,1,0,0,0,0,1,1,1,1,1},{0,0,1,0,0,0,0,1,0,0,1,1,1,0,0,0,0,1,0,0,1,0,1,1,1,0,0,0,0,1,0,0,1,0,1,0,0,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,0,0,1,0,1,1,1,1,1,0,1,0,1,1,0,0,0,1,1,1,1,0,0,1,0,1,1,1,0,0,1,0,0,1,1,0,0,1,0,1,1,0,1,1,0,1,1,1},{1,1,1,1,0,1,0,0,0,0,1,0,1,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,0,0,1,1,0,0,0,1,1,1,1,1,0,0,1,0,0,1,0,1,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,0,1,0,1,1,0,0,1,1,0,0,0,0},{0,0,0,1,1,1,0,1,0,1,0,0,1,1,0,1,1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,1,0,0,0,1,1,0},{0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,1,0,1,1,0,1,0,1,0,1,1,1,0,1,0,0,1,0,0,0,1,1,1,0,1,1,0,0,0,0,1,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,1,0,0,1,0,1,1,0,1,0,0,1,0,0,0,1,0,0,1,1,0,0,1,0,1,0,1,0,1,0,0,1,0,1,1,0,0,1},{1,1,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,0,1,0,1,1,0,0,1,1,1,0,0,1,1,1,0,0,1,0,1,0,0,0,1,1,1,0,1,1,0,1,1,1,0,0,0,1,0,0,0,1,1,0,1,1,0,0,0,0,1,0,0,1,1,0,0,0,0,1,0,1,1,0,0,0,0,1,0,1,0,0,0,1,0,0,0},{1,1,0,0,0,1,1,1,0,1,0,0,0,1,0,0,1,0,1,0,0,0,1,1,0,1,1,1,0,0,0,0,0,1,1,1,0,1,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,0,1,1,0,1,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,1,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,0,1},{0,1,0,0,1,0,0,1,1,0,0,1,1,1,0,1,1,0,0,1,1,0,0,0,0,1,1,1,1,1,0,1,1,0,0,1,1,0,1,0,0,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,0,1,0,1,1,1,0,1,1,0,0,0,1,1,1,0,0,0,1,0,1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,0,0,0},{1,0,1,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1,1,0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,1,1,1,0,1,1,0,1,0,1,1,1,1,0,0,0,1,1,1},{0,1,0,1,1,1,0,1,1,0,0,0,1,1,0,0,0,0,0,0,1,0,1,0,1,1,1,0,1,0,0,1,0,1,0,1,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,1,1,1,1,1,1,0,1,0,0,0,0,1,0,0,1,1,0,0,1,1,0,1,0,1,0,0,0,1,1,0,1,0,1,1,1,1,1,1,1,1,0,0,1,1,0,1,1,1},{0,0,1,0,0,0,0,1,1,0,1,0,1,1,0,0,0,1,1,1,0,1,0,0,1,0,0,0,0,0,1,1,1,0,1,1,0,1,1,1,0,1,0,0,0,0,1,1,0,1,1,1,1,1,0,0,1,1,1,0,0,1,1,0,1,0,1,1,1,0,0,1,0,0,1,1,1,0,0,1,0,1,0,1,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,0},{0,0,0,1,0,0,1,0,1,0,1,1,0,0,0,1,0,0,1,0,1,1,0,1,0,0,1,1,1,1,0,0,0,1,0,0,0,0,1,1,0,0,0,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,0,0,1,0,0,0,1,0,0,1,1,1,0,1,1,0,1,0,1,1,1,0,1,1,1,0},{1,0,0,0,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,0,0,1,0,0,0,1,0,1,0,0,1,1,0,0,1,1,1,1,0,1,1,1,1,0,0,0,1,1,0,1,1,1,1,0,1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,0,0,1,0,0,0,1,1,1,1,0,1,1,0,0,0,1,1,1,1,1,0},{1,0,1,0,0,1,0,0,1,0,0,1,1,1,0,0,1,0,0,1,0,1,0,0,1,0,1,1,0,1,1,1,1,0,0,0,0,1,1,0,0,1,0,0,1,1,0,1,0,0,0,0,1,1,0,1,1,0,1,0,1,0,0,0,1,0,0,1,0,1,1,1,0,0,0,1,0,1,1,0,0,0,0,1,0,1,0,0,1,1,0,1,1,0,0,1,1,1,0,1},{1,1,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,1,0,1,1,1,1,0,1,0,0,0,0,0,0,1,0,0,0,1,1,0,0,1,1,0,0,0,1,0,1,0,1,1,1,1,1,0,0,0,0,1,0,0,1,0,1,0,0,1,1,1,0,1,1,0,0,1,0,1,1,0,1,0,0,1,1,0,0,0,0,0,1,1,0,1,0,1,0,1},{1,1,0,1,0,0,1,1,0,0,0,1,0,0,1,0,0,0,1,0,1,0,1,1,0,1,1,0,1,1,1,0,1,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,1,1,0,1,0,1,1,1,1,1,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,1,1,0,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1},{1,1,0,0,1,1,1,1,0,1,1,0,0,1,0,0,0,1,1,1,1,1,1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0,1,1,1,0,1,1,0,1,1,1,0,0,0,0,1,0,0,1,1,0,1,1,0,0,0,1,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,0,1,1,0,1,0,1,0,1,1,0,1,1,0,1,1,1,1,1,0},{1,0,1,1,1,1,1,1,1,0,1,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0,1,1,1,1,1,0,0,1,0,1,0,0,0,1,1,0,0,1,0,1,0,1,0,0,1,0,0,1,1,0,1,0,1,0,1,1,0,0,0,0,1,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,1,1},{1,0,0,1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,0,0,0,1,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,0,1,0,0,1,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,0,1,0,0,0,1,1,0,1,1,1,0,0,1,0,1,1,1,1,0,0,0,1,1,0,1,1,0,1,1,0,0,0,0,0,1,0},{1,1,0,0,0,0,0,0,0,0,1,0,1,0,0,1,1,1,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,1,0,0,1,0,1,0,0,0,1,1,0,1,1,0,1,0,0,1,1,1,1,1,0,1,0,0,0,1,0,0,1,0,0,1,0,1,1,1,1,1,0,1,1,0,0,1,1,1,0,1,1},{1,1,1,1,0,1,1,0,0,0,1,1,0,0,0,1,0,1,0,0,0,1,1,1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,1,1,0,0,1,0,0,1,0,1,0,0,1,1,1,1,0,1,0,0,0,0,1,1,1,0,0,1,0,1,1,1,0,1,1,0,0,1,1,0,1,1,0,0,0,0,1,1,1,1},{1,0,0,1,0,0,1,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,1,0,0,1,0,1,0,1,1,0,1,1,0,1,0,1,0,0,0,0,1,1,0,1,1,1,1,0,1,0,1,1,0,0,0,1,0,1,0,0,1,0,1,0,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,1,0,0},{1,0,1,0,0,1,1,1,1,0,0,1,0,0,1,1,0,0,1,1,1,1,1,1,0,1,1,1,0,1,0,0,1,0,0,1,1,0,0,1,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,1,1,0,0,0,0,1,1,1,0,0,1,1,0,1,1,1,0,1,0,1,1,1,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,1,1,1,0,1},{0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1,0,0,1,0,1,0,1,1,0,1,1,1,0,1,1,0,0,1,0,0,0,1,0,1,1,1,1,0,0,0,0,1,0,1,0,1,0,1,1,0,1,0,1,1,1,1,1,0,0,0,0,1,1,1,0,1,1,0,1,0,0,1,1,0,0,1,1,1,0,0,0,1,1},{1,1,0,1,1,0,1,0,1,0,1,1,1,0,1,0,0,1,0,1,1,0,0,1,1,1,0,1,0,1,0,0,0,1,1,0,1,1,0,1,1,1,0,0,1,0,1,0,1,1,1,1,0,0,1,1,0,0,1,1,0,1,0,0,1,1,0,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,1,0,0,1,1,1,1,1,0,1},{1,0,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,0,0,0,1,1,1,1,1,0,1,0,1,1,0,1,1,0,0,0,1,0,0,0,0,0,1,1,0,1,0,1,1,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,1,1,1,0,1,0,0,0,0,0,1,0,1,1,0,1,0,1,1,1,0,1,1,1,1},{0,1,0,1,1,1,1,0,0,0,1,1,1,1,1,0,1,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,1,1,1,0,0,0,1,1,1,0,1,0,0,1,1,0,1,1,1,1,0,1,1,1,0,0,0,1,0,0,1,1,0,0,1,1,0,1,1,1,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1},{0,1,1,0,1,0,1,1,1,0,0,1,0,1,0,1,0,0,0,1,1,1,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,0,1,1,0,1,0,0,1,1,0,1,0,1,1,0,0,0,0,1,1,1,0,1,0,1,0,0,0,0,0,0,0},{1,0,0,1,1,1,0,0,0,0,1,0,1,0,1,0,1,1,1,1,0,1,1,0,0,1,0,1,0,1,1,1,0,1,1,1,0,0,0,1,1,0,0,1,0,1,0,1,1,1,1,0,0,1,0,0,1,0,1,0,1,0,0,1,0,0,1,0,0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,1},{0,1,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,1,1,1,0,0,0,1,1,1,0,1,1,0,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,0,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,0,1,1,0,0,1,1,0},{1,1,0,1,1,1,1,0,0,1,0,0,0,1,0,0,0,0,1,1,1,1,0,0,1,1,0,1,0,0,1,1,1,0,0,0,1,1,0,1,1,0,1,1,1,0,1,0,0,1,1,0,0,0,1,0,0,1,0,0,1,1,0,1,0,0,0,0,0,0,1,1,1,1,0,1,1,0,1,0,0,1,1,1,0,0,0,0,1,0,0,1,1,1,1,1,0,1,0,0},{0,0,1,0,1,1,0,0,0,1,1,1,1,1,0,0,0,1,0,0,1,1,1,1,1,0,0,0,0,1,0,1,1,1,0,0,0,1,0,0,0,0,0,1,1,1,1,0,1,1,0,1,0,1,1,0,1,0,1,1,1,1,0,0,1,1,1,0,1,1,1,0,0,1,1,1,1,0,1,1,0,0,1,0,0,0,1,1,1,1,1,1,0,0,1,0,0,1,1,1},{1,1,0,0,0,1,0,0,0,0,0,1,0,0,1,0,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,0,1,0,1,1,0,0,0,1,1,0,1,0,0,0,1,0,0,1,1,0,1,0,1,1,1,0,0,0,1,0,0,1,1,0,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,1},{1,0,1,1,0,1,0,1,0,1,0,0,1,1,1,0,0,1,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,0,1,1,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,1,0,1,1,1,0,0,1,0,0,1,1,0,0,1,0,1,0,0,1,1,0,1,0,1,1,0,0,1},{1,0,0,1,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,1,0,0,0,1,1,0,1,0,0,0,1,1,1,1,0,0,1,1,1,0,1,0,0,1,0,0,1,0,1,0,0,1,1,0,0,0,0,0,1,0,1,1,1,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1},{0,0,0,1,1,0,1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,1,0,1,1,1,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,1,0,0,0,1,1,0,1,1,0,0,1,1,0,1,0,0,1,0,1,0,1,1,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0},{0,0,0,1,0,1,1,1,1,1,1,1,0,1,0,0,1,0,1,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,1,0,1,1,0,1,1,0,1,0,0,1,0,1,1,1,0,0,1,1,0,1,1,0,0,0,1,1,1,1,0,1,1,0,0,1,0,1,1,0,0,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,1,0,1,1,1,0,0,0,1,1},{1,1,1,1,0,0,1,1,0,1,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,1,0,1,1,1,1,1,0,0,1,1,0,0,1,1,0,1,0,1,1,0,0,0,1,1,0,1,1,0,1},{1,0,1,0,0,1,1,1,0,1,1,1,1,0,0,1,1,1,0,1,1,1,0,1,0,0,0,0,1,0,1,1,0,0,0,0,0,1,0,1,1,1,0,1,0,1,0,0,0,1,1,1,1,0,0,0,1,0,1,1,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,0,0,1,1,1,1,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,1},{1,0,1,1,1,1,1,0,1,0,1,1,1,1,0,1,0,1,0,1,1,0,1,1,1,1,0,0,0,0,0,1,1,0,1,1,1,1,1,1,0,1,0,0,0,0,1,1,0,1,0,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,0,0,0,1,0,1,0,1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,0,0,0,1},{0,0,0,0,1,0,1,0,0,1,0,0,1,1,1,0,1,1,0,0,0,0,0,1,1,0,1,0,0,0,1,1,1,0,0,0,0,1,1,0,0,1,0,1,1,0,0,1,0,0,1,1,1,0,1,1,1,1,0,0,0,1,1,1,0,1,1,0,0,1,0,1,1,0,1,1,0,1,0,0,1,0,1,1,1,1,1,0,0,1,1,1,0,1,0,1,1,0,0,1},{0,1,0,1,1,1,0,0,1,0,0,0,0,0,0,1,0,1,1,1,1,1,0,1,0,0,1,1,1,1,1,0,0,0,1,1,0,0,0,1,0,1,0,1,0,1,1,0,1,0,1,1,0,1,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,1,0,0,0,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,1,0,0,0,0,0,1},{1,1,1,0,0,1,1,0,0,1,1,1,0,1,1,1,0,1,1,0,1,0,1,1,0,0,0,1,0,0,0,1,1,0,0,1,1,1,0,0,1,0,0,1,0,1,1,0,0,0,0,0,1,1,0,0,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,1,1,1,1,0,1,1,0,0,1,1,1},{1,1,0,0,1,1,1,1,1,0,0,1,0,0,1,0,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,0,1,1,1,1,0,0,1,1,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,0,0,1,1,1,1,0,1,0,1,0,1,1,0,1,1,1,0,0,1,0,0,1,1,1,1,1,0,0,0,1,0,1,0,0,1,1,1,1,0,0,1,1},{0,0,0,0,0,1,0,1,1,1,0,0,1,0,1,0,0,1,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,1,1,0,1,0,1,1,0,0,1,0,1,0,1,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,1,0,1},{0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,0,1,0,1,1,0,0,1,1,1,0,0,1,0,0,0,1,0,0,1,0,1,1,1,1,1,0,1,1,0,0,1,1,0,0,0,1,0,0,0,1,0,0,1,0,0,1,1,1,1,1,1,0,0,1,0,1,1,0,1,0,0,0,1,0,1,0,0,1,1,0,1,0,1,0,0,0,0,1,0,0,1,0,1},{0,1,0,0,1,0,1,1,1,1,1,1,0,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,1,0,0,1,1,0,0,0,0,1,1,1,1,1,0,0,1,1,1,0,0,1,1,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,0,0,1,0,0,1,0,0,1,0,0,1,1,1,1,1,0,1,1,0,0,1,0,1,1,1},{0,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1,1,0,1,0,1,0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,1,1,1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,0,1,1,0,1,0,0,1,0,0,0,1,1,1},{1,0,1,0,0,1,1,1,0,1,1,0,1,1,1,0,0,1,1,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,1,0,0,1,1,1,1,1,1,0,0,1,1,1,0,1,0,0,0,0,0,0,1,1,0,1,0,1,0,0,1,1,0,0,0,1,0,1,0,0,1,0,1,1,1,1,1,0,0,1,1,1,0,1,0,1,0,1,1,1,1,1},{1,0,1,1,1,0,1,1,0,0,0,1,0,1,0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,1,1,0,0,1,1,1,0,1,0,0,1,1,1,1,0,1,1,0,1,0,0,0,1,0,1,1,1,0,1,0,0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,0,1,1,1,1,0,0,1,0,0,1,1,0,1,1,1,0,0,1,1,0,0,0,1,0},{0,1,1,0,0,0,0,1,1,1,0,1,1,1,1,1,1,0,0,1,0,0,1,0,0,1,1,1,0,1,0,1,1,0,1,1,1,1,0,0,1,1,0,0,0,0,0,1,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,0,1,0,0,0,0,1,0,1,1,0,0,1,1,1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,0,0},{1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,1,0,1,1,1,1,0,0,0,0,1,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,1,0,0,1,0,1,1,0,1,1,0,0,0,0,1,1,1,0,0,1,0,1,1,1,0,1,1,1,0,1,0,1,1,0,1,1,0,0,1,1,0,0,1},{0,0,1,1,0,0,0,0,1,1,0,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,1,1,0,0,1,0,0,1,1,1,0,1,0,1,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,1,0,0,0,1,1,0,1,1,0,1,0,1,1,0,0,1,1,0,1,1,0,0,1,0,0,1,0,0,0},{1,1,1,0,0,1,0,0,0,0,1,0,0,1,0,1,1,0,0,1,0,1,0,0,0,0,0,1,1,0,1,0,0,1,1,1,1,0,1,1,0,0,1,1,1,1,1,1,0,0,0,1,0,1,0,0,0,1,1,0,0,0,1,0,1,1,1,1,1,0,1,1,1,0,0,0,1,0,0,1,0,1,1,0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,0,1},{0,0,1,0,0,1,0,0,1,1,0,0,1,1,1,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,1,0,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,1,1,1,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,0,0,0,1,0,1,0,1},{0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,0,1,0,0,1,1,1,1,0,0,1,1,1,0,0,0,1,0,1,1,0,1,1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,1,0,0,0,1,1,0,0,1,0,0,1,0,0,0,0,0,0,1},{1,1,0,1,0,0,0,1,0,1,1,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,0,0,1,0,1,0,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,0,0,1,0,1,0,0,1,1,0,1,0,0,1,1,0,1,1,1,0,0,0,1,1,1,1,0,1,1,1,1,0,0,0,0,1,0,0,1,1,0},{0,0,1,1,0,1,1,0,1,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,0,0,0,0,0,0,1,0,0,1,1,1,0,0,1,1,1,0,1,0,1,0,0,0,0,1,0,1,1,0,1,1,0,1,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,1,1,0,1,0,1,1,1,1,1,0,0,0,1,1,0},{0,1,1,0,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,1,0,1,1,1,0,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,0,1,0,0,1,0,1,1,0,1,0,1,0,1,1,1,0,0,1,1,0,1,0,0,1,1,0,1,0,1,1,0,1,0,1,0,0,1,1,0,0,1,1,0,1,1,0,1,1,1,1,0},{0,0,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,1,1,1,0,0,0,0,0,0,1,0,0,1,1,1,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,1,0,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,0,1,0,0,0,1,1,0,1,1,1,0,0,1,0,0,0,0,0,1},{1,0,1,1,0,1,0,1,0,0,1,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,1,1,1,0,1,1,1,0,1,1,0,1,0,1,0,1,0,1,0,1,1,0,0,0,1,1,0,1,0,1,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,0,1,0,0,1,0,0,0,1,0,0,1,1,1},{1,0,1,0,1,1,0,0,1,0,0,0,1,1,1,0,0,1,0,0,0,0,1,1,1,0,0,0,1,1,1,0,1,1,1,1,0,0,0,0,1,0,0,1,0,0,1,1,0,0,1,1,0,0,0,0,1,1,1,0,0,0,1,0,1,0,1,1,0,0,0,0,1,1,1,1,1,1,0,1,1,1,1,0,1,1,0,0,1,1,0,0,1,0,1,0,1,1,1,0},{1,0,1,1,1,0,0,1,1,0,0,0,0,0,1,0,0,1,1,0,1,0,1,1,0,0,1,0,0,0,1,0,0,1,0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,1,1,0,1,1,0,1,0,1,0,0,1,0,1,1,1,0,0,1,0,0,0,0,1,1,1,1,1,1,0,1,1,0,1,0,0,0},{0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,1,0,0,1,1,1,1,0,1,0,1,0,1,1,1,0,1,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,1,0,1,1,1,0,1,0,1,0,0,1,1,0,1,1,0,1,0,0,1,1,1,0,0,0,0,0,0,1,0,1,1,0,0,0,1,0,1,0,0,0,0,1,0},{0,0,0,1,1,1,0,1,1,1,0,0,1,0,0,0,0,1,0,1,1,1,1,1,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,1,1,1,0,0,0,0,1,1,0,0,1,0,1,0,0,1,1,0,1,1,0,1,1,0,1,0,0,1,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0},{0,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,0,0,0,0,1,1,1,0,1,1,0,1,1,0,0,1,0,0,0,1,0,0,1,1,1,0,1,1,1,0,0,0,1,0},{1,0,1,0,1,0,0,0,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,0,1,1,1,1,1,0,0,0,0,1,1,0,1,0,1,1,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,0,1,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,0,1,1,0,0,1,0,1,1},{0,0,0,0,0,0,1,0,1,1,1,0,0,1,0,1,0,1,0,1,0,0,1,1,0,1,1,1,0,1,1,0,0,0,1,1,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,1,1,1,0,0,1,1,1,0,1,0,1,0,1,0,0,1,0,0,1,1,0,0,1,0,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,1},{1,1,0,1,0,0,1,1,0,1,0,1,0,0,1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,0,1,0,0,0,1,0,1,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,1,0,1,1,0,1,1,1,1,1,1,0,0,1,0,1,0,1,1,1,0,1,0,0},{1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0,1,1,0,1,0,0,1,0,0,1,0,1,1,0,1,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,1,0,1,1,0,1,1,1,0,0,1,0,0,0,1,0,0,0,1,0,1,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,1},{1,0,0,0,1,1,0,0,1,1,0,1,1,0,1,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,1,0,0,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,0,1,0,0,1,1,1,1,0,1,0,0,0,1},{1,0,1,1,0,0,1,0,1,1,0,0,0,0,1,0,0,1,0,1,1,0,1,0,0,1,1,1,1,1,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,1,0,1,0,1,1,1,0,1,0,0,1,1,1,1,0,1,0,1,0,1,1,0,1,0,0,1,0,1,0,0,0,1,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0},{0,1,0,0,0,1,1,0,0,1,0,1,0,1,1,1,1,0,1,0,1,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,1,0,0,0,0,0,1,0,1,0,1,0,0,1,0,0,1,1,0,0,1,1,1,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,1,0,1},{0,0,0,0,0,1,1,0,1,1,1,1,1,0,1,1,1,0,0,1,0,0,1,1,0,1,1,0,1,1,0,1,1,0,1,0,0,0,1,0,1,1,1,1,0,0,1,1,1,0,0,1,0,1,1,0,0,1,1,0,0,1,1,0,1,0,0,0,1,1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0},{1,1,0,0,0,1,1,0,0,0,1,0,1,0,1,1,0,0,1,1,1,1,1,0,0,1,0,1,1,1,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,0,1,1,0,1,0,0,0,1,0,1,1,0,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,1,0,1},{0,1,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,0,1,0,1,1,0,1,1,0,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,1,1,0,1,0,1,1,1,1,1,0,1,0,0,0,1,1,0,1,1},{0,1,0,0,1,0,0,0,0,1,0,1,1,1,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,0,1,0,0,0,1,0,0,1,0,0,1,0,1,1,1},{0,1,0,1,0,0,0,1,0,0,0,1,0,1,1,1,0,0,1,1,1,1,1,0,1,0,1,1,0,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,1,0,1,1,1,0,1,1,0,0,0,0,0,1,1,1,1,1,0,1,0,1,0,1,1,0,1},{1,1,1,1,0,0,0,1,0,0,1,1,0,1,0,1,1,1,0,0,0,1,0,1,0,0,1,0,1,0,0,1,1,0,1,1,0,1,1,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,1,0,0,1,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,1,0,1,0,1,1,1},{1,0,0,0,0,1,1,1,0,1,0,1,0,0,1,1,1,0,1,0,0,0,0,1,1,0,1,1,0,0,0,1,1,1,0,1,1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,1,0,1,1,0,0,1,0,1,0,1,0,1,0,0,0,0,1,1,0,1,1,0,0,0,1,0,0},{0,1,1,0,0,0,1,1,1,0,1,0,0,1,1,0,0,1,1,1,0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,1,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0,1,0,0,0,1,1,1,0,0,0,0,1,0,0,1,0,0,1,1,0,1,0,1,0,1,1,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,1,1,1,1,1,1,1,0},{0,1,1,1,1,0,0,1,1,0,0,0,0,0,1,0,0,0,1,1,0,1,1,0,0,1,1,0,0,1,1,0,1,0,0,0,1,1,1,1,0,1,0,0,0,0,0,0,1,1,0,0,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,0,1,1,0,1,1,0,1,1,1,0,0,1,0,1,1,0,1,1,1,1,0,1,1,0,1,0,0,1},{1,0,0,0,1,1,1,0,0,1,1,1,1,0,1,0,0,1,0,0,1,1,1,0,1,0,1,0,0,1,1,1,0,1,1,1,0,0,1,0,0,0,1,1,0,1,0,1,1,0,0,1,1,0,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,1,0,0,1,1,1,1,1,0,1,1,0,0,0,1,0,1,0,0,0,0,0,0,1,1,1,0,0,1,1,1},{1,0,0,1,0,1,0,0,1,0,0,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,0,1,1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,1,1,1,1,0,1,1,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,1,1,1,1,0,1,1,0,0,1,1,0,0,0,1,1,1,0,0,0,1,0,1},{1,1,1,1,1,1,1,0,0,1,1,0,1,1,0,1,0,1,1,0,0,1,0,0,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,0,1,0,0,0,0,1,0,0,1,1,1,0,1,0,0,0,1,1,1,0,0,1,1,1,0,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,1,0,1,1,1,0,1,0,1},{1,0,0,0,1,1,1,0,0,0,1,0,0,0,1,1,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,0,0,1,0,1,1,0,0,1,1,0,1,1,1,0,0,1,0,0,1,0,1,0,0,0,0,0,1,1,1,1,1,1,0,0,1,0,0,1,1,1,0,1,0,0,1,1,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1},{0,1,1,0,0,1,0,1,1,1,1,1,0,1,0,0,1,1,0,1,0,0,0,1,1,1,1,0,0,0,0,0,1,1,0,0,1,1,1,0,1,1,0,1,0,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0,1,1,1,1,0},{1,0,0,0,0,1,1,0,1,0,1,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,1,0,0,1,1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,1,1,1,1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,0,0,0,1,0},{1,1,0,0,1,0,0,0,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,1,1,0,1,0,1,1,1,0,1,0,0,0,1,1,0,1,0,0,0,1,1,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,1,0,0,0,1,0,1,1,0,0,0,0,1,0},{1,0,0,1,1,0,0,1,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,0,1,0,0,1,0,1,1,1,1,1,0,0,0,0,1,0,1,1,1,0,0,1,1,0,1,0,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,1,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},{0,0,1,1,0,1,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,1,1,1,1,1,0,0,1,0,0,1,1,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,1,1,1,0,0,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,0,1,0,0,1,1,1,0,0,0,1,0,0,1,1,0},{0,1,0,0,1,1,0,0,1,1,1,0,1,1,1,1,0,1,0,1,1,0,0,1,0,1,1,0,0,1,0,1,0,0,0,1,0,1,1,0,0,0,1,1,1,1,1,0,1,0,0,0,1,1,1,0,1,1,1,0,1,1,0,0,0,1,0,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1,0,1,0,0,1,0},{1,0,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,1,1,1,1,0,1,1,1,0,0,1,1,0,1,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,1,0,1,0,1,1},{0,0,1,1,0,0,1,0,0,0,0,0,1,1,0,1,0,0,1,0,0,0,0,0,1,0,1,1,1,0,0,0,0,1,0,1,1,1,1,1,0,0,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,0,1,1,1,0,0,0,1,0,1,1,0,0,1,0,0},{1,1,0,1,0,1,0,0,0,0,1,0,0,0,0,1,1,0,1,1,1,0,0,0,0,1,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,0,1,0,1,1,0,0,0,0,1,1,0,1,1,1,1,0,0,0,0,1,1,1,0,1,0,0,0,1,1,1,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,1,1,1},{0,1,0,0,0,1,1,0,1,0,0,0,0,1,0,0,0,1,0,1,1,1,0,0,0,1,0,0,0,1,0,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,0,1,1,1,1,0,0,1,0,0,0,0,0,1,1,0,1,0,0,1,1,1,0,0,1,1,1,0,1,1,0,0,0,0,1,0,1,1,0,0,1,1,0,1,1,1,0,0,0,1},{0,0,0,0,1,0,1,1,0,1,1,1,1,0,0,1,1,0,1,0,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,1,0,1,0,0,1,1,1,1,1,1,0,1,0,1,0,0,1,1,1,0,0,1,1,1,0,0,1,0,1,1,0,1,1,1,1,1,1,1,0,0,1,0,1,1,1,1,0,0,1,0,1,1},{1,1,1,0,0,0,0,1,0,1,1,1,0,0,0,1,0,0,1,0,0,1,1,0,0,1,0,1,1,1,0,0,0,0,1,1,1,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,1,1,0,1,0,0,1,1,0,0,1,1,0,1,1,1,1,0,0,0,1,0,0,0,0,1,1,0,0,1,1,0,0,1},{0,0,1,1,0,0,0,0,0,0,1,1,0,1,1,0,1,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,0,1,1,1,1,0,1,1,0,1,1,0,0,0,1,0,1,0,1,0,1,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,1,0,0,1,0,1}};
    
    Solution S;
    clock_t Start = clock();
    int a = S.maxDistance(grid);
    printf("Time: %0.02f\n", (float)(clock()-Start)/CLOCKS_PER_SEC*1000);

    printf("\n\nExited the Program\n");
    return 0;
}