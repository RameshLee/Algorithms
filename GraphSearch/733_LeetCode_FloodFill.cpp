// Link: https://leetcode.com/problems/flood-fill/

// 1) bfs

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        this->row = image.size(), this->col = image[0].size();

        // apply bfs from source
        queue<pair<int,int>> q;
        int startColor = image[sr][sc];
        if (startColor != newColor) q.push(make_pair(sr,sc));
        while (!q.empty()){
            int i=q.front().first, j=q.front().second; q.pop();
            image[i][j] = newColor;

            for (int k=0; k<4; k++)
                if (isSafe( i+dir[k], j+dir[k+1] ))
                    if (image[i+dir[k]][j+dir[k+1]] == startColor)
                        q.push(make_pair( i+dir[k], j+dir[k+1] ));
        }
        return image;
    }
private:
    int row,col, dir[5] = {1,0,-1,0,1};

    bool isSafe(int i, int j){
        return (i>=0 && j>=0 && i<row && j<col) ? true : false;
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