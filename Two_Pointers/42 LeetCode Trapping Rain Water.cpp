// Link: https://leetcode.com/problems/trapping-rain-water/

// Algorithm: T=O(n), S=O(1)
// 1) find global max wall
// 2) water at any index is the difference between the minimum water that can be stored there and the wall height at that index.
// 2) units[i] = min(waterStored[i], height[i])
// w.k.t waterStored[i] i.e. water that can be stored at index i is the minimum of height between left/right wall and global wall.
// 3) scan from both sides to max wall index.

class Solution {
public:
    int trap(vector<int>& height) {

        // find global maxWall
        int Max = 0, index = 0, units=0;
        for (int i=0; i<height.size(); i++) {
            if (Max < height[i])
                Max = height[i], index=i;
        }

        // scan from leftmost index to maxWall
        int leftWall = 0;
        for (int i=0; i<index; i++){
            leftWall = max(leftWall, height[i]); // update left wall
            units += leftWall - height[i];
        }

        // scan from rightmost index to maxWall
        int rightWall = 0;
        for (int i=height.size()-1; i>=index; i--){
            rightWall = max(rightWall, height[i]); // update right wall
            units += rightWall - height[i];
        }

        return units;
    }
};