class Solution {
public:
    int sum(int n) {
        int ans = 0;
        while(n) {
            int rem = n%10;
            ans += rem;
            n = n/10;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];
            int s = sum(num);
            nums[i] = s;
        }
        return *min_element(nums.begin(), nums.end());
    }
};