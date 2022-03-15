// Link: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

class Solution {
public:
    int countOdds(int low, int high) {

        int output = 0;

        if (low%2 != 0) {low += 1; output += 1;}
        if (high%2 != 0) {high -= 1; output += 1;}

        return output + (high-low)/2;

    }
};