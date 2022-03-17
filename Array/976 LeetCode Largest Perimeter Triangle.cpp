// Link: https://leetcode.com/problems/largest-perimeter-triangle/

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
		sort(A.begin(), A.end());    //Sort the vector
        for(int i = A.size() - 1; i > 1; i--)    //Run a loop from end to begin
            if(A[i] < A[i - 1]+A[i-2])     //If triangle sum property satisfied
                return A[i]+A[i - 1]+A[i-2];    //Answer found, bcoz array is already sorted
        return 0;    //return 0 if answer not found yet
    }
};