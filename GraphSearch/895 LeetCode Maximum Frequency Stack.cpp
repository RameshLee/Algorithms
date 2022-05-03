// Link: https://leetcode.com/problems/maximum-frequency-stack/

//In PQ, first, the max heap based ordering is decided by frequency and then by count, all this is implicitly done by C++

class FreqStack {
public:
    unordered_map<int,int> freq;
    priority_queue<pair<int,pair<int,int>>> pq; //freq, position, value
    int pos = 0;

    FreqStack() {

    }

    void push(int val) {
        pq.push(make_pair(++freq[val], make_pair(++pos,val)));
    }

    int pop() {
        int val = pq.top().second.second; pq.pop();
        freq[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */