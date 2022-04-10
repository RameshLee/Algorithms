// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/


// 1) sliding window approach: T(n), O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.empty()) return 0;

        vector<int> visited(128,0);
        int l=0, r=0, len=0, maxLen=1;
        for (r=0; r<s.size(); r++){

            // move the right-side of the window
            char ele = s[r];
            visited[ele]++, len++;
            if (visited[ele] == 1) maxLen = max(maxLen, len);

            // move the left-side of the window
            if (visited[ele] > 1){
                while (s[l] != ele) visited[s[l]]--, l++, len--;
                visited[s[l]]--, l++, len--;
            }
        }
        return maxLen;
    }
};


// 2) optimized brute force: to avoid repeating calculations: T=O(n), S=O(n)

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


// 3) brute force: T=O(n^3), S=O(n)
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