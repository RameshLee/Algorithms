// Link: https://leetcode.com/problems/set-matrix-zeroes/

// 1) linear time, linear space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        row = matrix.size(), col = matrix[0].size();
        for (auto i=0; i<row; i++)
            for (auto j=0; j<col; j++)
                if (matrix[i][j] == 0)
                    sweep(matrix, i, j);

        for (auto it=Set.begin(); it!=Set.end(); it++) {
            vector<int> vec = *it;
            matrix[vec[0]][vec[1]] = 0;
        }
    }
private:
    int row, col; set<vector<int>> Set;

    bool isSafe(int i, int j) {
        return (i>=0 && j>=0 && i<row && j<col) ? true : false;
    }

    void sweep(vector<vector<int>>& matrix, int x, int y) {
        int i,j;
        i=x, j=y; while (isSafe(i,j)) Set.insert(vector<int>({i,j})), i--;
        i=x, j=y; while (isSafe(i,j)) Set.insert(vector<int>({i,j})), i++;
        i=x, j=y; while (isSafe(i,j)) Set.insert(vector<int>({i,j})), j--;
        i=x, j=y; while (isSafe(i,j)) Set.insert(vector<int>({i,j})), j++;
    }
};

// 2) linear time, constant space
// set every flag at first row and col if that cell is 0.