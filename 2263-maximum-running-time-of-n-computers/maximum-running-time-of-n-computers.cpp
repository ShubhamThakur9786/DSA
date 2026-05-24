class Solution {
public:
    bool possible(int n, vector<int>& batteries, long long mid) {
        long long available = 0;

        for (int bt : batteries) {
            available += min((long long)bt, mid);
        }

        return available >= n * mid;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long totalSum = 0;
        long long st = *min_element(batteries.begin(), batteries.end());

        for(int bt : batteries) {
            totalSum += bt;
        }
        long long end = totalSum/n;
        long long ans = 0;
        while(st <= end) {
            long long mid = st + (end-st)/2;
            if(possible(n, batteries, mid)) {
                ans = mid;
                st = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        return ans;
    }
};