class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i,j}, 0});
                    vis[i][j] = true;
                }
            }
        }
        vector<vector<int>> dist(n, vector<int>(m, 0));

        int r[] = {0, 1, 0, -1};
        int c[] = {-1, 0, 1, 0};
        
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dst = q.front().second;
            q.pop();
            dist[row][col] = dst;

            for(int i=0; i<4; i++) {
                int nrow = row+r[i];
                int ncol = col+c[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, dst+1});
                }
            }
        }
        return dist;
    }
};