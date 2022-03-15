// Link: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

class Solution {
public:
    double average(vector<int>& salary) {

        double Minimum = INT_MAX;
        double Maximum = 0;

        double sum = 0;
        for (auto& it:salary){
            Minimum = min(Minimum,(double)it);
            Maximum = max(Maximum,(double)it);
            sum += it;
        }

        return (sum-Minimum-Maximum)/(salary.size()-2);

    }
};