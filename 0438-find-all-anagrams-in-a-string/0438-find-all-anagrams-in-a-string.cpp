class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>res;
        if(s.length() < p.length()) return res;
        unordered_map<char, int>mp;

        for(char c: p){
            mp[c]++;
        }
        int left = 0, count = p.length();
        for(int right = 0; right<s.length(); right++){
            char ch = s[right];

            int val = mp[ch];
            if(val>0) count--;
            mp[ch] = val-1;

            if(right-left+1 > p.length()){
                char leftch = s[left];

                int leftval = mp[leftch];
                if(leftval >= 0) count++;
                mp[leftch] = leftval + 1;

                left++;
            }
            if(count == 0){
                res.push_back(left);
            }
        }
        return res;
    }
};