class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i<m; i++){
            if(board[i][0] == 'O')
                bfs(board, i, 0);

            if(board[i][n-1] == 'O')
                bfs(board, i, n-1);
        }
        for(int j = 0; j<n; j++){
            if(board[0][j] == 'O')
                bfs(board, 0, j);

            if(board[m-1][j] == 'O')
                bfs(board, m-1, j);
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
private:
    void bfs(vector<vector<char>>& board, int row, int col){
        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>>q;
        q.push({row, col});
        board[row][col] = '#';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i<4; i++){

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc] == 'O'){
                    board[nr][nc] = 'X';
                    bfs(board, nr, nc);

                    q.push({nr, nc});
                }
            }
        }
    }
};