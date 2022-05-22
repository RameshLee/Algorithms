// Link: https://leetcode.com/problems/buildings-with-an-ocean-view/

// Approach: go from right to left while keeping track of the tallest building so far.
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> result; int n = heights.size();
        int tallest = heights[n-1];
        result.push_back(n-1);
        for (auto i=n-2; i>=0; i--) {
            if (tallest < heights[i]) {
                tallest = heights[i];
                result.push_back(i);
            }
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};