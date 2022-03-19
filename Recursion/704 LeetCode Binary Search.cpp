// Link: https://leetcode.com/problems/binary-search/

class Solution {
public:
    int binarySearch(vector<int>& vec, int l, int r, int target){
        if (l>r) return -1;

        int i=(l+r)/2;
        if (vec[i] == target) return i;
        if (vec[i] < target) return binarySearch(vec, i+1, r, target);
        else return binarySearch(vec, l, i-1, target);
    }

    int search(vector<int>& vec, int target)
    {
        return binarySearch(vec, 0, vec.size()-1, target);
    }
};