// Link: https://leetcode.com/contest/weekly-contest-287/problems/maximum-candies-allocated-to-k-children/

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {

        // corner-case: less candies than the candidates
        long long total = 0;
        for (auto& it:candies) total += it;
        if (total < k) return 0;

        sort(candies.rbegin(), candies.rend());

        for (auto& it:candies) printf("%d ", it);

        auto Elem = candies[0];
        for (auto i=Elem; i>=1; i--){

            printf("Evaluating divisor: %d\n", i);

            long long count = 0;
            for (auto j=0; j<candies.size(); j++){
                auto divisor = candies[j] / i;
                count += divisor;

                if (divisor < 0) break;
                if (count >= k) {
                    printf("count reaches for i=%d\n", i);
                    return i;
                }
            }

        }
        return 0;
    }
};