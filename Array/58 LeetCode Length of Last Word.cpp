// Link: https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0; int i = s.size()-1;
        while (i>=0 && std::isspace(s[i])) i--; // bypass whitespaces from the end
        while (i>=0 && std::isalpha(s[i])) i--, count++; // read last word from the end
        return count;
    }
};