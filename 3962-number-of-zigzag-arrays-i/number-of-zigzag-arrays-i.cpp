class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> up(m, 0), down(m, 0);

        // length = 2
        for (int i = 0; i < m; i++) {
            up[i] = m - 1 - i; // choose larger value
            down[i] = i;       // choose smaller value
        }

        for (int len = 3; len <= n; len++) {
            vector<long long> newUp(m, 0), newDown(m, 0);

            // suffix sum of down
            long long suf = 0;
            for (int i = m - 1; i >= 0; i--) {
                newUp[i] = suf;
                suf = (suf + down[i]) % MOD;
            }

            // prefix sum of up
            long long pre = 0;
            for (int i = 0; i < m; i++) {
                newDown[i] = pre;
                pre = (pre + up[i]) % MOD;
            }

            up = move(newUp);
            down = move(newDown);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return ans;
    }
};