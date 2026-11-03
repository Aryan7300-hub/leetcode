class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int m = nums[0];
        for(int num : nums){
            sum+=num;
            m = max(m, num);
        }

        return nums.size()*m - sum;
    }
};