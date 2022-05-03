// Link: https://leetcode.com/problems/design-tic-tac-toe/

class TicTacToe {
public:
    TicTacToe(int n) {
        this->n = n;
        grid.assign(n, vector<int>(n,0));
    }

    int move(int i, int j, int player) {
        grid[i][j] = player;
        return isGameOver(i,j,player) ? player : 0;
    }
private:
    int n; vector<vector<int>> grid;

    bool isGameOver(int i, int j, int player);
    bool checkRow(int i, int j, int player);
    bool checkColumn(int i, int j, int player);
    bool checkDiagonal(int i, int j, int player);
    bool checkAntiDiagonal(int i, int j, int player);
    bool isSafe(int i, int j);
};

bool TicTacToe::isGameOver(int i, int j, int player){
    if (checkRow(i,j,player)) return true;
    if (checkColumn(i,j,player)) return true;
    if (checkDiagonal(i,j,player)) return true;
    if (checkAntiDiagonal(i,j,player)) return true;
    return false;
}


bool TicTacToe::checkRow(int i, int j, int player){
    int p,q;
    p=i,q=j; while (isSafe(p,q)) {if (grid[p][q] != player) return false; q--;}
    p=i,q=j; while (isSafe(p,q)) {if (grid[p][q] != player) return false; q++;}
    return true;
}

bool TicTacToe::checkColumn(int i, int j, int player){
    int p,q;
    p=i,q=j; while (isSafe(p,q)) {if (grid[p][q] != player) return false; p--;}
    p=i,q=j; while (isSafe(p,q)) {if (grid[p][q] != player) return false; p++;}
    return true;
}

bool TicTacToe::checkDiagonal(int i, int j, int player){
    int p,q;
    if (i==j){
        p=i,q=j; while (isSafe(p,q)) {if (grid[p][q] != player) return false; p++, q++;}
        p=i,q=j; while (isSafe(p,q)) {if (grid[p][q] != player) return false; p--, q--;}
        return true;
    } return false;
}

bool TicTacToe::checkAntiDiagonal(int i, int j, int player){
    int p,q;
    if (i==(n-1-j)){
        p=i,q=j; while (isSafe(p,q)) {if (grid[p][q] != player) return false; p--, q++;}
        p=i,q=j; while (isSafe(p,q)) {if (grid[p][q] != player) return false; p++, q--;}
        return true;
    } return false;
}

bool TicTacToe::isSafe(int i, int j){
        return (i>=0 && j>=0 && i<n && j<n) ? true : false;
    }


/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */