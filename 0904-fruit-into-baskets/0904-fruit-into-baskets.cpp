class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int,int>count;
        int left = 0, ans = 0;
        for(int right = 0; right<nums.size(); right++){
            count[nums[right]]++;

            while(count.size()>2){
                count[nums[left]]--;
                if(count[nums[left]] == 0){
                    count.erase(nums[left]);
                }
                left++;
            }
            
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};