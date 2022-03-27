// Link: https://leetcode.com/problems/meeting-rooms-ii/

using vi = vector<int>;
using vvi = vector<vi>;
class mySort{ public: bool operator()(vi &A, vi &B){ return A[0]<B[0]; } };
class myHeap{ public: bool operator()(vi &A, vi &B){ return A[1]>B[1]; } };

class Solution {
public:
    int minMeetingRooms(vvi& intervals) {

        sort(intervals.begin(), intervals.end(), mySort()); // sort intervals based on starting time
        int Rooms = 0;
        priority_queue<vi, vector<vi>, myHeap> pq;

        for (int i=0; i<intervals.size(); i++){
            if (!pq.empty()){

                int lowest_l = pq.top()[1];
                int e = intervals[i][0];

                if (e<lowest_l) Rooms++;
                else pq.pop(); // remove this meetingSlot since it got alloted for the new meeting.

                pq.push(intervals[i]);
            }
            else{
                Rooms++;
                pq.push(intervals[i]);
            }
        }
        return Rooms;
    }
};