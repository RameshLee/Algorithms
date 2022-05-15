// Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        for (auto s:tokens) {
            if (isValidSymbol(s))  op.push(s);
            else                val.push(stoi(s));
            collapseStacks();
        }
        return val.top();
    }
private:
    stack<int> val; stack<string> op;

    bool isValidSymbol(string Symb) {
        return (Symb == "+" || Symb == "-" || Symb == "*" || Symb == "/") ? true : false;
    }

    int applyOperation(int a, int b, string Symb) {
         return (Symb == "+" ?  a+b : (Symb == "-" ?  a-b : (Symb == "*" ?  a*b : (Symb == "/" ?  a/b : -1 ))));
    }

    void collapseStacks() {
        while (val.size() >= 2 && op.size() >= 1) {
            auto a = val.top(); val.pop();
            auto b = val.top(); val.pop();
            auto Symb = op.top(); op.pop();
            auto result = applyOperation(b,a,Symb);
            val.push(result);
        }
    }
};