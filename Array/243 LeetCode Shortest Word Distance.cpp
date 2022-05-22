// Link: https://leetcode.com/problems/shortest-word-distance/

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> Pos1, Pos2;
        for (auto i=0; i<wordsDict.size(); i++) {
            if (wordsDict[i] == word1) Pos1.push_back(i);
            if (wordsDict[i] == word2) Pos2.push_back(i);
        }

        int dist = INT_MAX;
        for (auto i:Pos1)
            for (auto j:Pos2)
                dist = min(dist, abs(j-i));
        return dist;
    }
};