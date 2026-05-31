class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroCnt = 0;
        int oneCnt = 0;
        int twoCnt = 0;

        for(int n : nums) {
            if(n == 0) 
                zeroCnt++;
            else if(n == 1) 
                oneCnt++;
            else 
                twoCnt++;
        }

        int i=0;
        while(zeroCnt) {
            nums[i] = 0;
            zeroCnt--;
            i++;
        }
        while(oneCnt) {
            nums[i] = 1;
            oneCnt--;
            i++;
        }
        while(twoCnt) {
            nums[i] = 2;
            twoCnt--;
            i++;
        }
    }
};