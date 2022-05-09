// Link: https://leetcode.com/problems/largest-3-same-digit-number-in-string/

// Sliding window approach: T=O(N), S=O(1)

class Solution {
public:
    string largestGoodInteger(string s) {
        string ret;
        if (s.size() < 3) return ret;

        // for the first three letters
        vector<int> vec(10,0);
        for (int i=0; i<3; i++) {
            string c = s.substr(i,1);
            vec[stoi(c)]++;
        }

        // sliding window approach
        int l=0;
        for (int r=3; r<s.size(); r++, l++) {
            if (isValid(vec))
                if (ret.empty() || stoi(ret) < stoi(s.substr(l,3)))
                    ret = s.substr(l,3);
            vec[stoi(s.substr(r,1))]++;
            vec[stoi(s.substr(l,1))]--;
        }
        if (isValid(vec))
            if (ret.empty() || stoi(ret) < stoi(s.substr(l,3)))
                ret = s.substr(l,3);
        return ret;
    }
private:
    bool isValid(vector<int>& vec) {
        int totalPosNums = 0;
        for (auto i:vec) {
            if (i > 0)
                totalPosNums++;
        }
        return (totalPosNums <= 1) ? true : false;
    }
};