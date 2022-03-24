// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    int index=0; int medianIndex;

    void merge(int i, int j, vector<int>& A, vector<int>& B, vector<int>& arr){

        // base cases
        if (index > medianIndex) return; // stop merging once you reach the median index
        if (i>=A.size() && j>=B.size()) return;

        if (i>=A.size())      { arr[index++] = (B[j++]); merge(i,j,A,B,arr); }
        else if (j>=B.size()) { arr[index++] = (A[i++]); merge(i,j,A,B,arr); }
        else if (A[i] < B[j]) { arr[index++] = (A[i++]); merge(i,j,A,B,arr); }
        else                  { arr[index++] = (B[j++]); merge(i,j,A,B,arr); }
    }

    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {

        int n = A.size() + B.size();
        vector<int> arr(n);
        medianIndex = (n%2==0) ? n/2 : (n+1)/2;

        merge(0, 0, A, B, arr);

        if (n%2 == 0) return ((double)arr[medianIndex-1] + (double)arr[medianIndex])/2;
        else return (double)arr[medianIndex-1];
    }
};