class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>>pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for(int i = 0; i<m; i++){
            dfs(i, 0, heights, pacific);
            dfs(i, n-1, heights, atlantic);
        }
        for(int j = 0; j<n; j++){
            dfs(0, j, heights, pacific);
            dfs(m-1, j, heights, atlantic);
        }

        vector<vector<int>> ans;
        for(int i = 0; i<m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
private:
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited){
        int m = heights.size();
        int n = heights[0].size();
        visited[r][c] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i = 0; i<4; i++){

            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= m || nc < 0 || nc >= n || 
                visited[nr][nc] || heights[nr][nc] < heights[r][c] ){
                    continue;
                }
            
            dfs(nr, nc, heights, visited);
        }
    }
};