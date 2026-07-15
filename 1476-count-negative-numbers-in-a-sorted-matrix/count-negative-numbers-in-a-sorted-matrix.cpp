class Solution {
public:
    int binarySearch(vector<int> &arr) {
        int st = 0;
        int end = arr.size()-1;
        int ans = arr.size();

        while(st <= end) {
            int mid = st + (end-st)/2;
            if(arr[mid] < 0) {
                ans = mid;
                end = mid-1;
            }
            else {
                st = mid+1;
            }
        }
        return arr.size()-ans;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++) {
            int count = binarySearch(grid[i]);
            ans += count;
        }
        return ans;
    }
};