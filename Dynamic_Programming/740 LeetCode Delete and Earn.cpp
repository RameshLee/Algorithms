// Link: https://leetcode.com/problems/delete-and-earn/

// Dynamic programming (reason: 1) find max, 2) current decision influences the future.)

// state variables: index i at which the number can be deleted currently
// recurrence relation: dp(i) = max( dp(i-1), dp(i-2) + values[i] );
// base-case: dp(0)=values[0], dp(1)=max(values[0],values[1]);


// 1) bottom-up dynamic programming (tabulation)

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        // initialization
        const int Limit = 100000; int SearchLimit = 0;
        vector<int> dp(Limit, 0); vector<int> values(Limit, 0);

        // count the frequencies, and aggregate the points
        unordered_map<int,int> Freq; for (auto i:nums) Freq[i]++;
        for (auto it=Freq.begin(); it!=Freq.end(); it++){
            values[it->first] = it->first * it->second;
            SearchLimit = max(SearchLimit, it->first);
        }

        // bottom-up DP
        dp[0] = values[0], dp[1] = max(values[0],values[1]);
        for (int i=2; i<=SearchLimit; i++){
            dp[i] = max( dp[i-1], dp[i-2] + values[i] );
        }
        return dp[SearchLimit];
    }
};


// 2) top-down dynamic programming

const int Limit = 100000;

class Solution {
public:
    vector<int> dp, values; unordered_map<int,int> Memo;

    int helper(int i){
        // base-case:
        if (i == 0) return values[0];
        if (i == 1) return max(values[0],values[1]);
        if (Memo.find(i) != Memo.end()) return Memo[i];

        // recurrence-relation
        return Memo[i] = max( helper(i-1), helper(i-2) + values[i] );
    }

    int deleteAndEarn(vector<int>& nums) {

        // initialization:
        int SearchLimit = 0;
        dp.resize(Limit,0); values.resize(Limit,0);

        // count the frequencies, and aggregate the points
        unordered_map<int,int> Freq; for (auto i:nums) Freq[i]++;
        for (auto it=Freq.begin(); it!=Freq.end(); it++){
            values[it->first] = it->first * it->second;
            SearchLimit = max(SearchLimit, it->first);
        }

        // top-down DP
        return helper(SearchLimit);
    }
};