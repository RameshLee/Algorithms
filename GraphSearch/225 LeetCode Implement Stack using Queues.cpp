// Link: https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
private: queue<int> q, q2;
public:
    void push(int x) {
        q.push(x);
    }

    int pop() {
        while (q.size() > 1) q2.push(q.front()), q.pop();
        int val = q.front(); q.pop();
        while (!q2.empty()) q.push(q2.front()), q2.pop();
        return val;
    }

    int top() {
        while (q.size() > 1) q2.push(q.front()), q.pop();
        int val = q.front();
        q2.push(q.front()), q.pop();
        while (!q2.empty()) q.push(q2.front()), q2.pop();
        return val;
    }

    bool empty() {
        return (q.empty()) ? true : false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */