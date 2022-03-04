// Link: https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    int row; int col;
    vector<vector<int>> output;
    vector<vector<int>> visited;
    vector<vector<int>> pacific;
    vector<vector<int>> atlantic;

    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,1,-1};

    bool isSafe(int i, int j)
    {
        if (i>=0 && j>=0 && i<row && j<col)
            return true;
        else return false;
    }

    void DFS(vector<vector<int>>& grid, int i, int j, int Marker, int Option)
    {
        if (visited[i][j] != Marker)
        {
            visited[i][j] = Marker;

            if (Option == 1)
                pacific[i][j] = 1;
            else if (Option == 2)
                atlantic[i][j] = 1;

            // recursively explore neighbors
            for (int k=0; k<4; k++)
                if (isSafe( i+x[k], j+y[k] ))
                    if (grid[i][j] <= grid[i+x[k]][j+y[k]])
                        DFS(grid, i+x[k], j+y[k], Marker, Option);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid)
    {
        row = grid.size(); col = grid[0].size();
        visited.resize(row, vector<int>(col,0));
        pacific.resize(row, vector<int>(col,0));
        atlantic.resize(row, vector<int>(col,0));



        // reverse approach: apply dfs from border lands to reach inner lands
        int Marker = 1;

        for (int j=0; j<col; j++, Marker++)
            DFS(grid,0,j,Marker,1);

        for (int i=0; i<row; i++, Marker++)
            DFS(grid,i,0,Marker,1);

        for (int i=0; i<row; i++, Marker++)
            DFS(grid,i,col-1,Marker,2);

        for (int j=0; j<col; j++, Marker++)
            DFS(grid,row-1,j,Marker,2);

        // load output
        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
                if (pacific[i][j] + atlantic[i][j] == 2)
                    output.push_back(vector<int>({i,j}));

        return output;
    }
};