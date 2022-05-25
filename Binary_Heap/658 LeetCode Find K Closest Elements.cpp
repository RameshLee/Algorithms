// Link: https://leetcode.com/problems/find-k-closest-elements/

int x; // global variable: to be used in custom comparator of priority_queue

class Comparator {
public:
    bool operator()(int a, int b) {
        return (abs(a-x) == abs(b-x)) ? a>b : (abs(a-x) > abs(b-x));
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int X) {
        x = X;
        priority_queue<int, vector<int>, Comparator> pq(arr.begin(), arr.end()); // O(N)
        vector<int> result;
        while (--k >= 0 && !pq.empty()) {
            result.push_back(pq.top()), pq.pop(); // O(k*logN)
        }
        std::sort(result.begin(), result.end()); // O(N*logN)
        return result;
    }
};