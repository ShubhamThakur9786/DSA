class Solution {
public:
    bool isGood(vector<int>& nums) {
        int size = nums.size();

        sort(nums.begin(), nums.end());

        // check sequence 1,2,3,...,size-1
        for(int i = 0; i < size - 1; i++) {
            if(nums[i] != i + 1) {
                return false;
            }
        }

        // last element should also be size-1
        return nums[size - 1] == size - 1;
    }
};