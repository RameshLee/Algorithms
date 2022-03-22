// Link: https://leetcode.com/problems/shortest-distance-from-all-buildings/
// Problem Statement: Find a node in (0) that has shortest path to all buildings(1), where (2) is wall.
// Algorithm: Apply BFS from all buildings(1) to find dist to empty lands(0), then return the minimum of summation of dist values at lands(0)

#include <iostream>
#include <vector>
#include <utility>
#include <time.h>
using namespace std;


class Solution
{
public:
    int building_count = 0;
    int Marker = 0;
    vector<pair<int,int>> building_position;
    vector<vector<int>> cumulative_dist; //from all buildings to all lands
    vector<vector<int>> dist; //from one building to all lands
    vector<vector<int>> visited;
    vector<vector<int>> trace;

    int row; int col;
    int x[4] ={1,-1,0,0};
    int y[4] ={0,0,1,-1};

    bool isSafe(int i, int j){
        if (i>=0 && j>=0 && i<row && j<col) return true;
        else return false;
    }

    void BFS(pair<int,int> source, vector<vector<int>> &grid)
    {

        Marker++;

        // 1) BFS to find min dist to all lands(0) from source building(1)
        vector<pair<int,int>> queue;
        int a = source.first; int b = source.second;
        queue.push_back(make_pair(a,b));
        visited[a][b] = Marker;
        dist[a][b] = 0;

        while (!queue.empty())
        {
            int i = queue[0].first;
            int j = queue[0].second;
            queue.erase(queue.begin());

            for (int k=0; k<4; k++)
                if (isSafe( i+x[k], j+y[k] ))
                     if (trace[i+x[k]][j+y[k]] == Marker-1)
                         if (visited[i+x[k]][j+y[k]] != Marker){

                            dist[i+x[k]][j+y[k]] = 1 + dist[i][j];
                            cumulative_dist[i+x[k]][j+y[k]] += dist[i+x[k]][j+y[k]];
                            queue.push_back(make_pair(i+x[k], j+y[k]));
                            visited[i+x[k]][j+y[k]] = Marker;
                            trace[i+x[k]][j+y[k]]++;
                        }
        }
    }

    int shortestDistance(vector<vector<int>> &grid)
    {

        // 1) initilization
        int result;
        row = grid.size(); col = grid[0].size();
        cumulative_dist.resize(grid.size());
        dist.resize(grid.size());
        visited.resize(grid.size());
        trace.resize(grid.size());
        int ThereIsNoLand = 1;
        for (int i=0; i<grid.size(); i++)
        {
            cumulative_dist[i].resize(grid[i].size());
            dist[i].resize(grid[i].size());
            visited[i].resize(grid[i].size());
            trace[i].resize(grid[i].size());

            for (int j=0; j<grid[i].size(); j++)
            {
                visited[i][j] = 0;
                // count buildings
                if (grid[i][j] == 1)
                {
                    building_count++;
                    building_position.push_back(make_pair(i,j));
                }
                // initialize variables
                if (grid[i][j] == 0)
                {
                    cumulative_dist[i][j] = 0;
                    trace[i][j] = 0;
                    ThereIsNoLand = 0;
                }
                else
                {
                   cumulative_dist[i][j] = INT_MAX;
                   trace[i][j] = INT_MAX;
                }
            }
        }
        // check corner cases
        if (ThereIsNoLand)
            return -1;
        if (!building_count)
            return -1;

        // 2) apply bfs from all buildings (1) to compute dist to the lands (0)
        for (int i=0; i<building_position.size(); i++)
        {
           BFS(building_position[i], grid);
        }

        // 3) compute min_distance and optimal land
        unsigned int Min_Distance = INT_MAX;
        pair<int,int> Optimal_Land;

        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[i].size(); j++)
                if (trace[i][j] == building_count)
                    if (cumulative_dist[i][j] < Min_Distance)
                    {
                        Min_Distance = cumulative_dist[i][j];
                        Optimal_Land = make_pair(i,j);
                    }

        if (Min_Distance == INT_MAX)
            Min_Distance = -1;

       // printf("Min Shortest Path is %d from (%d,%d)\n", Min_Distance, Optimal_Land.first, Optimal_Land.second);

        return Min_Distance;
    }
};

int main()
{
   vector<vector<int>> grid= {{1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0}};
    //vector<vector<int>> grid= {{0,2,0,2,2,0,2,2},{0,2,2,2,1,0,1,2},{0,0,0,1,0,2,0,0},{2,0,0,2,0,2,2,0},{0,0,0,2,0,0,0,0}};

    //vector<vector<int>> grid= {{0,2,1},{1,0,2},{0,1,0}};

    //vector<vector<int>> grid= {{2,0,0,2,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,1,2,0,2,0,1,1,0},{0,1,0,1,1,2,0,0,2,0,0,2,0,2,2,0,2,0,2,0,0,0,0,0,0,0,0,0},{1,0,0,1,2,0,0,2,0,2,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,0,0,2},{0,0,2,2,2,1,0,0,2,0,0,0,0,0,0,0,0,0,2,2,2,2,1,0,0,0,0,0},{0,2,0,2,2,2,2,1,0,0,0,0,1,0,2,0,0,0,0,2,2,0,0,0,0,2,2,1},{0,0,2,1,2,0,2,0,0,0,2,2,0,2,0,2,2,2,2,2,0,0,0,0,2,0,2,0},{0,0,0,2,1,2,0,0,2,2,2,1,0,0,0,2,0,2,0,0,0,0,2,2,0,0,1,1},{0,0,0,2,2,0,0,2,2,0,0,0,2,0,2,2,0,0,0,2,2,0,0,0,0,2,0,0},{2,0,2,0,0,0,2,0,2,2,0,2,0,0,2,0,0,2,1,0,0,0,2,2,0,0,0,0},{0,0,0,0,0,2,0,2,2,2,0,0,0,0,0,0,2,1,0,2,0,0,2,2,0,0,2,2}};

    Solution S;
    int a = S.shortestDistance(grid);

    printf("\nExited the Program!\n");
    return 0;
}