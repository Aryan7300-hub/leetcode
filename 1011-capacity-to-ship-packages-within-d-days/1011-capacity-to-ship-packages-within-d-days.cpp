class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;
        int ans;
        for(int w : weights){
            low = max(low, w);
            high+=w;
        }
        while(low<=high){
            int mid = low + (high-low)/2;
            if(Canbe(weights, days, mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
private:
    bool Canbe(vector<int>&weights, int days, int k){
        int d = 1, sum = 0;
        for(int w : weights){
            sum+=w;
            if(sum>k){
                d++;
                sum = w;
            }
        }
        return d <= days;
    }
};