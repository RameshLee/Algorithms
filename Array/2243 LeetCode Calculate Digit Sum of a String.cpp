// Link: https://leetcode.com/problems/calculate-digit-sum-of-a-string/

class Solution {
public:
    string digitSum(string s, int k) {

        int chunk = k;
        while (1){
            if (s.size() <= chunk)  break;

            string number;
            for (int i=0; i<s.size(); i+=chunk){
                int sum = 0;
                for (int j=i; j<i+chunk; j++)
                    if (j<s.size())
                        sum += (int)s[j]-48;

                number += to_string(sum);
            }
            s = number; k--;
        }
        return s;
    }
};