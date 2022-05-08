// Link: https://leetcode.com/problems/jump-game/

// Dynamic Programming:
// 1) Traverse from right to left.
// 2) Mark each node as "Good" or "Bad" if we can reach the final index from that node.
// 3) At the end, if the node 0 is Good, then return true;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> canReach(n, false);

        canReach[n-1] = true;
        for (int i=n-2; i>=0; i--) {
            for (int steps=0; steps<=nums[i]; steps++) {
                if (i+steps < nums.size() && canReach[i+steps]) {
                    canReach[i] = true;
                    break;
                }
            }
        }
        return canReach[0];
    }
};
