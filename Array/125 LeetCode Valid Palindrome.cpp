// Link: https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {

        // convert to lowercase
        string str;
        for (auto c:s) {
            if (std::isalpha(c)) str.push_back(std::tolower(c));
            else if (std::isdigit(c)) str.push_back(c);
        }

        // check palindrome
        int l=0, r=str.size()-1;
        while (l<=r){
            if (str[l] != str[r]) return false;
            l++, r--;
        }
        return true;
    }
};