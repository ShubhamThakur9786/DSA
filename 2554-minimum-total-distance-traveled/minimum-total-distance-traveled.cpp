class Solution {
public:
    long long solve(int i, int j, vector<int>& robot, vector<vector<int>>& factory, vector<vector<long long>>& dp) {
        if(i == robot.size()) return 0;
        if(j == factory.size()) return 1e18;

        if(dp[i][j] != -1) return dp[i][j];

        long long ans = solve(i, j+1, robot, factory, dp); // skip factory

        long long dist = 0;
        for(int k = 0; k < factory[j][1] && i + k < robot.size(); k++) {
            dist += abs(robot[i+k] - factory[j][0]);
            ans = min(ans, dist + solve(i + k + 1, j+1, robot, factory, dp));
        }

        return dp[i][j] = ans;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size(), m = factory.size();
        vector<vector<long long>> dp(n, vector<long long>(m, -1));

        return solve(0, 0, robot, factory, dp);
    }
};