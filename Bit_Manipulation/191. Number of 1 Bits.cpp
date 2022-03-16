// Link: https://leetcode.com/problems/number-of-1-bits/

// n&1 gives LSB; n>>1 performs right shift.

class Solution {
public:
int hammingWeight(uint32_t n) {
        int count=0;
        while(n){
            if(n&1 ==1) count++;
            n=n>>1;
        }
        return count;
    }
};