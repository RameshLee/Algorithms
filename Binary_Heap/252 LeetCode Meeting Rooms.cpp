// Link: https://leetcode.com/problems/meeting-rooms/

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& interval) {
        if (interval.empty()) return true; // corner case

        sort(interval.begin(), interval.end()); // sort according to startTimes

        int meetingRooms = 1;
        priority_queue<int> pq;
        pq.push(interval[0][1]);

        for (auto i=1; i<interval.size(); i++){ // find total required meeting rooms
            int endTime = pq.top();
            int startTime = interval[i][0];
            if (endTime <= startTime)   pq.pop();
            else                        meetingRooms++;
            pq.push(interval[i][1]);
        }
        return (meetingRooms == 1) ? true : false;
    }
};