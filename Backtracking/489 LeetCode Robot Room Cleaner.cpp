// Link: https://leetcode.com/problems/robot-room-cleaner/submissions/

class Solution {
public:
    int x[4] = {0,1,0,-1};
    int y[4] = {1,0,-1,0};
    bool visited[300][300] = {false};

    void undoMove(Robot& robot){
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
    }

    void backtrack(Robot& robot, int i, int j, int dir) {

        if (visited[i][j]) return;
        visited[i][j] = true;

        robot.clean();
        for(int l=0; l<4; l++) { // explore candidates
            int k = (dir+l) % 4;
            //int k = dir+l; if (dir+l >= 4) k -= 4; // ensure proper directions
            if(robot.move()){ // make move
                backtrack(robot, i+x[k], j+y[k], k); // backtrack
                undoMove(robot); // undo move
            }
            robot.turnRight();
        }
    }

    void cleanRoom(Robot& robot) {
        backtrack(robot, 150, 150, 0);
    }
};