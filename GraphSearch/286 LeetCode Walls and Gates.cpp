// Link: https://leetcode.com/problems/walls-and-gates/

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {

        row = rooms.size(), col = rooms[0].size();

        // enqueue all gates
        queue<pair<int,int>> q;
        for (auto i=0; i<row; i++)
            for (auto j=0; j<col; j++)
                if (rooms[i][j] == 0)
                    q.push(make_pair(i,j));

        // apply multi-start bfs from gates towards empty cells
        while (!q.empty()){
            int i = q.front().first;
            int j = q.front().second; q.pop();

            for (int k=0; k<4; k++)
                if (isSafe( i+x[k], j+y[k] ))
                    if (rooms[i+x[k]][j+y[k]] == 2147483647){
                        rooms[i+x[k]][j+y[k]] = 1 + rooms[i][j];
                        q.push(make_pair(i+x[k], j+y[k]));
                    }
        }
    }
private:
    int row,col,x[4]={1,-1,0,0}, y[4]={0,0,1,-1};

    bool isSafe(int i, int j){
        return (i>=0 && j>=0 && i<row && j<col) ? true : false;
    }
};