// Link: https://leetcode.com/problems/binary-search/

// 1) Iterative

class Solution {
public:
    int search(vector<int>& vec, int target)
    {
        int l=0, r=vec.size()-1;
        while (l<=r){
            int i = l + rand()%(r-l+1);
            if (vec[i] == target) return i;
            if (vec[i] < target) l=i+1;
            else r=i-1;
        }
        return -1;
    }
};

// 2) Recursive

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