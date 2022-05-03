// Link: https://leetcode.com/problems/n-queens/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        grid.resize(n, vector<int>(n,0));
        backtrack(0);
        return result;
    }
private:
    int n; vector<vector<int>> grid;
    vector<vector<string>> result;

    void backtrack(int i);
    void updateResult();
    void placeQueen(int i, int j);
    void removeQueen(int i, int j);
    bool isValidPos(int i, int j);
    bool isSafe(int i, int j);
};

void Solution::backtrack(int i){
        // base-case
        if (i==n){
            updateResult();
            return;
        }

        // explore candidates
        for (auto j=0; j<n; j++){
            if (isValidPos(i,j)){
                placeQueen(i,j); // make move
                backtrack(i+1); // backtrack
                removeQueen(i,j); // undo move
            }
        }
    }

void Solution::updateResult(){
        vector<string> combo;
        for (auto row:grid){
            string s;
            for (auto i:row){
                s.push_back( (i==1) ? 'Q' : '.' );
            } combo.push_back(s);
        }
        result.push_back(combo);
    }

bool Solution::isSafe(int i, int j){
    return (i>=0 && j>=0 && i<n && j<n) ? true : false;
}

bool Solution::isValidPos(int i, int j){
    return (grid[i][j] == 0) ? true : false;
}

void Solution::placeQueen(int i, int j){

    // mark all attack positions
     int p,q;
     p=i,q=j;   while (isSafe(p,q))     grid[p][q] += 1, p++;
     p=i,q=j;   while (isSafe(p,q))     grid[p][q] += 1, p--;
     p=i,q=j;   while (isSafe(p,q))     grid[p][q] += 1, q++;
     p=i,q=j;   while (isSafe(p,q))     grid[p][q] += 1, q--;
     p=i,q=j;   while (isSafe(p,q))     grid[p][q] += 1, p--, q--;
     p=i,q=j;   while (isSafe(p,q))     grid[p][q] += 1, p++, q++;
     p=i,q=j;   while (isSafe(p,q))     grid[p][q] += 1, p--, q++;
     p=i,q=j;   while (isSafe(p,q))     grid[p][q] += 1, p++, q--;
     grid[i][j] -= 7; // offset
}

void Solution::removeQueen(int i, int j){

    // unmark all attack positions
     int p,q;
     p=i,q=j;   while (isSafe(p,q))     grid[p][q] -= 1, p++;
     p=i,q=j;   while (isSafe(p,q))     grid[p][q] -= 1, p--;
     p=i,q=j;   while (isSafe(p,q))     grid[p][q] -= 1, q++;
     p=i,q=j;   while (isSafe(p,q))     grid[p][q] -= 1, q--;
     p=i,q=j;   while (isSafe(p,q))     grid[p][q] -= 1, p--, q--;
     p=i,q=j;   while (isSafe(p,q))     grid[p][q] -= 1, p++, q++;
     p=i,q=j;   while (isSafe(p,q))     grid[p][q] -= 1, p--, q++;
     p=i,q=j;   while (isSafe(p,q))     grid[p][q] -= 1, p++, q--;
     grid[i][j] += 7; // offset
}