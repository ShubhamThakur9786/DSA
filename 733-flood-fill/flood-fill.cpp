class Solution {
public:
    void bfs(int sr, int sc, int color, vector<vector<bool>> &vis, vector<vector<int>>& image) {
        vis[sr][sc] = 1;
        int colr = image[sr][sc];
        image[sr][sc] = color;
        queue<pair<int, int>> q;
        q.push({sr, sc});

        int n = image.size();
        int m = image[0].size();

        int r[] = {0, -1, 0, 1};
        int c[] = {-1, 0, 1, 0};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int nrow = row+r[i];
                int ncol = col+c[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == colr && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }

        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        bfs(sr, sc, color, vis, image);
        return image;
    }
};