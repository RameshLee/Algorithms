// Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/

// Sliding window approach: T=O(N), S=O(1)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int k = p.size();
        if (p.size()>s.size()) return vector<int>();

        vector<char> Map(128), window(128); vector<int> result;
        for (auto c:p) Map[c]++;

        // cover the first window
        for (int i=0; i<k; i++) window[s[i]]++;
        if (Map == window) result.push_back(0); // O(1) check

        // slide the window
        for (int i=k; i<s.size(); i++){
            window[s[i-k]]--;
            window[s[i]]++;
            if (Map == window) result.push_back(i-k+1); // O(1) check
        }
        return result;
    }
};