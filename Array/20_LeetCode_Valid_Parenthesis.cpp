// Link: https://leetcode.com/problems/valid-parentheses/

// Solution based on hash map and stack

class Solution {
public:
    unordered_map<char,int> Map = { {'(', 2}, {')', -2},  {'{', 3}, {'}', -3}, {'[', 4}, {']', -4} };

    bool isValid(string s) {

        // special case: return if there are odd number of brackets
        if (s.size()%2 != 0) return false;

        int Aggregator = 0;
        vector<int> vec;
        for (auto& it:s) {
            Aggregator += Map[it];

            if (Map[it] < 0) {
                if (!vec.empty()){
                    if (Map[it] == (-1)*vec.back()) {
                       vec.pop_back();
                    }
                    else {return false;}
                }
            }
            else vec.push_back(Map[it]);
        }

        //corner-cases
        if (!vec.empty()) return false;
        else if (abs(Aggregator) > 0) return false;

        return true;

    }
};