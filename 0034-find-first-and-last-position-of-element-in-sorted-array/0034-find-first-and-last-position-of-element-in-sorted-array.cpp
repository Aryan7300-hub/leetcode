class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=-1, second=-1;
        int s=0, e=n-1, mid;
        while(s<=e){
            mid = s + (e-s)/2;
            if(nums[mid]==target){
                first = mid;
                e = mid-1;
            }else if(nums[mid] < target){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        s=0, e=n-1;
        while(s<=e){
            mid = s + (e-s)/2;
            if(nums[mid]==target){
                second = mid;
                s = mid+1;
            }else if(nums[mid] < target){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        vector<int>ans(2);
        ans[0] = first;
        ans[1] = second;
        return ans;
    }
};