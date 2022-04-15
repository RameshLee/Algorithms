// Link: https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // find the targetRow
        int row = 0;
        for (int i=0; i<matrix.size(); i++)
            if (matrix[i][0] > target) break;
            else row = i;

        // binary search on the columns
        int l=0, r=matrix[row].size()-1;
        while (l<=r){
            int i = l + rand()%(r-l+1);
            if (matrix[row][i] == target) return true;
            if (matrix[row][i] < target) l=i+1;
            else r=i-1;
        }
        return false;
    }
};