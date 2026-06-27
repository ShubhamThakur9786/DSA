class Solution {
public:
    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<int>>& grid) {
        vis[row][col] = true;
        int n = grid.size();
        int m = grid[0].size();

        int r[] = {0, 1, 0, -1};
        int c[] = {-1, 0, 1, 0};

        for(int i=0; i<4; i++) {
            int nrow = row + r[i];
            int ncol = col + c[i];

            if(nrow >= 0 && nrow < n-1 && ncol >= 0 && ncol < m-1 && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, vis, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if((i == 0 || i == n-1 || j == 0 || j == m-1) && (grid[i][j] == 1)) {
                    if(!vis[i][j]) {
                        dfs(i, j, vis, grid);
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};