class MinStack {
public:
    stack<int>st;
    stack<int>minst;

    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if(minst.empty()){
            minst.push(val);
        }else{
            minst.push(min(val, minst.top()));
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
            minst.pop();
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if(minst.empty()) return -1;
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */