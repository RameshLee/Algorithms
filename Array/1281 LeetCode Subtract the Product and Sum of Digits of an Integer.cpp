// Link: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

class Solution {
public:
    int subtractProductAndSum(int n) {

        int sum=0; int mul=1;
        while (n>0){
            int a = n%10;
            n = n/10;

            sum += a;
            mul *= a;
        }
        return mul-sum;
    }
};