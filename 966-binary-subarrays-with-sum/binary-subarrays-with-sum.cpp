class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int currSum = 0;
        int result = 0;
        for(int i=0; i<n; i++) {
            currSum += nums[i];
            int diff = currSum-goal;
            if(mp.find(diff) != mp.end()) {
                result += mp[diff];
            }
            mp[currSum]++;
        }
        return result;
    }
};