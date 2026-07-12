class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, l = 0, r;
        for(int i= 0; i<nums.size(); i++){
            sum+=nums[i];
        }
        for(int i = 0; i<nums.size(); i++){
            
            r = sum - l - nums[i];

            if(l == r) return i;

            l+=nums[i];
        }
        return -1;
    }
};