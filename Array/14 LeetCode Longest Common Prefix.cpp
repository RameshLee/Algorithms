// Link: https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& vec) {

        string ret;
        int minSize = INT_MAX;
        for (int i=0; i<vec.size(); i++)
            minSize = min(minSize, (int)vec[i].size());

        for (int j=0; j<minSize; j++){
            for (int i=0; i<vec.size(); i++)
                if (i>0 && vec[i][j] != vec[i-1][j])
                    return ret;
            ret.push_back(vec[0][j]);
        }

        return ret;
    }
};