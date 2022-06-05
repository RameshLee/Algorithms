// Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        stack<char> Stack;
        for (auto c:s) {
            if (c == CLOSED) {
                if (!Stack.empty() && Stack.top() == OPEN) Stack.pop();
                else count++;
            } else {
                Stack.push(c);
            }
        }
        count += Stack.size();
        return count;
    }
private:
    enum Brackets{OPEN='(', CLOSED=')'};
};