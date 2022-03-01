// Problem Statement: https://tenderleo.gitbooks.io/leetcode-solutions-/content/GoogleHard/317.html
// Problem: Find a node in (0) that has shortest path to all buildings(1), where (2) is wall.

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution
{
    int building_count = 0;
    vector<pair<int,int>> building_position;
    vector<vector<int>> cumulative_dist; //from all buildings to all lands
    vector<vector<int>> dist; //from one building to all lands
    vector<vector<int>> visited;
    vector<vector<int>> trace;
public:
    void BFS(pair<int,int> source, vector<vector<int>> &grid)
    {

        // 1) clear visited array and set dist to max
        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[i].size(); j++)
            {
                visited[i][j] = 0;
                dist[i][j] = INT_MAX;
            }

        // 2) BFS to find min dist to all lands(0) from source building(1)

        vector<pair<int,int>> queue;
        int a = source.first; int b = source.second;
        queue.push_back(make_pair(a,b));
        visited[a][b] = 1;
        dist[a][b] = 0;

        //printf("source: (%d,%d)\n", a,b);

        int traversal_dist = 1;
        while (!queue.empty())
        {
            int i = queue[0].first;
            int j = queue[0].second;
            queue.erase(queue.begin());
            if (visited[i][j] == 0)
                trace[i][j]++;
            visited[i][j] = 1;


            //printf("    current: (%d,%d) dist: %d\n", i,j, dist[i][j]);

            if (i-1 >= 0 && grid[i-1][j] == 0) // up
                if (visited[i-1][j] == 0)
                {
                    if (dist[i-1][j] > 1 + dist[i][j])
                        dist[i-1][j] = 1 + dist[i][j];
                    queue.push_back(make_pair(i-1,j));
                   // printf("neighbor: (%d,%d) newdist: %d\n", i-1,j, dist[i-1][j]);
                }

            if (j-1 >= 0 && grid[i][j-1] == 0) // left
                if (visited[i][j-1] == 0)
                {
                    if (dist[i][j-1] > 1 + dist[i][j])
                        dist[i][j-1] = 1 + dist[i][j];
                    queue.push_back(make_pair(i,j-1));
                   // printf("neighbor: (%d,%d) newdist: %d\n", i,j-1, dist[i][j-1]);
                }

            if (i+1 < grid.size() && grid[i+1][j] == 0) // down
                if (visited[i+1][j] == 0)
                {
                    if (dist[i+1][j] > 1 + dist[i][j])
                        dist[i+1][j] = 1 + dist[i][j];
                    queue.push_back(make_pair(i+1,j));
                   // printf("neighbor: (%d,%d) newdist: %d\n", i+1,j, dist[i+1][j]);
                }

            if (j+1 < grid[0].size() && grid[i][j+1] == 0) // right
                if (visited[i][j+1] == 0)
                {
                    if (dist[i][j+1] > 1 + dist[i][j])
                        dist[i][j+1] = 1 + dist[i][j];
                    queue.push_back(make_pair(i,j+1));
                  //  printf("neighbor: (%d,%d) newdist: %d\n", i,j+1, dist[i][j+1]);
                }
            traversal_dist++;
        }

        // print utility
        /*for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[i].size(); j++)
                if (grid[i][j] == 0)
                    printf("dist[%d][%d] = %d\n", i,j,dist[i][j]);
         printf("--------\n");

        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[i].size(); j++)
                if (grid[i][j] == 0)
                   printf("trace[%d][%d] = %d (%d)\n", i,j,trace[i][j], cumulative_dist[i][j]);
        */

    }

    int shortestDistance(vector<vector<int>> &grid)
    {
        // 1) initilization
        int result;
        cumulative_dist.resize(grid.size());
        dist.resize(grid.size());
        visited.resize(grid.size());
        trace.resize(grid.size());
        for (int i=0; i<grid.size(); i++)
        {
            cumulative_dist[i].resize(grid[i].size());
            dist[i].resize(grid[i].size());
            visited[i].resize(grid[i].size());
            trace[i].resize(grid[i].size());

            for (int j=0; j<grid[i].size(); j++)
            {

                if (grid[i][j] == 1)
                {
                    building_count++;
                    building_position.push_back(make_pair(i,j));
                }
                if (grid[i][j] == 0)
                {
                    cumulative_dist[i][j] = 0;
                    trace[i][j] = 0;
                }
                else
                {
                   cumulative_dist[i][j] = INT_MAX;
                   trace[i][j] = INT_MAX;
                }
            }
        }

        // 2) apply bfs from all buildings (1) to compute dist to the lands (0)
        for (int i=0; i<building_position.size(); i++)
        {
           BFS(building_position[i], grid);

           //accumulate distance values
            for (int i=0; i<grid.size(); i++)
                for (int j=0; j<grid[i].size(); j++)
                    if (grid[i][j] == 0)
                        cumulative_dist[i][j] += dist[i][j];


//            for (int i=0; i<grid.size(); i++)
//                for (int j=0; j<grid[i].size(); j++)
//                {
//                    printf("cumulative_dist[%d][%d] = %d\n", i,j,cumulative_dist[i][j]);
//                }
        }

        // 3) compute min_distance and optimal land
        unsigned int Min_Distance = INT_MAX;
        pair<int,int> Optimal_Land;
        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[i].size(); j++)
                if (grid[i][j] == 0)
                    if (trace[i][j] == building_count)
                        if (cumulative_dist[i][j] < Min_Distance)
                        {
                            Min_Distance = cumulative_dist[i][j];
                            Optimal_Land = make_pair(i,j);
                        }

        // print utility
        /*for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[i].size(); j++)
                if (grid[i][j] == 0)
                    printf("cumulative_dist[%d][%d] = %d\n", i,j,cumulative_dist[i][j]);

        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[i].size(); j++)
                if (grid[i][j] == 0)
                    if (trace[i][j] == building_count)
                        printf("trace[%d][%d] = %d (%d)\n", i,j,trace[i][j], cumulative_dist[i][j]);
        */

        printf("Min Shortest Path is %d from (%d,%d)\n", Min_Distance, Optimal_Land.first, Optimal_Land.second);

        return result;
    }
};

int main()
{
  //  vector<vector<int>> grid= {{1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0}};
    vector<vector<int>> grid= {{0,2,0,2,2,0,2,2},{0,2,2,2,1,0,1,2},{0,0,0,1,0,2,0,0},{2,0,0,2,0,2,2,0},{0,0,0,2,0,0,0,0}};

    Solution S;
    int a = S.shortestDistance(grid);

    printf("\nExited the Program!\n");
    return 0;
}