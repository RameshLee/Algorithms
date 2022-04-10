// Link: https://leetcode.com/problems/palindromic-substrings/

class Solution {
private: int table[1000][1000] = {0}; // memoization table
public:
    bool check(string& s, int l, int r){ // check palindrome
       while (l<=r){
            if (table[l][r]) return true; // memoization
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }

    int countSubstrings(string s) {

        int count = 0;
        for (int i=0; i<s.size(); i++){
            for (int j=i; j<s.size(); j++){
                if (!table[i][j]){ // memoization
                    if (check(s,i,j)) {
                        count++;
                        table[i][j] == 1;
                    }
                }
                else count++;
            }
        }
        return count;
    }
};