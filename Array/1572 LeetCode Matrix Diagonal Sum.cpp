// Link: https://leetcode.com/problems/matrix-diagonal-sum/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {

        int i=0, j=0, k=mat.size()-1, sum = 0, num = 0;

        // find intersecting mid element
        if (mat.size()%2!=0) num = mat[mat.size()/2][mat.size()/2];

        // traverse along the two diagonals
        while(k>=0){
            sum += mat[i][j] + mat[k][j]; i++; j++; k--;
        }

        return sum-num;
    }
};