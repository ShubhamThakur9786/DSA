class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int candidate = 0;
        // int count = 0;
        // for(int num : nums) {
        //     if(count == 0) {
        //         candidate = num;
        //     }
        //     count += (num == candidate) ? 1 : -1;
        // }

        // return candidate;
        int n = nums.size();

        unordered_map<int, int> mp;

        for(int n : nums) {
            mp[n]++;
        }

        for(auto it : mp) {
            if(it.second > n/2) {
                return it.first;
            }
        }
        return -1;
    }
};