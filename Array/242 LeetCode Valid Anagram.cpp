// Link: https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) return false;

        unordered_map<int,int> Map;
        unordered_map<int,int> Map2;

        for (auto& it:s) Map[it]++;
        for (auto& it:t) Map2[it]++;
        for (auto& it:s) if (Map2[it] != Map[it]) return false;

        return true;

    }
};