class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> str;
        stack<int> st;
        int j=0;
        for(int i=1; i<=n; i++) {
            if( j < target.size() && i == target[j]) {
                str.push_back("Push");
                st.push(i);
                j++;
            }
            else if(j < target.size()) {
                str.push_back("Push");
                str.push_back("Pop");
            }
        }

        return str;
    }
};