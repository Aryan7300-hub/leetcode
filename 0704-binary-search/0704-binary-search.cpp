class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return binary(nums, 0, n-1, target);
    }
private:
    int binary(vector<int>&nums, int left, int right, int target){
        if(left>right) return -1;
        int mid = left + (right-left)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] > target){
            return binary(nums, left, mid-1, target);
        }else{
            return binary(nums, mid+1, right, target);
        }
    }
};