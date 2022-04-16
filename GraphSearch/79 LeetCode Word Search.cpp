// Link: https://leetcode.com/problems/word-search/

class Solution {
private:  string s; int row, col, index=0, dir[5] = {1,0,-1,0,1}; bool decision = false;
public:
    bool isSafe(int i, int j){
        return (i>=0 && j>=0 && i<row && j<col) ? true : false;
    }

    void backtrack(int i, int j, vector<vector<char>>& board, string &word){

        if (index >= word.size()) return; // base-case
        if (word[index] != board[i][j]) return; // search pruning

        s.push_back(board[i][j]); // make move
        board[i][j] = 'X';
        index++;

        if (s == word) decision = true; // record solution

        for (int k=0; k<4; k++) // backtrack
            if (isSafe( i+dir[k], j+dir[k+1] ))
                backtrack(i+dir[k], j+dir[k+1], board, word);

        board[i][j] = s.back(); // undo move
        s.pop_back();
        index--;
    }

    bool exist(vector<vector<char>>& board, string word) {

        // apply dfs from all starting characters in board
        row = board.size(), col = board[0].size();
        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
                if (board[i][j] == word[0]){
                    backtrack(i,j,board,word);
                }

        return decision;
    }
};