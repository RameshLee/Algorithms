// Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        if (letters[0] > target) return letters[0];

        int l=1, r=letters.size()-1;
        while (l<=r){
            int i = l + rand()%(r-l+1);;
            if (letters[i] > target && letters[i-1] <= target) return letters[i];
            if (letters[i] > target) r = i-1;
            else l = i+1;
        }
        return letters[0];
    }
};