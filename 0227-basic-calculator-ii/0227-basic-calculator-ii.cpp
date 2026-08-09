class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int num = 0;
        char op = '+';

        for(int i = 0; i<=s.length(); i++){
            char ch = (i == s.length())? '+' : s[i];

            if(isdigit(ch)){
                num = num*10 + (ch-'0');
            }else if(ch != ' '){
                if(op == '+') st.push(num);
                else if(op == '-') st.push(-num);
                else if(op == '*'){
                    int top = st.top();
                    st.pop();
                    st.push(top*num);
                }
                else if(op == '/'){
                    int top = st.top();
                    st.pop();
                    st.push(top/num);
                }
                op = ch;
                num = 0;
            }
            
        }

        int ans = 0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        return ans;
    }
};