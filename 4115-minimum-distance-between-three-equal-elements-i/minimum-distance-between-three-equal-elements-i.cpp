class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                for(int k=j+1; k<nums.size(); k++) {
                    if(nums[i] == nums[j] && nums[j] == nums[k]) {
                        int sum = abs(i-j) + abs(j-k) + abs(k-i);
                        ans = min(ans, sum);
                    }
                }
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};