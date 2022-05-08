// Link: https://leetcode.com/problems/pascals-triangle/

// 1) Recursion with memoization (top-down DP): T=O(N), S=O(N), where N-> total cells
// (Preferred: 100% Faster, 99% Memory efficient)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        // tailor the vector
        vec.resize(numRows, vector<int>());
        for (int i=0; i<numRows; i++) vec[i].resize(i+1,0);

        // launch recursion
        for (int i=numRows-1; i>=0; i--) {
            for (int j=0; j<i+1; j++){
               vec[i][j] = helper(i,j);
            }
        }
        return vec;
    }
private:
    vector<vector<int>> vec;
    int helper(int i, int j){
        // base-case
        if (i<0 || j<0) return 0;
        if (j==0 || j==i) return 1;
        if (vec[i][j]) return vec[i][j];

        // recursion
        return vec[i][j] = helper(i-1, j-1) + helper(i-1, j);
    }
};

// 2) Iterative solution: T=O(N), S=O(N), where N -> total cells

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec(numRows, vector<int>());
        for (int i=0; i<numRows; i++){
            for (int j=0; j<i+1; j++){
                if (j==0 || j==i) {
                    vec[i].push_back(1);
                }
                else{
                    vec[i].push_back(vec[i-1][j-1] + vec[i-1][j]);
                }
            }
        }
        return vec;
    }
};