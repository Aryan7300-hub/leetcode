class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, min_count = INT_MAX, sum = 0;
        for(int right = 0; right<nums.size(); right++){
            sum+= nums[right];
            while(sum >= target){
                min_count = min(min_count, right-left+1);
                sum -= nums[left];
                left++;
            }
        }
        return min_count == INT_MAX ? 0 : min_count;
    }
};