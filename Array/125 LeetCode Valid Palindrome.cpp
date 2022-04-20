// Link: https://leetcode.com/problems/valid-palindrome/


// 1) Optimized approach: T=O(N), S=O(1)

class Solution {
public:
    bool isPalindrome(string s) {

        // in-place erase everything except digits & characters
        int i = 0;
        while(1){
            if (i>=s.size()) break;
            if (std::isalpha(s[i]) || std::isdigit(s[i])) {
                 s[i] = std::tolower(s[i]);
            }
            else {
                s.erase(s.begin()+i);
                i--;
            }
            i++;
        }

        // check palindrome
        int l=0, r=s.size()-1;
        while (l<=r){
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
};

// 2) Simple approach: T=O(N), S=O(N)

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