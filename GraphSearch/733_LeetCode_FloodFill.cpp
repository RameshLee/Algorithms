// Link: https://leetcode.com/problems/flood-fill/

class Solution
{
    int row; int col;
    int currColor;
    int newColor;
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
public:

    bool isSafe(int i, int j)
    {
        if (i>=0 && j>=0 && i<row && j<col) return true;
        else return false;
    }

    void DFS(vector<vector<int>>& image, int i, int j)
    {
        if (image[i][j] == currColor)
        {
            image[i][j] = newColor;

            for (int k=0; k<4; k++)
                if (isSafe( i+x[k], j+y[k] ))
                    DFS(image, i+x[k], j+y[k]);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int novelColor)
    {
        row = image.size(); col = image[0].size();

        newColor = novelColor;
        currColor = image[sr][sc];

        if (currColor != newColor)
            DFS(image, sr, sc);

        return image;
    }
};