class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] == 1 || grid[m-1][n-1] == 1)
            return -1;

        vector<vector<int>>dist(m, vector<int>(n, 0));
        queue<pair<int,int>>q;
        int path = 0;

        q.push({0, 0});
        dist[0][0] = 1;

        /*for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }*/

        int distances[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {1, -1}, {1, 1} , {-1, -1}};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            if(r == m-1 && c == n-1)
                return dist[r][c];

            for(auto& dir : distances){
                int nr = r + dir[0];
                int nc = c + dir[1];
                if(nr>=0 && nr<n && nc>=0 && nc<n && dist[nr][nc] == 0 && grid[nr][nc] == 0){
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return -1;
    }
};