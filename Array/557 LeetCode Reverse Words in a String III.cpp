// Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s)
    {
        int start = 0;
        for (int end=0; end<s.size(); end++)
        {
            if (isspace(s[end])) //detects space
            {
                reverse(s.begin()+start, s.begin()+end);
                start = end+1;
            }
            else if (end == s.size()-1)
                reverse(s.begin()+start, s.end());
        }
        return s;
    }
};