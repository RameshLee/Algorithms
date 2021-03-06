// Link: https://leetcode.com/problems/n-queens-ii/submissions/

class Solution {
public:
    int totalNQueens(int n) {
        this->n = n;
        grid.resize(n,vector<int>(n,0));
        backtrack(0);
        return DistinctSolutions;
    }
public:
    int n, DistinctSolutions = 0;
    vector<vector<int>> grid;

    void backtrack(int i);
    void place_queen(int i, int j);
    void remove_queen(int i, int j);
    bool isSafe(int i, int j);
    bool isValidPosition(int i, int j);
};

void Solution::backtrack(int i){

    if (i==n){ // base-case
        DistinctSolutions++;
        return;
    }

    for (int j=0; j<n; j++){ // for all candidates
        if (isValidPosition(i,j)){
            place_queen(i,j);  // make move
            backtrack(i+1);    // backtrack
            remove_queen(i,j); // undo move
        }
    }
}

bool Solution::isSafe(int i, int j){
    if (i>=0 && j>=0 && i<n && j<n) return true;
    else return false;
}

bool Solution::isValidPosition(int r, int c){
    if (grid[r][c] == 0) return true;
    else return false;
}

void Solution::place_queen(int i, int j){

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

void Solution::remove_queen(int i, int j){

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


