// Link: https://leetcode.com/problems/calculate-amount-paid-in-taxes/

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double result = 0;
        auto prev = 0;
        for (auto e:brackets) {
            auto dollars = min(e[0] - prev, income);
            result += (double)(dollars * e[1])/100;
            income -= dollars, prev = e[0];
        }
        return result;
    }
};