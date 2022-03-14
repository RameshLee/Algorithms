// Link: https://leetcode.com/problems/first-unique-character-in-a-string/
//Time complexity: O(n)

class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char,int> Map;

        for (auto& it:s)
            Map[it]++;

        for (int i=0; i<s.size(); i++)
            if (Map[s[i]] == 1)
                return i;

        return -1;
    }
};