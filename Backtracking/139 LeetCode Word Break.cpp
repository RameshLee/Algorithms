// Link: https://leetcode.com/problems/word-break/

class Solution {
public:
    unordered_map<string,int> Map;
    bool Decision = false;

    void backtrack(int i, string &s){

        // base-case
         if (Decision) return;

        if (i >= s.size()){
            //printf("True\n");
            Decision = true;
            return;
        }

        // for all candidates
        string str;
        for (int j=i; j<s.size(); j++){
            str.push_back(s[j]); // make move
            if (Map[str] == 1){
                backtrack(j+1, s); // backtrack
            }
            // undo move : NA here
             if (Decision) return;
        }


    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto& it:wordDict) Map[it] = 1;

        backtrack(0,s);

        return Decision;
    }
};