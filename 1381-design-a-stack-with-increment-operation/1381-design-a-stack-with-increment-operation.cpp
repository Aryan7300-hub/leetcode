class CustomStack {
public:
    vector<int>st;
    int idx = -1;
    int  n;
    CustomStack(int maxSize) {
        n = maxSize;
        st.resize(maxSize);
    }
    
    void push(int x) {
        if(idx == n-1) return;
        idx++;
        st[idx] = x;
    }
    
    int pop() {
        if(idx == -1) return -1;
        int val = st[idx];
        idx--;
        return val;
    }
    
    void increment(int k, int val) {
        int limit = min(k, idx+1);
        for(int i = 0; i<limit ; i++){
            st[i] += val; 
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */