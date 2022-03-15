// Link: https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {

    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {

        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        int elem = s2.top();
        s2.pop();

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

        return elem;

    }

    int peek() {

        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        int elem = s2.top();

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

        return elem;
    }

    bool empty() {

        return s1.empty();

    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */