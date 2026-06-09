class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans = 0;
        int mini = *min_element(nums.begin(), nums.end());
        int  maxi = *max_element(nums.begin(), nums.end());

        int diff = maxi-mini;
        
        for(int i=0; i<k; i++) {
            ans += diff;
        }
        return ans;
    }
};