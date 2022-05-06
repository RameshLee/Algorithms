// Link: https://leetcode.com/problems/find-median-from-data-stream/

// Using two balancing heaps: T=O(logN), S=O(N)

class MedianFinder {
public:
    void addNum(int num) {
        if (small.empty()) small.push(num);
        else if (large.empty()) large.push(num);
        else {
            if (num < small.top()) small.push(num);
            else if (num > large.top()) large.push(num);
            else small.push(num);
            rebalanceHeaps();
        }

        // spl case: if both heaps have 1 element, ensure the ordering of elements.
        if (small.size() == 1 && large.size() == 1) {
            if (small.top() > large.top()) {
                int A = small.top(), B = large.top();
                small.pop(), large.pop();
                small.push(B), large.push(A);
            }
        }
    }

    double findMedian() {
        double val;
        if (small.size() == large.size())   val = (double)(small.top() + large.top()) / 2;
        else if (small.size() > large.size())    val = small.top();
        else if (large.size() > small.size())    val = large.top();
        return val;
    }
private:
    priority_queue<int, vector<int>, greater<int>> large; // minHeap: to store larger half
    priority_queue<int> small; // maxHeap: to store smaller half

    void rebalanceHeaps() { // ensure that the size of two heaps differ atmost by 1
        if (small.size() > (1+large.size())) {
            int val = small.top(); small.pop();
            large.push(val);
        }
        else if (large.size() > (1+small.size())) {
            int val = large.top(); large.pop();
            small.push(val);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */