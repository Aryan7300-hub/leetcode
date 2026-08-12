class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;

        for(char ch : s){
            if(ch == ')' &&  !st.empty() && st.top() == '('){
                st.pop();
            }else{
                st.push(ch);
            }
        }

        return st.size();
    }
};