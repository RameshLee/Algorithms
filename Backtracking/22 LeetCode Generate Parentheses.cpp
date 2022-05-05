// Link: https://leetcode.com/problems/generate-parentheses/

// Backtracking approach (100% Faster)

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        backtrack(0);
        return output;
    }
private:
    vector<string> output; string s; int n, sum=0, open=0, closed=0;
    enum Brackets{OPEN_BRACKET='(', CLOSED_BRACKET=')'};

    void backtrack(int i) {

        if (sum<0 || open>n || closed>n) return; //solution is infeasible

        if (i == 2*n) { // update feasible solution
            output.push_back(s);
            return;
        }

         // for all candidates
        s.push_back(OPEN_BRACKET), sum++, open++; //add open bracket
        backtrack(i+1); // backtrack
        s.pop_back(), sum--, open--; //remove open bracket

        s.push_back(CLOSED_BRACKET), sum--, closed++; //add closed bracket
        backtrack(i+1); // backtrack
        s.pop_back(), sum++, closed--; //remove closed bracket
    }

};