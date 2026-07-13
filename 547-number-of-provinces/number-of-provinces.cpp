class Solution {
public:
    void dfs(vector<vector<int>> &adjls, vector<bool> &vis, int st) {
        vis[st] = true;

        for(auto it : adjls[st]) {
            if(!vis[it]) {
                dfs(adjls, vis, it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjls(n+1);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i != j && isConnected[i][j] == 1) {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }

        int count = 0;
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                count++;
                dfs(adjls, vis, i);
            }
        }

        return count;
    }
};