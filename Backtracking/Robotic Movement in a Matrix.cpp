// Link: https://leetcode.com/problems/spiral-matrix/

// Robotic Movement in a Matrix (Faster than 100%)

class Solution {
public: enum directions{RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3};

    bool isSafe(int i, int j, vector<vector<int>>& matrix){
        if (i>=0 && j>=0 && i<matrix.size() && j<matrix[0].size()) return true;
        return false;
    }

    void turnRobot_At_boundary(int &dir, int i, int j, vector<vector<int>>& matrix){
        switch (dir){
            case RIGHT: if (++j>=matrix[0].size()) dir = DOWN; break;
            case DOWN:  if (++i>=matrix.size())    dir = LEFT; break;
            case LEFT:  if (--j<0)                 dir = UP;   break;
            case UP:    if (--i<0)                 dir = RIGHT; break;
        }
    }

    void moveRobot(int dir, int &i, int &j, vector<vector<int>>& matrix){
        switch (dir){
            case RIGHT: if (isSafe(i,j+1, matrix)) ++j; break;
            case DOWN:  if (isSafe(i+1,j, matrix)) ++i; break;
            case LEFT:  if (isSafe(i,j-1, matrix)) --j; break;
            case UP:    if (isSafe(i-1,j, matrix)) --i; break;
        }
    }

    void turnRobot(int &dir){
        switch (dir){
            case RIGHT: dir = DOWN; break;
            case DOWN:  dir = LEFT; break;
            case LEFT:  dir = UP; break;
            case UP:    dir = RIGHT; break;
        }
    }

    void bfs(vector<int>& vec, vector<vector<int>>& matrix){
        using pi = pair<int,int>;
        queue<pair<pi,int>> q; // pair(coordinates,direction);
        q.push(make_pair( make_pair(0,0), 0 )); // robot starting positions

        while (1){
            pi p = q.front().first;
            int dir = q.front().second; q.pop();
            int i=p.first, j=p.second;

            vec.push_back(matrix[i][j]);
            matrix[i][j] = INT_MAX; // mark as visited

            int k = 0;
            while (q.empty()) {

                turnRobot_At_boundary(dir,i,j, matrix); // turn if robot hits the wall.
                int x=i, y=j; // backup original robot positions

                moveRobot(dir,i,j, matrix); // try moving ahead
                if (matrix[i][j] == INT_MAX) { // no feasible position ahead? then turn direction.
                     turnRobot(dir);
                     i=x, j=y; // restore original robot positions
                     if (k>3) return; k++; // all four directions are blocked! exit.
                }
                else q.push(make_pair( make_pair(i,j), dir )); // inject new visit position
            }
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> vec;
        bfs(vec,matrix);
        return vec;
    }
};