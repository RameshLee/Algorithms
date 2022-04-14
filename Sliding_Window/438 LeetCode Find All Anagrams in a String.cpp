// Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        if (p.size()>s.size()) return vector<int>();

        // initialization
        vector<char> Map(26,0), slidingWindow(26,0);
        vector<int> ret; int n=p.size();

        // update the mapping for p
        for (auto c:p) Map[c%26]++;

        // update the sliding window mapping for s
        for (int i=0; i<n; i++) slidingWindow[s[i]%26]++;

        // move the sliding window from left to right
        for (int i=0; i<s.size()-n; i++){

            if (Map == slidingWindow) ret.push_back(i); // O(1) check

            slidingWindow[s[i]%26]--;
            slidingWindow[s[i+n]%26]++;
        }
        if (Map == slidingWindow) ret.push_back(s.size()-n);
        return ret;
    }
};