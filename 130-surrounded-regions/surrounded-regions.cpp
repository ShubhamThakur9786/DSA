class Solution {
public:
    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>>& board) {
        vis[row][col] = true;
        int n = board.size();
        int m = board[0].size();
        
        int r[] = {0, 1, 0, -1};
        int c[] = {-1, 0, 1, 0};

        for(int i=0; i<4; i++) {
            int nrow = row + r[i];
            int ncol = col + c[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board);
            } 
        }


    }
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if((i == 0 || i == n-1 || j == 0 || j == m-1) && board[i][j] == 'O') {
                    //boundry
                    if(!vis[i][j]) {
                        dfs(i, j, vis, board);
                    }
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

    }
};