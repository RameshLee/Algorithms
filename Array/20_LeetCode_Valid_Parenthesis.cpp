// Link: https://leetcode.com/problems/valid-parentheses/

// Solution based on hash map and stack

class Solution {
private:
    unordered_map<char,int> Map = { {'(', 2}, {')', -2},  {'{', 3}, {'}', -3}, {'[', 4}, {']', -4} };
public:
    bool isValid(string s) {

        // corner case: return if there are odd number of brackets
        if (s.size()%2 != 0) return false;

        stack<int> Stack; int sum = 0;
        for (auto c:s) {
            sum += Map[c];
            if (Map[c] < 0) {
                if (Stack.empty()) return false;
                if (Map[c] == (-1)*Stack.top()) Stack.pop(); // remove valid pair of brackets
            }
            else Stack.push(Map[c]);
        }
        return (Stack.empty() && sum == 0) ? true : false;
    }
};