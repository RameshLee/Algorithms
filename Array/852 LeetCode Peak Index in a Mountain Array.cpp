// Link: https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l=0, r=A.size()-1;
        while (l<r){
            int i = l + rand()%(r-l+1);
            if (A[i] < A[i+1]) l = i + 1;
            else r = i;
        }
        return l;
    }
};