// Link: https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // sort based on starting time

        vector<vector<int>> result;
        for (auto window : intervals) {
            if (result.empty() || result.back()[1] < window[0]) { // non-overlapping intervals
                result.push_back(window);
            }
            else { // overlapping intervals
                result.back()[1] = max(result.back()[1], window[1]);
            }
        }
        return result;
    }
};