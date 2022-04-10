// Link: https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {

        if (s.size() == 0 || t.size() == 0) return "";

        unordered_map<char,int> Map;
        for (auto& c:t) Map[c]++;

        // left is the start index of the min-length substring ever found
        int min = INT_MAX, start = 0, left = 0, end = 0, required = t.size();
        while (end <= s.size() && start < s.size()) {
            if(required) {
                if (end == s.size()) break;
                Map[s[end]]--;
                if (Map[s[end]] >= 0) required--;
                end++;
            }
            else {
                if (end - start < min) {
                    min = end-start;
                    left = start;
                }
                Map[s[start]]++;
                if (Map[s[start]] > 0) required++;
                start++;
            }
        }
        return min == INT_MAX? "" : s.substr(left, min);
    }
};