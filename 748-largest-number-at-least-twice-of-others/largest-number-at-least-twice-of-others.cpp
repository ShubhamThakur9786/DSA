class Solution {
public:
    int maxi(vector<int> &nums) {
        int maxii = INT_MIN;
        int idx = -1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > maxii) {
                maxii = nums[i];
                idx = i;
            }
        }
        return idx;
    }
    int dominantIndex(vector<int>& nums) {
        int largestIdx = maxi(nums);
        for(int i=0; i<nums.size(); i++) {
            if(largestIdx != i && nums[largestIdx] < 2*nums[i]) {
                return -1;
            }
        }

        return largestIdx;
    }
};