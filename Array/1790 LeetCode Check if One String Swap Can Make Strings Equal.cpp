// Link: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

		// edge-cases
        if (s1==s2) return true;
        if (s1.size() != s2.size()) return false;

        int vec[4]; int size = 0; int diff = 0;
        for (int i=0; i<s1.size(); i++)
            if (s1[i] != s2[i]){
                diff++;
                vec[size++] = s1[i];
                vec[size++] = s2[i];
                size = (size>=4)?0:size;
            }
        if (diff == 2 && vec[0]==vec[3] && vec[1]==vec[2]) return true;
        return false;
    }
};