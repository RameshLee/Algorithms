// Link: https://leetcode.com/problems/longest-palindromic-substring/

// Top-down dynamic programming
// optimal sub-problem: palindrome of a big string can be checked by referring the previously computed results of their substrings.

class Solution {
private: int table[1000][1000] = {0}; //dp lookup table
public:
    bool check(string& s, int l, int r){
        while (l<=r){
            if (table[l][r]) return true; // memoization
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }

    string longestPalindrome(string s) {

        // edge-case: all chars are same in string.
        int foundVariation = 0;
        for (int i=1; i<s.size(); i++)
           if (s[i] != s[i-1]) {
               foundVariation = 1;
               break;
           }
        if (!foundVariation) return s;

        // top-down dynamic-programing: check palindrome for all strings
        int pos=0,length=1;
        for (int i=0; i<s.size(); i++){
            for (int j=i; j<s.size(); j++){
                if (check(s,i,j)) {
                    if (length < (j-i)+1)
                        length = (j-i)+1, pos = i;
                    table[i][j] = 1;
                }
            }
        }
        return s.substr(pos,length);;
    }
};