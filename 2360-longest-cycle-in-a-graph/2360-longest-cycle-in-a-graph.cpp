class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>visited(n, 0); // 0 = unvisited, 1 = visiting, 2 = visited 
        vector<int>depth(n, 0);
        int result = -1;

        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                dfs(edges, visited, depth, 0, i, result);
            }
        }

        return result;
    }
private:
    void dfs(vector<int>& edges, vector<int>& visited, vector<int>& depth, int d, int node, int& result){
        if(node == -1) return;

        if(visited[node] == 0){
            visited[node] = 1;
            depth[node] = d;
            dfs(edges, visited, depth, d+1, edges[node], result);
            visited[node] = 2;
        }else if(visited[node] == 1){
            result = max(result, d - depth[node]);
        }
    }
};