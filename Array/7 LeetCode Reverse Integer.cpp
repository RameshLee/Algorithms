// Link: https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x); int coeff = 1;
        if (x < 0) coeff = -1, s.erase(s.begin());


        std::reverse(s.begin(), s.end());
        long long ans = stoll(s);

        if (INT_MIN <= ans && ans <= INT_MAX) {
            return coeff * (int)ans;
        }
        return 0;
    }
};