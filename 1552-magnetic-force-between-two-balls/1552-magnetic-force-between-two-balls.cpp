class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int high = position.back() - position.front();
        int ans;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canplace(position, m , mid)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
private:
    bool canplace(vector<int>&arr, int m, int dist){
        int c = 1;
        int last = arr[0];
        for(int i =1; i<arr.size(); i++){
            if(arr[i] - last >= dist){
                c++;
                last = arr[i];
            }
        }
        return c>=m;
    }
};