// Link: https://leetcode.com/problems/decode-string/

class Solution {
private: enum Brackets{OPEN='[', CLOSED=']'};
public:
    void collapseStack(vector<char>& vec, vector<string>& words, vector<int>& rep){

        // extract string word
        string substr;
        while (!vec.empty() && vec.back() != OPEN){
            auto c = vec.back(); vec.pop_back();
            substr.push_back(c);
        }
        reverse(substr.begin(), substr.end());
        vec.pop_back(); // remove openBracket

        // extract rep count
        string number;
        while (!vec.empty() && std::isdigit(vec.back())){
            auto c = vec.back(); vec.pop_back();
            number.push_back(c);
        }
        reverse(number.begin(), number.end());
        int val = stoi(number);

        // expand the word & push into the stack
        string expand;
        for (int i=0; i<val; i++)
            expand += substr;
        for (auto c:expand) vec.push_back(c);
    }

    string decodeString(string s) {

        vector<char> vec;
        vector<string> words; vector<int> rep;

        // whenever closedBracket is encounter, expand the words.
        for (auto c:s){
            if (c == CLOSED) collapseStack(vec, words, rep);
            else vec.push_back(c);
        }

        string ret;
        for (auto c:vec) ret.push_back(c);
        return ret;
    }
};