class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        
        for(string val: tokens){
            if(val != "+" && val != "-" && val != "*" && val != "/"){
                st.push(stoi(val));
            }else{
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                switch(val[0]){
                    case '+' : 
                        st.push(a+b);
                        break;
                    case '-' : 
                        st.push(b-a);
                        break;
                    case '*' : 
                        st.push(a*b);
                        break;
                    case '/' : 
                        if(a == 0) return -1;
                        st.push(b/a);
                        break;
                }
            }
        }

        return st.top();
    }
};