// Link: https://leetcode.com/problems/first-bad-version/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n)
    {
        // corner-case
        if (n == 1)
        {
            if (isBadVersion(n))
                return n;
            else
                return -1;
        }
        else if (n == 2)
        {
            if (isBadVersion(n-1))
                return n-1;
            else if (!isBadVersion(n-1) && isBadVersion(n))
                return n;
            else return -1;
        }

        // randomized binary search
        int LB = 0;
        int UB = n;
        int pivot = rand()%(UB-LB)+LB;

        while (1)
        {
            if (!isBadVersion(pivot-1) && isBadVersion(pivot))
                    return pivot;
            else if (!isBadVersion(pivot)) //not bad
            {
                LB = pivot;
                pivot = rand()%(UB-LB)+LB;
            }
            else if (isBadVersion(pivot)) // bad
            {
                UB = pivot;
                pivot = rand()%(UB-LB)+LB;
            }

            if (abs(LB-UB) == 1)
                 if (isBadVersion(UB))
                    return UB;

        }

        return -1;

    }
};