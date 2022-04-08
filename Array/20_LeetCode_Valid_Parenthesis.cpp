// Link: https://leetcode.com/problems/valid-parentheses/

// Solution based on hash map and stack

class Solution {
private:
    unordered_map<char,int> Map = { {'(', 2}, {')', -2},  {'{', 3}, {'}', -3}, {'[', 4}, {']', -4} };
public:
    bool isValid(string s) {

        // special case: return if there are odd number of brackets
        if (s.size()%2 != 0) return false;

        vector<int> vec;
        int sum = 0;
        for (auto& it:s) {
            sum += Map[it];

            if (Map[it] < 0) {
                if (vec.empty()) return false;
                if (Map[it] == (-1)*vec.back()) vec.pop_back(); // remove if it is a valid pair.
            }
            else vec.push_back(Map[it]);
        }

        //corner-cases
        if (!vec.empty()) return false;
        if (abs(sum) != 0) return false;

        return true;

    }
};