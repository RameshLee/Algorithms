// Link: https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool helper(string &str, int start, int end){
        if (start>=end) return true;
        if (str[start] != str[end]) return false;

        return helper(str, start+1, end-1);
    }

    bool isPalindrome(int x) {
        string str = to_string(x);
        return helper(str, 0, str.size()-1);
    }
};