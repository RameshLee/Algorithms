// Link: https://leetcode.com/problems/power-of-three/

class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n%3 == 0 && n>1) n = n/3;
        return (n==1) ? true : false;
    }
};