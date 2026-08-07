class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>list;
        vector<int>ll;
        sub(0, ll, list, nums);

        return list;
    }
private:
    void sub(int i, vector<int>&ll , vector<vector<int>>&list, vector<int>&nums){
        if(i == nums.size()){
            list.push_back(ll);
            return;
        }

        //include
        ll.push_back(nums[i]);
        sub(i+1, ll, list, nums);

        //exclude
        ll.pop_back();
        sub(i+1, ll, list, nums);
    }
};