// Link: https://leetcode.com/problems/shortest-word-distance-ii/

class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        this->wordsDict = wordsDict;
        preprocessPositions();
    }

    void preprocessPositions() {
         for (auto i=0; i<wordsDict.size(); i++) {
            Pos[wordsDict[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int dist = INT_MAX;
        for (auto i:Pos[word1])
            for (auto j:Pos[word2])
                dist = min(dist, abs(j-i));
        return dist;
    }
private:
    vector<string> wordsDict;
    unordered_map<string, vector<int>> Pos;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */