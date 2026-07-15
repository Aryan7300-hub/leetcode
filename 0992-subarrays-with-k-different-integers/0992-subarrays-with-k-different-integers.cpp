class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
    int atmost(vector<int>nums, int k){
       int count = 0, left = 0;
       unordered_map<int, int>mpp;
       for(int right = 0; right<nums.size(); right++){
        mpp[nums[right]]++;
        while(mpp.size()>k){
            mpp[nums[left]]--;
            if(mpp[nums[left]] == 0){
                mpp.erase(nums[left]);
            }
            left++;
        }
        count += right-left+1;
       }
       return count;
    }
};