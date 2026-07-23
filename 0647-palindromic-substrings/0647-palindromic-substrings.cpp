class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int  i =0; i<s.size(); i++){
           count+= ispal(s, i, i); // odd
           count+= ispal(s, i, i+1); // e
        }
        return count;
    }
private:
    int ispal(string &s, int left, int right){
        int count=0;
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }
};