// Link: https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/

// Binary search: T=O(N*logM), S=O(1) (100% faster)
// N=candies.size(), M=maxElem

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {

        // corner-case: less candies than the children
        long long total = 0;
        int maxElem = 0;
        for (auto& it:candies) {
            total += it;
            maxElem = max(maxElem, it);
        }
        if (total < k) return 0;
        if (total == k) return 1;

        // perform binary search
        int l=1, h=maxElem, maxCandies = 0;
        while (l<=h){

            // select chunk from range(l,h)
            int chunk = l + (rand()%(h-l+1));

            // investigate the chunk distribution
            long long children = 0;
            for (auto j=0; j<candies.size(); j++){
                children += candies[j] / chunk;
                if (children >= k) {
                    maxCandies = max(maxCandies, chunk); break;
                }
            }

            // update two pointers
            if (children < k) h = chunk-1;
            else l = chunk+1;
        }
        return maxCandies;
    }
};