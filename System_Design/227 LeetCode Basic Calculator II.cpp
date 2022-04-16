// Link: https://leetcode.com/problems/basic-calculator-ii/submissions/

class Solution {
public:
    vector<int> val; vector<char> op;
    enum operators{ADD='+', SUBTRACT='-', MULTIPLY='*', DIVIDE='/', BLANK=' '};

    int findPrecedence(char operation){
        switch(operation){
            case ADD: return 1; break;
            case SUBTRACT: return 1; break;
            case MULTIPLY: return 2; break;
            case DIVIDE: return 2; break;
            case BLANK: return 0; break;
        }
        return 0;
    }

    int performOp(int a, char operation, int b){
        switch(operation){
            case ADD: return b+a; break;
            case SUBTRACT: return b-a; break;
            case MULTIPLY: return b*a; break;
            case DIVIDE: return b/a; break;
            case BLANK: return 0; break;
        }
        return 0;
    }

    void collapseStack(char nextOp){

        // take two values and perform one operation
        while (!op.empty() && findPrecedence(op.back()) >= findPrecedence(nextOp)){
            if (val.size()>=2 && op.size()>=1){
                auto a = val.back(); val.pop_back();
                auto b = val.back(); val.pop_back();
                auto symb = op.back(); op.pop_back();

                val.push_back(performOp(a,symb,b));
            }
        }
    }

    int calculate(string s) {

        // remove blanks
        s.erase(std::remove(s.begin(), s.end(), BLANK), s.end());

        int i=0;
        for (auto loop:s){
            // extract digit
            if (i<s.size()){
                auto pos=i, length=0;
                while (std::isdigit(s[i])) i++, length++;
                val.push_back(  stoi( s.substr(pos,length) )  );
            }

            // extract operator
            if (i<s.size()){
                collapseStack(s[i]);
                op.push_back(s[i]), i++;
            }
        }
        while (!op.empty()) collapseStack(BLANK), i++;
        return val.back();


    }
};