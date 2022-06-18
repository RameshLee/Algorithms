// Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> A, B; int p = 0;
        for (auto e : nums) {
            if (e < pivot) A.push_back(e);
            if (e > pivot) B.push_back(e);
            if (e == pivot) p++;
        }
        vector<int> C;
        C.insert(C.end(), A.begin(), A.end());
        while (p-- > 0) C.push_back(pivot);
        C.insert(C.end(), B.begin(), B.end());
        return C;
    }
};