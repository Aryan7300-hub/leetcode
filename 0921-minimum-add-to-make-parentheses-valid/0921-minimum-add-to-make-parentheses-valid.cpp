class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int count = 0;

        for(char ch : s){
            if(ch == ')' &&  !st.empty() && st.top() == '('){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        while(!st.empty()){
            count++;
            st.pop();
        }

        return count;
    }
};