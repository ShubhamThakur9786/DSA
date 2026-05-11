class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];
            string str = to_string(num);
            for(int i=0; i<str.size(); i++) {
                int n = (str[i]-'0');
                ans.push_back(n);
            }
        }
        return ans;
    }
};