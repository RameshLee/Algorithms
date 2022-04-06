// Link: https://leetcode.com/problems/diagonal-traverse/

class Solution {
public:
    int row, col;

    void moveRobot(int &i, int &j, int direction){
        switch(direction){
            case 1: --i, ++j; break; //move up-right
            case 2: ++i, --j; break; //move down-left
        }
    }

    void checkSafety(int &i, int &j, int &direction){
        if (i>=0 && j>=0 && i<row && j<col) return;
        else {
            if (direction == 1){ // check whether robot has moved out-of-bounds
                if (j>=col)    --j, ++i, ++i;
                if (i<0)       ++i;
            }
            else { // check whether robot has moved out-of-bounds
                if (i>=row)    --i, ++j, ++j;
                if (j<0)       ++j;
            }
            direction = (direction == 2) ? 1 : 2; // change direction
        }
    }

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        row = mat.size(); col = mat[0].size();

        vector<int> vec;
        int i=0, j=0, direction=1;
        while (1){

            vec.push_back(mat[i][j]);
            if (i==row-1 && j==col-1) break;
            moveRobot(i,j,direction);
            checkSafety(i,j,direction);
        }
        return vec;
    }
};