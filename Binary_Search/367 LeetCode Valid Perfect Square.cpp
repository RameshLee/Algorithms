// Link: https://leetcode.com/problems/valid-perfect-square/

// Binary search: T = O(log (num/2)), S=O(1)
// Algo: sqrt of any number is always less than its half.

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num==1) return true;

        long long l=0, r=num/2;
        while (l<=r){
            long long i = l + rand()%(r-l+1);

            if (i*i == num) return true;
            else if (i*i > num) r = i-1;
            else l = i + 1;
        }
        return false;
    }
};