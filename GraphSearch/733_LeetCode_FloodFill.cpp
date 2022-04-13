// Link: https://leetcode.com/problems/flood-fill/

// 1) bfs

class Solution {
private: int row,col, x[4]={1,-1,0,0}, y[4]={0,0,1,-1};
public:
    bool isSafe(int i, int j){
        return (i>=0 && j>=0 && i<row && j<col) ? true : false;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        row = image.size(), col = image[0].size();
        int startColor = image[sr][sc];

        queue<pair<int,int>> q;

        if (startColor != newColor)
            q.push(make_pair(sr,sc));

        while (!q.empty()){
            int i = q.front().first;
            int j = q.front().second; q.pop();

            image[i][j] = newColor;

            for (int k=0; k<4; k++)
                if (isSafe( i+x[k], j+y[k] ))
                    if (image[i+x[k]][j+y[k]] == startColor)
                        q.push(make_pair( i+x[k], j+y[k] ));
        }

        return image;
    }
};

// 2) dfs
/*
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
*/