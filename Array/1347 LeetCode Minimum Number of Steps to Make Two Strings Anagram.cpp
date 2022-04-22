// Link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int,int> Map; int result=0;

        for (auto c:s) Map[c]++; // count the frequencies on s

        for (auto c:t) // adjust frequencies based on t
            if (Map.find(c) != Map.end())
                if (--Map[c] == 0) Map.erase(c);

        for (auto it=Map.begin(); it!=Map.end(); it++) // count total letters need to be changed
            result += it->second;

        return result;
    }
};