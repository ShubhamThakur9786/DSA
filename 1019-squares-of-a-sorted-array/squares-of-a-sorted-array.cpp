class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        vector<int> temp(nums.size());
        
        for(int i=nums.size()-1; i>=0; i--) {
            if(abs(nums[left]) < abs(nums[right])) {
                temp[i] = nums[right]*nums[right];
                right--;
            }
            else {
                temp[i] = nums[left]*nums[left];
                left++;
            }
        }
        return temp;
    }
};