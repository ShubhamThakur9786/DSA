class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if(n <= 4) {
            return 0;
        }

        int result = INT_MAX;
        result = min(result, nums[n-1]-nums[3]);
        result = min(result, nums[n-4]-nums[0]);
        result = min(result, nums[n-2]-nums[2]);
        result = min(result, nums[n-3]-nums[1]);

        return result;
    }
};