class Solution {
public:
    int minLength(string s) {
        string str = "";

        for(char ch : s){
            if(!str.empty()){
                char last = str.back();
                if((last == 'A' && ch == 'B')|| (last == 'C' && ch == 'D')){
                    str.pop_back();
                    continue;
                }
            }
            str.push_back(ch);
        }

        return str.length();
    }
};