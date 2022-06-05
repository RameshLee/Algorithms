// Link: https://leetcode.com/problems/car-pooling/

// Variant of the meeting rooms problem: https://leetcode.com/explore/learn/card/heap/646/practices/4087/
class mySort {
public:
    bool operator()(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    }
};

class myPriorityQueue {
public:
    bool operator()(const vector<int>& v1, const vector<int>& v2) {
        return v1[2] > v2[2];
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // sort trips according to their starting times
        std::sort(trips.begin(), trips.end(), mySort());
        priority_queue<vector<int>, vector<vector<int>>, myPriorityQueue> pq;

        // pull from priority queue according to their ending times
        int load = 0;
        for (auto e:trips) {

            // drop off all possible customers
            auto start = e[1]; // starting time of current trip
            while (!pq.empty()) {
                auto end = pq.top()[2]; // ending time of any trip
                if (start < end) break;
                else {
                    load -= pq.top()[0]; // drop-off
                    pq.pop();
                }
            }

            // pick up the current customer
            if (e[0] + load > capacity) return false;
            else {
                pq.push(e);
                load += e[0]; // pick-up
            }
        }
        return true;
    }
};