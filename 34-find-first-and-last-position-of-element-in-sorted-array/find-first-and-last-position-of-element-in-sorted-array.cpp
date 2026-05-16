class Solution {
public:
    void binarySearchLeft(vector<int> nums, int target, int &left) {
        int l = 0;
        int r = nums.size()-1;
        while(l <= r) {
            int mid = (l+r)/2;
            if(nums[mid] == target) {
                left = mid;
                r = mid-1;
            }
            else if(nums[mid] < target) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
    }
    void binarySearchRight(vector<int> nums, int target, int &right) {
        int l = 0;
        int r = nums.size()-1;
        while(l <= r) {
            int mid = (l+r)/2;
            if(nums[mid] == target) {
                right = mid;
                l = mid+1;
            }
            else if(nums[mid] < target) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = -1;
        int right = -1;
        vector<int> ans;
        binarySearchLeft(nums, target, left);
        binarySearchRight(nums, target, right);
        
        ans.push_back(left);
        ans.push_back(right);
        return ans;
    }
};