// Link: https://leetcode.com/problems/jump-game/

// Dynamic Programming:
// 1) Traverse from right to left.
// 2) Mark each node as "Good" or "Bad" if we can reach the final index from that node.
// 3) At the end, if the node 0 is Good, then return true;

class Solution {
public:
    bool canJump(vector<int>& nums) {

        vector<bool> canReach(nums.size(), false);

        int lastIndex = nums.size()-1;
        canReach[lastIndex] = true;

        for (int i=lastIndex-1; i>=0; i--){
            for (int steps=1; steps<=nums[i]; steps++){
                if (i+steps < nums.size())
                    if (canReach[i+steps] == true){
                        canReach[i] = true; break;
                    }
            }
        }
        return canReach[0];
    }
};