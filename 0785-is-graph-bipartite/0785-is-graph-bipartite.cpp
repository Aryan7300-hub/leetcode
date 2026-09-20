class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);

        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                if(!dfs(graph, visited, 1, i))
                    return false;
            }
        }
        return true;
    }
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int col, int node){
        visited[node] = col;

        for(int i: graph[node]){
            if(visited[i] == 0){
                if(!dfs(graph, visited, -col, i)){
                    return false;
                }
            }
            else{
                if(visited[i] == col)
                return false;
            }
        }
        return true;
    }  
};