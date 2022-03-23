// Link: https://leetcode.com/problems/n-queens-ii/

class Solution {
public:
    int n;
    int DistinctSolutions = 0;
    vector<vector<int>> grid; //0-Feasible,1-UnderAttack
    unordered_map<int,int> Map; //stores the Q positions

    bool isSafe(int i, int j);
    bool isValidPosition(int r, int c);
    void place_queen(int r, int c);
    void remove_queen(int r, int c);
    void backtrack(int r);
    int totalNQueens(int _n);
};

bool Solution::isSafe(int i, int j){
    if (i>=0 && j>=0 && i<n && j<n) return true;
    else return false;
}

bool Solution::isValidPosition(int r, int c){
    if (grid[r][c] == 0) return true;
    else return false;
}

void Solution::place_queen(int r, int c){

    // Add Queen into hashMap
    Map[r] = c;

    // 1) mark row-wise attack positions
    for (int j=0; j<n; j++) grid[r][j] += 1;

    // 2) mark col-wise attack positions
    for (int i=0; i<n; i++) grid[i][c] += 1;

    // 3) mark right-cross attack positions
    int i,j;
    i=r, j=c; while (isSafe(i,j)){ // upper-right
        grid[i][j] += 1; i--; j++;
    }

    i=r, j=c; while (isSafe(i,j)){ //lower-right
        grid[i][j] += 1; i++; j--;
    }

    // 4) mark left-cross attack positions
    i=r, j=c; while (isSafe(i,j)){ // upper-left
        grid[i][j] += 1; i--; j--;
    }
    i=r, j=c; while (isSafe(i,j)){ //lower-left
        grid[i][j] += 1; i++; j++;
    }

    grid[r][c] -= 5; //offset junk additions
}

void Solution::remove_queen(int r, int c){

    // Remove Queen from hashMap
    Map.erase(r);

    // 1) row
    for (int j=0; j<n; j++) grid[r][j] -= 1;

    // 2) col
    for (int i=0; i<n; i++) grid[i][c] -= 1;

    // 3) right cross
    int i,j;
    i=r, j=c; while (isSafe(i,j)){ // upper-right
        grid[i][j] -= 1; i--; j++;
    }

    i=r, j=c; while (isSafe(i,j)){ //lower-right
        grid[i][j] -= 1; i++; j--;
    }

    // 4) left cross
    i=r, j=c; while (isSafe(i,j)){ // upper-left
        grid[i][j] -= 1; i--; j--;
    }
    i=r, j=c; while (isSafe(i,j)){ //lower-left
        grid[i][j] -= 1; i++; j++;
    }

    grid[r][c] += 5; //offset junk subtractions
}

void Solution::backtrack(int r){

    if (r==n && Map.size() == n){
        DistinctSolutions++;
        return;
    }

    for (int c=0; c<n; c++){
        if (isValidPosition(r,c)){
            place_queen(r,c);
            backtrack(r+1);
            remove_queen(r,c);
        }
    }
}

int Solution::totalNQueens(int _n) {

    n = _n;
    grid.resize(n,vector<int>(n,0));
    backtrack(0);
    return DistinctSolutions;
}
