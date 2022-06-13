// Link: https://leetcode.com/problems/valid-palindrome/


// 1) Optimized approach: T=O(N), S=O(1)

class Solution {
public:
    bool isPalindrome(string s) {

        // in-place erase everything except digits & characters
        auto index = 0;
        for (auto i=0; i<s.size(); i++) {
            if (std::isalpha(s[i]) || std::isdigit(s[i]))
                s[index++] = std::tolower(s[i]);
        }

        // check palindrome
        auto l=0, r=index-1;
        while (l<=r) {
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