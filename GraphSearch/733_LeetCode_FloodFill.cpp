// Link: https://leetcode.com/problems/flood-fill/

class Solution
{
    int currentColor;
    int newColor;
    vector<vector<int>> visited;
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};
public:
    bool isSafe(int i, int j)
    {
        if (i>=0 && j>=0 && i<visited.size() && j<visited[0].size())
            return 1;
        else return 0;
    }

    void DFS(vector<vector<int>>& image, int i, int j)
    {
        if (visited[i][j] == 0 && image[i][j] == currentColor)
        {
            visited[i][j] = 1;
            image[i][j] = newColor;

            //check neighbors: up,down,left,right
            for (int l=0; l<4; l++)
                if (isSafe(i+x[l], j+y[l]))
                    DFS(image,i+x[l], j+y[l]);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcol)
    {
        visited.resize(image.size(), vector<int>(image[0].size(),0));
        newColor = newcol;
        currentColor = image[sr][sc];
        DFS(image, sr, sc);

        return image;
    }
};