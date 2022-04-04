// Link: https://leetcode.com/problems/first-bad-version/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// Binary search: T=O(logN), S=O(1) (100% Faster)

class Solution {
public:
    int firstBadVersion(int n)
    {
        int l=1, r=n;
        while (l<=r){
            int i = l + rand()%(r-l+1);
            if (isBadVersion(i)){
                if (i-1>=0 && isBadVersion(i-1)==false) return i;
                r = i-1;
            }
            else l = i+1;
        }
        return l;
    }
};