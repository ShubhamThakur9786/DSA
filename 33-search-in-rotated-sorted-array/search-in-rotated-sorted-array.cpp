class Solution {
public:
    int minIdx(vector<int> &nums) {
        int s = 0;
        int e = nums.size() - 1;

        while(s < e) {
            int mid = s + (e - s) / 2;

            if(nums[mid] < nums[e]) {
                e = mid;
            }
            else {
                s = mid + 1;
            }
        }

        return s;
    }

    int binarySearch(vector<int> &nums, int st, int end, int target) {
        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {

        int pivotIdx = minIdx(nums);

        int ans = binarySearch(nums, 0, pivotIdx-1, target);

        if(ans != -1) {
            return ans;
        }

        return binarySearch(nums, pivotIdx, nums.size() - 1, target);
    }
};