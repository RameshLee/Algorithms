// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int count = 0;
        unordered_set<char> Set;

        for (int i=0; i<s.size(); i++){
            Set.clear(); Set.insert(s[i]);
            for (int j=i+1; j<s.size(); j++){
                if (Set.find(s[j]) != Set.end()) break;
                else Set.insert(s[j]);
            }
            count = max(count, (int)Set.size());
        }
        return count;
    }
};