// Link: https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        auto index = haystack.find(needle);
        if (index == string::npos) return -1;
        else return index;
    }
};