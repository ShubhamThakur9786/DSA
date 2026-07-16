class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        //gcd(max[i], nums[i]) 
        vector<int> mx(nums.size(), 0);
        int maxi = INT_MIN;
        vector<int> prefixGcd;

        for(int i=0; i<nums.size(); i++) {
            maxi = max(nums[i], maxi);
            mx[i] = maxi;
            prefixGcd.push_back(gcd(mx[i], nums[i]));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int st = 0;
        int end = prefixGcd.size()-1;
        long long ans = 0;
        while(st < end) {
            ans += gcd(prefixGcd[st], prefixGcd[end]);
            st++;
            end--;
        }
        return ans;
    }
};