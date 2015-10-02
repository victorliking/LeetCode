/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
public:
    stack<int> s1;
    stack<int> s2;
    void push(int x) {
        s1.push(x);
        if(s2.empty()||x<=getMin()) s2.push(x);
    }

    void pop() {
        if(s1.top()==getMin()) s2.pop();
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }
};