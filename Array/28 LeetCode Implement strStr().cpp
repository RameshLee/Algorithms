// Link: https://leetcode.com/problems/implement-strstr/

// 1) sliding window approach
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        for (int l=0; l<haystack.size(); l++) { // move the left side of window
            int r=l, index = 0;
            while (haystack[r] == needle[index]) { // expand the right side of window
                if (haystack.substr(l,r-l+1) == needle) return l;
                r++, index++;
            }
        }
        return -1;
    }
};


// 2) using inbuilt function
class Solution {
public:
    int strStr(string haystack, string needle) {
        auto index = haystack.find(needle);
        if (index == string::npos) return -1;
        else return index;
    }
};