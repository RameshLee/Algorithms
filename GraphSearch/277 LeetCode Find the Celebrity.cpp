// Link: https://leetcode.com/problems/find-the-celebrity/

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        for (auto attendee=0; attendee<n; attendee++)
            if (isCelebrity(attendee, n))
                return attendee;
        return -1;
    }
private:
    int isCelebrity(int celebrity, int n) {
        for (auto attendee=0; attendee<n; attendee++) {
            if (celebrity == attendee) continue;
            if (!knows(attendee,celebrity) || knows(celebrity,attendee)) return false;
        }
        return true;
    }
};