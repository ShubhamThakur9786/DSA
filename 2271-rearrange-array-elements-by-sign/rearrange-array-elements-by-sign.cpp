class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posIndx = 0;
        int negIndx = 1;
        vector<int> ans(nums.size());
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < 0) {
                //odd indx
                ans[negIndx] = nums[i];
                negIndx+=2;
            }
            else {
                ans[posIndx] = nums[i];
                posIndx+=2;
            }
        }

        return ans;
    }
};