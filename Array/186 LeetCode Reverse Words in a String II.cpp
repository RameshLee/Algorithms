// Link: https://leetcode.com/problems/reverse-words-in-a-string-ii/

// Two-pointers approach: one-pass: T=O(N)
class Solution {
public:
    void reverseWords(vector<char>& s) {
        std::reverse(s.begin(), s.end());
        int l=0, r=0, n=s.size();
        for (r=0; r<n; r++) {
            if (std::isspace(s[r])) {
                std::reverse(s.begin()+l, s.end()-(n-r));
                l = r+1;
            }
        }
        std::reverse(s.begin()+l, s.end()-(n-r));
    }
};