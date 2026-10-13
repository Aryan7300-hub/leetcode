class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<long long>sqt(n);

        for(int i = 0; i < n; i++){
            sqt[i] = (long long)nums[i] * nums[i]; 
        }

        sort(sqt.begin(), sqt.end());
        
        long long ans = 0;
        int k = n/2;

        for(int i = 0; i < k; i++){
            ans -= sqt[i];
        }
        for(int i = k; i < n; i++){
            ans += sqt[i];
        }

        return ans;
    }
};