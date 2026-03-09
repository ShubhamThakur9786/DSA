class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st; //store indices
        vector<int> ans(prices.size());
        for(int i=0; i<prices.size(); i++) {
            ans[i] = prices[i];
            while(!st.empty() && prices[st.top()] >= prices[i]) {
                ans[st.top()] = prices[st.top()] - prices[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};