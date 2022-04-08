// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

// 1) optimized brute force: to avoid repeating calculations: T=O(n), S=O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> Set; int maxLen=0;
        int j=0;
        for (int i=0; i<s.size(); i++){
            while (j<s.size()){
                if (Set.find(s[j]) != Set.end()) break;
                Set.insert(s[j]);
                maxLen = max(maxLen, (int)Set.size()); j++;
            }
             Set.erase(s[i]);
        }
        return maxLen;
    }
};

// 2) brute force: T=O(n^3), S=O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int count = 0;
        unordered_set<char> Set;

        for (int i=0; i<s.size(); i++){
            Set.clear(); Set.insert(s[i]);
            for (int j=i+1; j<s.size(); j++){
                if (Set.find(s[j]) != Set.end()) break;
                else Set.insert(s[j]);
            }
            count = max(count, (int)Set.size());
        }
        return count;
    }
};