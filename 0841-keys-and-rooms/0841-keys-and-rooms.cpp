class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n, false);

        dfs(rooms, visited,0);

        for(bool v : visited){
            if(!v)
                return false;
        }
        return true;
    }
private:    
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int node){
        visited[node] = true;

        for(int i : rooms[node]){
            if(!visited[i])
                dfs(rooms,visited,i);
        }
    }
};