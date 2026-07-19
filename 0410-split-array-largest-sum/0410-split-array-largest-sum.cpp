class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        if (k > nums.size()) return -1;
        int low = 0, high = 0, ans = -1;
        for(int a : nums){
            low = max(low, a);
            high+= a;
        }
        while(low<=high){
            int mid = low + (high - low)/2;
            if(canbe(nums, k, mid)){
                ans= mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
private:
    bool canbe(vector<int>&arr, int k, int m){
        int c = 1, sum = 0;
        for(int s : arr){
            if(sum+s <= m){
               sum+=s;
            }else{
                c++;
                sum = s;
            }
        }
        return c<=k;
    }
};