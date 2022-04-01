// Link: https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    enum symbol{DOT = '.'};
    int start_i[9] = {0,0,0, 3,3,3, 6,6,6};
    int start_j[9] = {0,3,6, 0,3,6, 0,3,6};
    int end_i[9]   = {2,2,2, 5,5,5, 8,8,8};
    int end_j[9]   = {2,5,8, 2,5,8, 2,5,8};

    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<char,int> Map;

        // 3x3 grid-by-grid sweep
        for (int k=0; k<9; k++){
            Map.clear();
            for (int i=start_i[k]; i<=end_i[k]; i++){
                for (int j=start_j[k]; j<=end_j[k]; j++){
                    char val = board[i][j];
                    if (val != DOT){
                        if (Map.find(val) != Map.end()) return false;
                        else Map[val] = 1;
                    }
                }
            }
        }

        // horizontal sweep
        for (int i=0; i<9; i++){
            Map.clear();
            for (int j=0; j<9; j++){
                char val = board[i][j];
                if (val != DOT){
                    if (Map.find(val) != Map.end()) return false;
                    else Map[val] = 1;
                }
            }
        }

        // vertical sweep
        for (int i=0; i<9; i++){
            Map.clear();
            for (int j=0; j<9; j++){
                char val = board[j][i];
                if (val != DOT){
                    if (Map.find(val) != Map.end()) return false;
                    else Map[val] = 1;
                }
            }
        }

        return true;
    }
};