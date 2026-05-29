class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int result = 0;
        int cummSum = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) cummSum += -1;
            cummSum += nums[i];
            if(mp.find(cummSum) != mp.end()) {
                result = max(result, i-mp[cummSum]);
            }
            else {
                mp[cummSum] = i;
            }
        }
        return result;
    }
};