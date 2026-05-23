class MinStack {
public:
    stack<int>st,ms;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            ms.push(val);
        }
        else if(val <= ms.top()){
            st.push(val);
            ms.push(val);

        }
        else st.push(val);
    }
    
    void pop() {
        if(ms.top() == st.top()){
            st.pop();
            ms.pop();
        }
        else st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return ms.top();
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