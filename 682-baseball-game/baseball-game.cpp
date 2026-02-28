class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i=0; i<operations.size(); i++) {
            string ch = operations[i];
            if(ch == "+") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.push(first);
                st.push(first+second);
            }
            else if(ch == "C") {
                st.pop();
            }
            else if(ch == "D") {
                int dbl = st.top();
                int newdbl = 2*dbl;
                st.push(newdbl);
            }
            else {
                int n = stoi(ch);
                st.push(n);
            }
        }

        int sum = 0;
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};