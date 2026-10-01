class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int>q;
        vector<bool>visited(n*n+1, false);

        q.push(1);
        visited[1] = true;
        int moves = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int curr = q.front();
                q.pop();

                if(curr == n*n)
                    return moves;
            
                for(int dice = 1; dice<=6; dice++){
                    int next = curr + dice;

                    if(next > n*n)
                        break;
                    
                    int r = n-1-(next-1)/n;
                    int c = (next-1)%n;

                    if((n-r) % 2 == 0)
                        c  = n-1-c;
                
                    if(board[r][c]!= -1)
                        next = board[r][c];
                
                    if(!visited[next]){
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};