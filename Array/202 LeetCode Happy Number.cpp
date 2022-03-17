// Link: https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {

        int sum = 0;
        int B = n;

        unordered_map<int,int> Map;

        while (1){
            sum = 0;
            while (B){
                sum += (B%10)*(B%10);
                B=B/10;
            }
            if (Map[sum]>0) return false;
            if (sum == 1) {return true;}
            B = sum;
            Map[sum]++;
        }
        return false;
    }
};