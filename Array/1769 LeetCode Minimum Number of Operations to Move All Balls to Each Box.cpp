// Link: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n);
        for (auto targetBox=0; targetBox<n; targetBox++) { // from all boxes to targetBox
            auto effort = 0;
            for (auto i=0; i<n; i++)
                if (i != targetBox)
                    effort += (boxes[i] - '0') * abs(i-targetBox);
            result[targetBox] = effort;
        }
        return result;
    }
};