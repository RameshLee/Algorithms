// Link: https://leetcode.com/problems/word-break/

// Recursion with memoization (top-down dynamic programming)

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto str:wordDict) Map[str] = 1;
        return helper(s);
    }
private:
    unordered_map<string,int> Map;
    unordered_map<string,bool> Memo;

    bool helper(string word){
        if (Map.find(word) != Map.end()) return true;
        if (Memo.find(word) != Memo.end()) return Memo[word];

        for (int i=0; i<word.size(); i++){
            string current = word.substr(0,i+1);
            string remaining = word.substr(i+1);

            if (Map.find(current) != Map.end()){ // if found, recursively explore remaining part

                bool isFound = helper(remaining);
                if (isFound){ // entire word exists
                    Memo[remaining] = true;
                    return true;
                }
            }
        }

        return Memo[word] = false;
    }
};

