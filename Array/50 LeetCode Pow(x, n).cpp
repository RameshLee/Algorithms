// Link: https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPowUtility(double x, long long n){
        if (n<0)        return myPowUtility(1/x, -1*n);
        if (n==0)       return (double)(1);
        if (n==1)       return x;
        if (n%2==0)     return myPowUtility(x*x, n/2);
        else            return myPowUtility(x*x, n/2)*x;
    }

    double myPow(double x, int n) {
        return myPowUtility(x,n);
    }
};


