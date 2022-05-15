// Link: https://leetcode.com/problems/daily-temperatures/

// Approach: Monotonic stack
// Idea: if temperatures of consecutive days are decreasing, then they share a common answer.

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int,int>> Stack; Stack.push(make_pair(0,temperatures[0]));
        for (auto i=0; i<temperatures.size(); i++) {
            while (!Stack.empty() && temperatures[i] > Stack.top().second) {
                result[Stack.top().first] = i - Stack.top().first;
                Stack.pop();
            }
            Stack.push(make_pair(i, temperatures[i]));
        }
        return result;
    }
};