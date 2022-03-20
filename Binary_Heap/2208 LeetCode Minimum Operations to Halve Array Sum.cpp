// Link: https://leetcode.com/contest/biweekly-contest-74/problems/minimum-operations-to-halve-array-sum/

class Solution {
public:
    int halveArray(vector<int>& vec) {

        priority_queue<double> nums;
        for(auto &it:vec) nums.push(it);


        // compute target
        double target = 0;
        for (auto& it:vec) target += it;
        target = target/2;

        // keep dividiing by max elements: if number goes less than target, break
        int attempt = 0;
        double currSum = target*2;
        while (currSum > target){
             double val = nums.top();
             currSum -= (val/2);
             attempt++;
             nums.pop();
             nums.push(val/2);
        }
        return attempt;
    }
};