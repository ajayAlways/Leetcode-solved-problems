class MinStack {
public:
    stack<int>v;
    stack<int>mini;
    
    MinStack() {
        stack<int>v;
        stack<int>mini;
    }
    
    void push(int val) {
        v.push(val);
        (mini.size()==0 || mini.top()>val) ? mini.push(val):mini.push(mini.top());
    }
    
    void pop() {
        v.pop();
        mini.pop();
    }
    
    int top() {
        return v.top();
    }
    
    int getMin() {
        return mini.top();
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