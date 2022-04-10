// Link: https://leetcode.com/problems/3sum/

// 1) back up the indices for odd and even numbers
// 2) sort odd and even numbers separately
// 3) combine the sorted elements according to indices

class Solution {
public:
    int largestInteger(int num) {

        vector<int> evenIndices, oddIndices, even, odd;

        string s = to_string(num);

        for (int i=0; i<s.size(); i++){
            int val = (int)s[i]-48;
            if (val%2 == 0) even.push_back(val), evenIndices.push_back(i);
            else            odd.push_back(val), oddIndices.push_back(i);
        }
        sort(even.rbegin(), even.rend());
        sort(odd.rbegin(), odd.rend());

        // merge them
        int l=0,r=0; string ret;
        for (int i=0; i<s.size(); i++){

            if (l>=even.size())                         ret += to_string(odd[r]), r++;
            else if (r>=odd.size())                     ret += to_string(even[l]), l++;
            else if (evenIndices[l] < oddIndices[r])    ret += to_string(even[l]), l++;
            else                                        ret += to_string(odd[r]), r++;
        }
        //printf("ret: %s\n", ret.c_str());
        return stoi(ret);
    }
};