class Solution {
public:
    long long find(vector<int>& nums, vector<int>& cost, int target) {
        long long res = 0;
        for(int i=0; i<nums.size(); i++) {
            res += (long long)abs(target-nums[i])*(cost[i]);
        }
        return res;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans = INT_MAX;
        long long l = *min_element(nums.begin(), nums.end());
        long long r = *max_element(nums.begin(), nums.end());

        while(l <= r) {
            long long mid = l+(r-l)/2;
            long long cost1 = find(nums, cost, mid);
            long long cost2 = find(nums, cost, mid+1);
            ans = min(cost1, cost2);
            if(cost1 < cost2) {
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }

        if(ans == INT_MAX) return 0;

        return ans;
    }
};