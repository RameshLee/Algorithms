// Link: https://leetcode.com/problems/valid-palindrome-ii/

class Solution {
public:
    bool validPalindrome(string s) {
        this->s = s;
        return isPalindrome(0, s.size()-1, 0);
    }
private:
    string s; int count = 0;

    bool isPalindrome(int l, int r, int count) {
        if (count > 1) return false;
        if (l>r) return true;
        if (s[l] == s[r]) return isPalindrome(l+1,r-1, count);
        return (isPalindrome(l+1,r,count+1) || isPalindrome(l,r-1,count+1));
    }
};