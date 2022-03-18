// Link: https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    int memo[50][50];

    int helper(int i, int j, int size){

        if (j==0 || j==size) return 1; //base-case
        if (memo[i][j] > 0) return memo[i][j]; //memoization

        memo[i][j] = helper(i-1,j-1, size-1)+helper(i-1,j, size-1); //recurrence
        return memo[i][j];
    }

    vector<int> getRow(int rowIndex) {

        vector<int> vec(rowIndex+1);
        for (int j=0; j<=rowIndex; j++)
            vec[j] = helper(rowIndex,j, rowIndex);

        return vec;
    }
};