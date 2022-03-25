// Link: https://leetcode.com/problems/generate-parentheses/

// Backtracking approach (100% Faster)

class Solution {
public:
    vector<string> output;
    int n; string str ="";

    void backtrack(int i, int sum, int open, int closed){

        if (sum<0 || open>n || closed>n) return; //solution is infeasible

        if (i == 2*n) { // update feasible solution
            output.push_back(str);
            return;
        }

        // for all candidates
        for (int c=0; c<2; c++){ //0-open,1-closed

            // make move
            if (c==0) str.push_back('('), sum++, open++; //add open bracket
            else str.push_back(')'), sum--, closed++; //add closed bracket

            // backtrack
            backtrack(i+1, sum, open, closed);

            // undo move
            if (c==0) str.pop_back(), sum--, open--; //remove open bracket
            else str.pop_back(), sum++, closed--; //remove closed bracket
        }
    }

    vector<string> generateParenthesis(int _n) {

        n = _n;
        backtrack(0,0,0,0);
        return output;
    }
};

