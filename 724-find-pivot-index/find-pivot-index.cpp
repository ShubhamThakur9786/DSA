class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int totalSum = 0;
        for(int i=0; i<nums.size(); i++) {
            totalSum += nums[i];
        }

        int currSum = 0;
        for(int i=0; i<nums.size(); i++) {
            currSum += nums[i];
            int temp = totalSum;
            temp -= currSum;

            if(currSum - nums[i] == temp) {
                return i;
            }
        }

        return -1;

    }

};