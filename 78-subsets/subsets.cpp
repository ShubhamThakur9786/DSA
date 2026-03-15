class Solution {
public:
    void subset(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int idx) {
        if(idx >= nums.size()) {
            ans.push_back(temp);
            return;
        }
        //include
        temp.push_back(nums[idx]);
        subset(nums, ans, temp, idx+1);
        //exclude
        temp.pop_back();
        subset(nums, ans, temp, idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int idx = 0;
        subset(nums, ans, temp, idx);
        return ans;
    }
};