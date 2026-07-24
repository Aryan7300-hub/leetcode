class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        unordered_map<char, int>mp;
        for(char ch : s1){
            mp[ch]++;
        }
        int left = 0, count = s1.length();
        for(int right = 0; right<s2.size(); right++){
            char ch = s2[right];
            int val = mp[ch];
            if(mp[ch] > 0) count--;
            mp[ch] = val -1;

            if(count == 0) return true;
            if(right-left+1 == s1.length()){
                char leftch = s2[left];
                int leftval = mp[leftch];
                if(leftval >= 0) count++;
                mp[leftch] = leftval+1;
                left++;
            }
        }
        return false;
    }
};