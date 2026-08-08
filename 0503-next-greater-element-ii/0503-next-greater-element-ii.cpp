class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, -1);
        stack<int>s;

        for(int i =2* n-1; i>=0; i--){

            int num = nums[i%n];
            while(!s.empty() && s.top() <= num){
                s.pop();
            }
            if(i<n && !s.empty()){
                ans[i] = s.top();
            }
            s.push(num);
        }
        return ans;
    }
};