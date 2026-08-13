class MinStack {
public:
    stack<long long>st;
    long long minVal;

    MinStack() {}
    
    void push(int x) {
        if(st.empty()){
            st.push(x);
            minVal = x;
        }else if(x < minVal){
            st.push(2LL * x - minVal);
            minVal = x;
        }else{
            st.push(x);
        }
    }
    
    void pop() {
        if(st.empty()) return;

        long long top = st.top();
        st.pop();
        if(top < minVal){
            minVal = 2* minVal - top;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        
        long long top = st.top();
        return (top < minVal)? minVal: top;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return minVal;
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