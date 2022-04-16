// Link: https://leetcode.com/problems/target-sum/

class Solution {
private: int sum = 0, count = 0;
public:
    void backtrack(int i, vector<int>& vec, int target){
        // base-case
        if (i>=vec.size()){
            if (sum == target) count++;
            return;
        }

        // for all candidates
        sum += vec[i]; // make move
        backtrack(i+1, vec, target); // backtrack
        sum -= vec[i]; // undo move

        sum -= vec[i]; // make move
        backtrack(i+1, vec, target); // backtrack
        sum += vec[i]; // undo move
    }

    int findTargetSumWays(vector<int>& vec, int target) {
        backtrack(0, vec, target);
        return count;
    }
};