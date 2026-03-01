class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        for(int num : nums2) {
            while(!st.empty() && st.top() < num) {
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        while(!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        vector<int> res;
        for(int i=0; i<nums1.size(); i++) {
            res.push_back(mp[nums1[i]]);
        }

        return res;
    }
};