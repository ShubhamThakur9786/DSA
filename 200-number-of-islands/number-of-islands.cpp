class Solution {
public:
    void bfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>> &grid) {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        int r[] = {0, -1, 0, 1};
        int c[] = {-1, 0, 1, 0};

        while(!q.empty()) {
            int qrow = q.front().first;
            int qcol = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int nrow = qrow + r[i];
                int ncol = qcol + c[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
                        
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    ans++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return ans;
    }
};