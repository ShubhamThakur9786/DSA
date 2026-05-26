class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;

        int count1 = 0;
        int count2 = 0;
        int majElem1 = NULL;
        int majElem2 = NULL;

        for(int i=0; i<nums.size(); i++) {
            if(majElem1 == nums[i]) {
                count1++;
            }
            else if(majElem2 == nums[i]) {
                count2++;
            }
            else if(count1 == 0) {
                majElem1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0) {
                majElem2 = nums[i];
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        //verification;
        int majElem1count = 0;
        int majElem2count = 0;
        for(int num : nums) {
            if(majElem1 == num) {
                majElem1count++;
            }
            else if(majElem2 == num) {
                majElem2count++;
            }
        }
        if(majElem1count > nums.size()/3) {
            ans.push_back(majElem1);
        }
        if(majElem2count > nums.size()/3) {
            ans.push_back(majElem2);
        }
        return ans;
    }
};