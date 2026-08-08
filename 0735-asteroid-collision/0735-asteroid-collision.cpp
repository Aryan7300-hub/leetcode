class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int>ans;
        stack<int>s;

        for(int i = 0; i<n; i++){
            int num = asteroids[i];
            while(!s.empty() && s.top()>0 && num<0 && s.top() < -num){
                s.pop();
            }
            if(!s.empty() && num<0 && s.top()>0){
                if(s.top() == -num){
                    s.pop();
                }
            }else{
                s.push(num);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};