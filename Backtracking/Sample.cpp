

/*
< expression > = < term > | < term > + < term >| < term > — < term >
< term > = < factor > | < factor > * < factor > | < factor > / < factor >
< factor > = < letter > | (< expression >)
<letter>= A|B|...|Z

Example: s = A+(B-C)
*/

#include <iostream>
#include <string>
#include <algorithm>

class Expression {
private:
    unordered_map<char,bool> letterMap = {{'A',true},....,{'Z',true}}; // hashmap STL O(1) search
    unordered_map<char,bool> symbolMap = {{'+',true},....,{')',true}};
    string s;

    int open=0, closed=0, sum=0; // to validate the brackets
    std::stack<char> Letter, Symbol; //  to read letter and symbol
    bool result = true;

public:
    Expression(string input): s(input) {}
    ~Expression() {}

public:
    bool validate() {
        int i = 0;
        while (i < s.size()) {
            if (letterMap.find(s[i]) == letterMap.end()) return false;
            else {
                Letter.push(s[i]), i++;
                continue;
            }

            if (symbolMap.find(s[i]) == symbolMap.end()) return false;
            else if (Letter.empty()) return false; // a symbol is encountered: check whether letter is present on the letterstack
        }
        return result;
    }

};

int main() {

    string input = "A+(B-C)";
    Expression E(input);
    if (E.validate()) printf("Valid\n");
    else              printf("NOT Valid\n");
    return 0;
}

