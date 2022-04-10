// Link: https://leetcode.com/problems/minimum-window-substring/

// Sliding window technique: T=O(n)
// basically, find the longest substring with 2 distinct characters.

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        map<int,int> visited;

        int l=0, r, len=0, maxLen=0;
        for (r=0; r<fruits.size(); r++){

            int ele = fruits[r];
            visited[ele]++, len++; // expand the right window

            if (visited.size() <= 2)  maxLen = max(maxLen,len);
            if (visited.size() > 2){ // shrink the right window
                while (visited.size() > 2){
                    if (--visited[fruits[l]] == 0) visited.erase(fruits[l]);
                    l++, len--;
                }
            }
        }
        return maxLen;
    }
};