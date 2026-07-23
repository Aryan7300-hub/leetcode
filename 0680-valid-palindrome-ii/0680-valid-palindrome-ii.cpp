class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left<right){
            if(s[left]!=s[right]){
               return func(s, left+1, right) || func(s, left, right-1);
            }
            left++;
            right--;
        }
        return true;
    }
private:
    bool func(string &s, int left, int right){
        while(left<right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};