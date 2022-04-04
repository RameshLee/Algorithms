// Link: https://leetcode.com/problems/sqrtx/solution/

class Solution {
public:
    int mySqrt(int x) {
        long long l=1, r=x;
        while (l<=r){
            long long i = l+rand()%(r-l+1);
            if (i*i > x) r=i-1;
            else l=i+1;
        }
        return r;
    }
};