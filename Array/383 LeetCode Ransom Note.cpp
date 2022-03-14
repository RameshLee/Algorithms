// Link: https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char,int> Map;
        unordered_map<char,int> Map2;

        for (auto& it:magazine) Map2[it]++;
        for (auto& it:ransomNote) if (Map2[it] < ++Map[it]) return false;

        return true;

    }
};