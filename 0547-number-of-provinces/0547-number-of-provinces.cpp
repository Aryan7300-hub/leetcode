class Solution {
public:
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int count = 0;

        

        for(int i = 0; i<isConnected.size(); i++){
            if(!visited[i]){
                dfs(isConnected, visited, i);
                count++;
            }
        }

        return count;
    }
private:
    void dfs(vector<vector<int>>&isConnect, vector<bool>&visited, int node){
        visited[node] = true;

        for(int i = 0; i<isConnect.size(); i++){
            if(isConnect[node][i] == 1 && !visited[i])
                dfs(isConnect, visited, i);
        }
    }
};