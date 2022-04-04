// Link: https://leetcode.com/problems/guess-number-higher-or-lower/

class Solution {
public:
    int guessNumber(int n) {
        long long l=0, r=n;
        while (l<=r){
            int i = l + rand()%(r-l+1);
            if (guess(i) == 0) return i;
            if (guess(i) == -1) r=i-1;
            else l=i+1;
        }
        return -1;
    }
};