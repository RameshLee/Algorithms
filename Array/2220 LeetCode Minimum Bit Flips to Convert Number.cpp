// Link: https://leetcode.com/contest/biweekly-contest-75/problems/minimum-bit-flips-to-convert-number/

class Solution {
public:
    int minBitFlips(int start, int goal) {
        string A = std::bitset<1000>(start).to_string();
        string B = std::bitset<1000>(goal).to_string();

        int count = 0;
        for (int i=0; i<A.size(); i++){
            if (A[i] != B[i])
                count++;
        }

        printf("%s %s\n", A.c_str(), B.c_str());
        return count;
    }
};