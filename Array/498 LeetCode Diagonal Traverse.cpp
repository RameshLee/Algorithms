// Link: https://leetcode.com/problems/diagonal-traverse/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        row = mat.size(); col = mat[0].size();
        vector<int> result;

        i=0, j=0, direction=SKY;
        while (1){
            result.push_back(mat[i][j]);
            if (i==row-1 && j==col-1) break;
            moveRobot();
        }
        return result;
    }
private:
    int row, col; // matrix size
    enum trajectory{SKY, GROUND}; // trajectory
    int i,j,direction; // robot positions & direction

    void moveRobot(){

        // advance the robot position
        switch(direction){
            case SKY:    --i, ++j; break; //move up-right
            case GROUND: ++i, --j; break; //move down-left
        }

        // if robot goes out-of-bound positions
        if (i<0 || j<0 || i>=row || j>=col) {
            // retract to feasible position
            switch(direction){
                case SKY:    if (j>=col)    --j, ++i, ++i; // goes out of right-side
                             if (i<0)       ++i;           // goes out of top
                case GROUND: if (i>=row)    --i, ++j, ++j; // goes out of left side
                             if (j<0)       ++j;           // goes out of bottom
            }
            // change directions
            direction = (direction == SKY) ? GROUND : SKY; // change direction
        }
    }
};