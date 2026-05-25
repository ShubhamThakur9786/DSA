class Solution {
public:
    bool valid(vector<int>& nums, int p, int mid) {
        int result = 0;
        int n = nums.size();
        int i=0;
        while(i < n-1) {
            if(nums[i+1]-nums[i] <= mid) {
                result++;
                i+=2;
            }
            else {
                i++;
            }
        }
        return result >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums[n-1]-nums[0];

        int result = INT_MAX;

        while(left <= right) {
            int mid = left + (right-left)/2;
            if(valid(nums, p, mid)) {
                result = mid;
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }
        return result;
    }
};