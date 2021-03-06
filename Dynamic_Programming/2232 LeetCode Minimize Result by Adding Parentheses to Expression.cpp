// Link: https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/

class Solution {
private: int memo[1000][1000] = {0}, globalMin = INT_MAX, pos1, pos2;
public:
    int calculate(string str){

        // parse the string into four values
        string prev, first, second, later;
        int i=0;
        while (str[i] != '(') prev.push_back(str[i]), i++; i++;
        while (str[i] != '+') first.push_back(str[i]), i++; i++;
        while (str[i] != ')') second.push_back(str[i]), i++; i++;
        while (i < str.size()) later.push_back(str[i]), i++;

        // convert the string to integer
        int a=1,b=1,c=1,d=1;
        if (!prev.empty()) a = stoi(prev);
        b = stoi(first), c = stoi(second);
        if (!later.empty()) d = stoi(later);

        int finalVal = a * (b+c) * d; // calculate final value

        return finalVal;
    }

    void helper(string s, int l, int r){

        if (l<0 || r>s.size()+1) return;

        if (memo[l][r] == 0){ // memoization
            string str = s;
            str.insert(str.begin()+l, '(');
            str.insert(str.begin()+r, ')');
            memo[l][r] = calculate(str);

            if (globalMin > memo[l][r]){ // update globalMin
                globalMin = memo[l][r], pos1 = l, pos2 = r;
            }
        }

        helper(s,l-1,r);
        helper(s,l,r+1);
    }

    string minimizeResult(string s) {

        // find initial bracket insertion positions: (l,r)
        int l,r;
        for (int i=0; i<s.size(); i++)
            if (s[i] == '+'){
                l=i-1; r=i+3;
                break;
            }

        // recursively insert brackets
        helper(s,l,r);

        // compute the final answer
        s.insert(s.begin()+pos1, '(');
        s.insert(s.begin()+pos2, ')');

        return s;
    }
};