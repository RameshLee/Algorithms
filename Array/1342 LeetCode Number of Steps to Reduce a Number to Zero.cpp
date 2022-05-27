// Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

class Solution {
public:
    int numberOfSteps(int num) {
        int steps;
        for (steps=0; num != 0; steps++) {
            num = (num%2==0) ? num/2 : num-1;
        }
        return steps;
    }
};