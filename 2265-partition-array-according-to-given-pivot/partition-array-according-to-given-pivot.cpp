class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        vector<int> left;
        vector<int> equal;
        vector<int> right;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < pivot) {
                left.push_back(nums[i]);
            }
            else if(nums[i] == pivot) {
                equal.push_back(nums[i]);
            }
            else {
                right.push_back(nums[i]);
            }
        }
        int i=0;
        while(i < left.size()) {
            ans.push_back(left[i]);
            i++;
        }
        int k=0;
        while(k < equal.size()) {
            ans.push_back(equal[k]);
            k++;
        }
        int j=0;
        while(j < right.size()) {
            ans.push_back(right[j]);
            j++;
        }
        return ans;
    }
};