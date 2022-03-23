// Link: https://leetcode.com/problems/to-lower-case/

class Solution {
public:
    string toLowerCase(string s) {
        for (auto& it:s) it = (it>=65 && it<=90)? it+32 : it;
        return s;
    }
};