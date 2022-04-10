// Link: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {

        map<char,int> visited;

        int l=0, r=0, len=0, maxLen=0;
        for (r=0; r<s.size(); r++){

            char ele = s[r];
            visited[ele]++, len++;    // move the right-side of the window

            if (visited.size() <= k) maxLen = max(maxLen,len); // record answer
            else{    // move the left-side of the window
                while (visited.size() > k){
                    if (--visited[s[l]] == 0) visited.erase(s[l]);
                    len--, l++;
                }
            }
        }
        return maxLen;
    }
};