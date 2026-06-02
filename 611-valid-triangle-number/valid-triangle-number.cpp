class Solution {
public:
    int bs(vector<int>& nums, int l, int r, int sum) {
        
        int ans = 0;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(sum > nums[mid]) {
                ans = mid;
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return ans;
    }
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int count = 0;
        for(int i=0; i<n-2; i++) {
            for(int j=i+1; j<n-1; j++) {
                int sum = nums[i]+nums[j];
                int l = j+1;
                int r = n-1;
                int k = bs(nums, l, r, sum);
                if(k != 0) {
                    count += k-j;
                }
            }
        }
        return count;
    }
};