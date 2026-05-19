class Solution {
public:
    int findPivot(vector<int> nums) {
        int l = 0;
        int r = nums.size()-1;

        while(l < r) {
            //skips duplicate from left and right
            while(l < r && nums[l] == nums[l+1]) {
                l++;
            }
            while(r > l && nums[r] == nums[r-1]) {
                r--;
            }
            int mid = l+(r-l)/2;
            if(nums[mid] > nums[r]) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        return r;
    }

    bool bS(vector<int> &nums, int st, int end, int target) {
        while(st <= end) {
            int mid = st+(end-st)/2;
            if(nums[mid] == target) {
                return true;
            }
            else if(nums[mid] < target) {
                st = mid+1;
            }
            else {
                end = mid-1;
            }
        }

        return false;
    }
    bool search(vector<int>& nums, int target) {
        int pivotIdx = findPivot(nums);

        if(bS(nums, 0, pivotIdx-1, target)) {
            return true;
        }
        return bS(nums, pivotIdx, nums.size()-1, target);
    }
};