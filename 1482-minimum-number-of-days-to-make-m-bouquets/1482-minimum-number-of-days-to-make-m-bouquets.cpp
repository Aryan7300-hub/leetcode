class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long)m*k > bloomDay.size()) return -1;
        int low = bloomDay[0], high = 0, ans=-1;
        for(int f : bloomDay){
            low = min(low, f);
            high = max(high, f);
        }
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canbe(bloomDay, m, k, mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
private:
    bool canbe(vector<int>&arr, int m, int k , int d){
        int c = 0, t = 0;
        for(int f : arr){
            if(f <= d){
                t++;
                if(t == k){
                    c++;
                    t = 0;
                }
            }else{
                t = 0;
            }
        }
        return c >= m;
    }
};