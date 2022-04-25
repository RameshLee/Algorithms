// Link: https://leetcode.com/problems/longest-palindromic-subsequence/
// Top-down dynamic programming

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        return helper(0,s.size()-1, s);
    }
private:
    int Memo[1001][1001] = {0};

    int helper(int l, int r, string &s){
        // base-case
        if (l==r) return 1;
        if (l>r)  return 0;
        if (Memo[l][r]) return Memo[l][r];

        // recursion
        if (s[l]==s[r]){
            return Memo[l][r] = 2 + helper(l+1, r-1, s);
        }
        else {
            return Memo[l][r] = max(helper(l+1,r,s),helper(l,r-1,s));
        }
    }
};