class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> rightSmallest(heights.size());
        vector<int> leftSmallest(heights.size());

        stack<int> st;

        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                //found smallest elemnt store index of this elem in rightSmallest;
                rightSmallest[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) {
            rightSmallest[st.top()] = n;
            st.pop();
        }

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                leftSmallest[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) {
            leftSmallest[st.top()] = -1;
            st.pop();
        }

        int maxi = 0;
        for(int i=0; i<n; i++) {
            int area = heights[i]*(rightSmallest[i] - leftSmallest[i] - 1);
            maxi = max(maxi, area);
        }

        return maxi;

    }
};