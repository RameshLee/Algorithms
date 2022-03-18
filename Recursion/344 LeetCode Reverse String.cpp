// Link: https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void helper(int start, int end, vector<char>& s){

        if (start>=end) return;

        helper(start+1, end-1, s);
        int tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
    }

    void reverseString(vector<char>& s) {
        helper(0,s.size()-1,s);
    }
};