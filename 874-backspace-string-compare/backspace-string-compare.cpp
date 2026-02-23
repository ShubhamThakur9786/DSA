class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;

        for(int i=0; i<s.size(); i++) {
            if(s[i] != '#') {
                st1.push(s[i]);
            }
            else {
                if(!st1.empty()) {
                    st1.pop();
                }
            }
        }

        string str1 = "";
        while(!st1.empty()) {
            str1.push_back(st1.top());
            st1.pop();
        }

        for(int i=0; i<t.size(); i++) {
            if(t[i] != '#') {
                st2.push(t[i]);
            }
            else {
                if(!st2.empty()) {
                    st2.pop();
                }
            }
        }

        string str2 = "";
        while(!st2.empty()) {
            str2.push_back(st2.top());
            st2.pop();
        }

        if(str1 == str2) {
            return true;
        }
        else {
            return false;
        }
    }
};