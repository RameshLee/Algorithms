// Link: https://leetcode.com/problems/binary-search/

class Solution {
public:
    int search(vector<int>& vec, int target)
    {
        int l=0; int r=vec.size()-1;

        while(l<=r){
            int i=(l+r)/2;

            if (vec[i] == target) return i;
            if (vec[i] < target) l++;
            else r--;
        }
        return -1;
    }
};