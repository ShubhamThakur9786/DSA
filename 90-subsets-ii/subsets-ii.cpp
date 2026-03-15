class Solution {
public:
    void subset(vector<int> &arr, int idx, vector<vector<int>> &ans, vector<int> &temp) {
        ans.push_back(temp);
        for(int i=idx; i<arr.size(); i++) {
            if(i>idx && arr[i] == arr[i-1]) {
                continue;
            }
            temp.push_back(arr[i]);
            subset(arr, i+1, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int idx = 0;
        subset(nums, idx, ans, temp);
        return ans;
    }
};