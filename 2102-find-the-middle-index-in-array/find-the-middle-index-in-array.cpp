class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();

        for(int it : nums) {
            totalSum += it;
        }
        
        int leftSum = 0;
        int rightSum = 0;
        for(int i=0; i<n; i++) {
            rightSum = totalSum-nums[i]-leftSum;
            if(leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};