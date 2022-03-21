// Link: https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target){

        int i=mat.size()-1,j=0;

        while(i>=0 && j<mat[0].size()){
            if (mat[i][j] == target) return true;
            if (mat[i][j] > target) i--; //move up
            else j++; //move right
        }
        return false;
    }
};