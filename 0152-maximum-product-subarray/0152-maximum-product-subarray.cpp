class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m = INT_MIN, r = 1;
        for(int i = 0; i<nums.size(); i++){
            r*= nums[i];
            m = max(r, m);
            if(r == 0){
                r = 1;
            }
        }
        r = 1;
        for(int i = nums.size()-1; i>=0; i--){
            r*=nums[i];
            m = max(r,m);
            if(r == 0) 
                r = 1;
        }
        return m;
    }
};