class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n);
        long long curr = 0;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                curr++;
            } 
            else if (c == '*') {
                if (curr > 0) curr--;
            } 
            else if (c == '#') {
                curr *= 2;
            } 
            else { // '%'
                // length unchanged
            }

            len[i] = curr;
        }

        if (k >= curr) return '.';

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                if (k == len[i] - 1) {
                    return c;
                }
            }
            else if (c == '#') {
                long long prevLen = len[i] / 2;
                k %= prevLen;
            }
            else if (c == '%') {
                long long L = len[i];
                k = L - 1 - k;
            }

            // '*' requires no special handling
        }

        return '.';
    }
};