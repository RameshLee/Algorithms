// Link: https://leetcode.com/problems/word-break/

// 1) Recursion with memoization

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto str:wordDict) {
            dictSet.insert(str);
        }
        return helper(s);
    }
private:
    unordered_set<string> dictSet;
    unordered_map<string,bool> Memo;

    bool helper(string word){
        if (dictSet.count(word)) return true;
        if (Memo.find(word) != Memo.end()) return Memo[word];

        for (int i=0; i<word.size(); i++){
            string left = word.substr(0,i+1);
            string right = word.substr(i+1);

            if (dictSet.count(left)){ // if found, recursively explore remaining part
                bool isFound = helper(right);
                if (isFound) return Memo[right] = true; // entire word exists
            }
        }
        return Memo[word] = false;
    }
};



