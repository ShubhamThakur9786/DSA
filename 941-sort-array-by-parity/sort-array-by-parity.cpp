class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        while(left <= right) {
            if(nums[left]%2 == 0) {
                //even
                left++;
            }
            else if(nums[right]%2 == 1) {
                //odd
                right--;
            }
            else {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        return nums;
    }
};