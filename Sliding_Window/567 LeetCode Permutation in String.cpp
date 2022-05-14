// Link: https://leetcode.com/problems/permutation-in-string/

// Sliding window approach: T=O(n), S=O(1)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int k = s1.size();
        if (s1.size() > s2.size()) return false;

        vector<char> Map(128), window(128);
        for (auto c:s1) Map[c]++;

        // cover the first window
        for (int i=0; i<k; i++) window[s2[i]]++;
        if (Map == window) return true;

        // slide the window
        for (int i=k; i<s2.size(); i++) {
            window[s2[i-k]]--;
            window[s2[i]]++;

            if (Map == window) return true; // O(1) comparison
        }
        return false;
    }
};