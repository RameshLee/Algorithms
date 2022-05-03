// Link: https://leetcode.com/problems/min-stack/

// Algo: Keep track of min values at every point on the second stack.

class MinStack {
public:
    stack<int> Stack;
    stack<int> minStack;

    MinStack() {

    }

    void push(int val) {
        if (minStack.empty() || val < minStack.top()) {
            minStack.push(val);
        }
        else {
            minStack.push(minStack.top());
        }
        Stack.push(val);
    }

    void pop() {
        Stack.pop();
        minStack.pop();
    }

    int top() {
        return Stack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */