class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j < k) {
                //skip duplicates
                int targ = -nums[i];
                int sum = nums[j]+nums[k];
                
                if(sum == targ) {
                    while(j < k && nums[j] == nums[j+1]) {
                        j++;
                    }
                    while(j < k && nums[k] == nums[k-1]) {
                        k--;
                    }
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(sum < targ) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        return ans;
    }
};