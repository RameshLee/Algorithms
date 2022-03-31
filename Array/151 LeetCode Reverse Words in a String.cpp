// Link: https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    void helper(int start, int end, vector<string>& vec){
        if (start>end) return;
        helper(start+1, end-1, vec);
        std::swap(vec[start],vec[end]);
    }

    string reverseWords(string s) {

        // convert into vector<strings>
        stringstream str(s);
        vector<string> vec; string word;
        while (str >> word) vec.push_back(word);

        // swap strings in vector<strings>
        helper(0, vec.size()-1, vec);

        // read the swapped strings
        string A = vec[0];
        for (int i=1; i<vec.size(); i++) A += " " + vec[i];
        return A;
    }
};