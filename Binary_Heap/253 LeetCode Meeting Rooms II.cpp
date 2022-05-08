// Link: https://leetcode.com/problems/meeting-rooms-ii/

class myComparator{
public:
    bool operator()(vector<int> &A, vector<int> &B) const{
        return A[1]>B[1];
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end()); // sort intervals based on starting time

        using vi = vector<int>;
        priority_queue<vi, vector<vi>, myComparator> pq;

        int Rooms = 0;
        for (int i=0; i<intervals.size(); i++){
            if (!pq.empty()){

                int endTime = pq.top()[1]; // earliest end time of any meeting
                int startTime = intervals[i][0]; // start time of the current meeting

                if (startTime>=endTime) {
                    pq.pop(); // book this existing room for the new meeting.
                }
                else Rooms++;
            }
            else Rooms++; // allot a new room
            pq.push(intervals[i]);
        }
        return Rooms;
    }
};

/*
using pi = pair<int,int>;
using vpi = vector<vector<pi>>;

class Solution {
public:
    int maxColors = 1;

    bool isOverlap(int i, int j, vector<vector<int>>& intervals){

        int e1 = intervals[i][0];
        int l1 = intervals[i][1];
        int e2 = intervals[j][0];
        int l2 = intervals[j][1];

        if (e1==e2) return true;

        if (e1<e2){
            if (e2<l1) return true;
        }
        else if (e2<e1){
            if (e1<l2) return true;
        }


        return false;
    }

    void bfs(vpi &graph, vector<int>& visited, int curr){


        queue<pi> q;
        q.push(make_pair(curr,1));

        while (!q.empty()){

            int i = q.front().first;
            int &color = q.front().second;
            q.pop();

            printf("Popped node %d, col %d\n", i, color);

            printf(" changed: Popped node %d, col %d\n", i, color);


            for (int j=0; j<graph[i].size(); j++){
                int k = graph[i][j].first;
                int N_color = graph[i][j].second;

                if (color == N_color){
                    color = maxColor;
                }
            }

            for (int j=0; j<graph[i].size(); j++){
                int k = graph[i][j].first;
                int thisColor = graph[i][j].second;
                if (visited[k] == 0){

                     printf("   neighbor %d, col %d, currcolor %d\n", k, thisColor, color);
                    q.push(make_pair(k,thisColor));
                    visited[k] = 1;
                }

            }
        }
    }

    int minMeetingRooms(vector<vector<int>>& intervals) {

        vpi graph(intervals.size());

        for (int i=0; i<intervals.size(); i++)
            for (int j=i+1; j<intervals.size(); j++){
                //printf("Checking edge: (%d,%d)\n",i,j);
                if (isOverlap(i,j,intervals)){
                    graph[i].push_back(make_pair(j,1));
                    //printf("    Adding edge: (%d,%d)\n",i,j);
                }
            }

        for (int i=0; i<graph.size(); i++){
            printf("Edges %d: ", i);
            for (auto& ele:graph[i])
                    printf(" %d", ele.first);
            printf("\n");
        }

        vector<int> visited(graph.size(), 0);
        for (int i=0; i<graph.size(); i++)
            if (visited[i] == 0)
                bfs(graph, visited, i);

        return maxColors;
    }
};
*/