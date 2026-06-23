class Solution {
public:
    void dfs(int i, vector<bool> &vis, vector<vector<int>> &isConnected) {

        vis[i] = true;
        for(int j=0; j<isConnected.size(); j++) {
            if(isConnected[i][j] == 1 && !vis[j]) {
                dfs(j, vis, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        vector<bool> vis(size, false);

        int countProvince = 0;
        for(int i=0; i<vis.size(); i++) {
            if(!vis[i]) {
                countProvince++;
                dfs(i, vis, isConnected);
            }
        }
        return countProvince;
    }
};