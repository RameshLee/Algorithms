// Link: https://leetcode.com/problems/palindromic-substrings/

// 1) top-down dynamic programming (recursion + memoization)

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (auto i=0; i<s.size(); i++)
            for (auto j=i; j<s.size(); j++)
                if (isPalindrome(s,i,j))
                    count++;
        return count;
    }
private:
    bool Memo[1001][1001] = {false}; // memoization table

    bool isPalindrome(string& s, int l, int r){
        if (l>=r) return true;
        return Memo[l][r] = (s[l]==s[r]) ? isPalindrome(s,l+1,r-1) : false;
    }
};