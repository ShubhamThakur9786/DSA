class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;

        for(int i=1; i<arr.size(); i++) {
            minDiff = min(minDiff, arr[i]-arr[i-1]);
        }

        vector<vector<int>> ans;
        for(int i=1; i<arr.size(); i++) {
            int diff = arr[i]-arr[i-1];
            if(minDiff == diff) {
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};