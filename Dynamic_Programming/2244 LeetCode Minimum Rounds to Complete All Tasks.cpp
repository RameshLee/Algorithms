// Link: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

class Solution {
private: int memo[10000000] = {0};
public:
    int helper(int num){
        if (num == 0) return 0;
        if (num < 0) return 999999;
        if (memo[num]) return memo[num];

        return memo[num] = min(1 + helper(num-3), 1 + helper(num-2));
    }

    int minimumRounds(vector<int>& tasks) {

        unordered_map<int,int> Map;
        for (auto ele:tasks) Map[ele]++;

        vector<int> rep;
        for (auto it=Map.begin(); it!=Map.end(); it++) rep.push_back(it->second);

        int rounds = 0;
        for (int i=0; i<rep.size(); i++){

            int ans = helper(rep[i]);
            if (ans > 999999) return -1;
            rounds += ans;
        }
        return rounds;
    }
};