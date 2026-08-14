class CustomStack {
public:
    vector<int>st, inc;
    int values;
    int  n;
    CustomStack(int maxSize) {
        n = maxSize;
        st.resize(maxSize);
        inc.resize(maxSize);
        values = -1;
    }
    
    void push(int x) {
        if(values == n-1) return;
        values++;
        st[values] = x;
    }
    
    int pop() {
        if(values == -1) return -1;
        int result = st[values]+ inc[values];
        if(values>0){
            inc[values-1]+=inc[values];
        }
        inc[values] = 0;
        values--;
        return result;
    }
    
    void increment(int k, int val) {
        int index = min(k-1, values);
        if(index>=0){
            inc[index]+=val;
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