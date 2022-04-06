// Link: https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/

// Binary search: T=O(N*logM), S=O(1) (100% faster)
// N=candies.size(), M=maxElem

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {

        int l=1, h=10000000, result = 0;
        while (l<=h){

            int size = l + (rand()%(h-l+1)); // set pivot
            long chunks = 0; for (auto& it:candies) chunks += it/size; // find total chunks
            if (chunks >= k) l = size+1, result = max(result, size);  // update pointers & result
            else h = size-1;
        }
        return result;
    }
};