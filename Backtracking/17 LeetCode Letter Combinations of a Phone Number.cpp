// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    map<char,string> Map= {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    map<char,int> TotalCharacters = {{'2',3},{'3',3},{'4',3},{'5',3},{'6',3},{'7',4},{'8',3},{'9',4}};
    vector<string> input, output;
    string str, InputDigits; int Count;

    void backtrack(int digit){

        if (str.size() == Count){  // base-case
            output.push_back(str);
            return;
        }

        //explore candidates
        int limit = TotalCharacters[InputDigits[digit]];
        for (int j=0; j<limit; j++){
            str.push_back(input[digit][j]); //make move
            backtrack(digit+1); //backtrack
            str.pop_back();  //undo move
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty()) return output; // corner-case

        InputDigits = digits;
        Count = digits.size();
		for (auto& it:digits) input.push_back(Map[it]);

		backtrack(0);  // backtracking approach
        return output;
    }
};