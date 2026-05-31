class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str1 = "";
        string str2 = "";

        for(auto c1 : s) {
            if(c1 != '#') {
                str1.push_back(c1);
            }
            else {
                if(str1.size() >= 1) {
                    str1.pop_back();
                }
            }
        }
        for(auto c2 : t) {
            if(c2 != '#') {
                str2.push_back(c2);
            }
            else {
                if(str2.size() >= 1) {
                    str2.pop_back();
                }
            }
        }

        return str1 == str2;
    }
};


        // stack<char> st1;
        // stack<char> st2;

        // for(int i=0; i<s.size(); i++) {
        //     if(s[i] != '#') {
        //         st1.push(s[i]);
        //     }
        //     else {
        //         if(!st1.empty()) {
        //             st1.pop();
        //         }
        //     }
        // }

        // string str1 = "";
        // while(!st1.empty()) {
        //     str1.push_back(st1.top());
        //     st1.pop();
        // }

        // for(int i=0; i<t.size(); i++) {
        //     if(t[i] != '#') {
        //         st2.push(t[i]);
        //     }
        //     else {
        //         if(!st2.empty()) {
        //             st2.pop();
        //         }
        //     }
        // }

        // string str2 = "";
        // while(!st2.empty()) {
        //     str2.push_back(st2.top());
        //     st2.pop();
        // }

        // if(str1 == str2) {
        //     return true;
        // }
        // else {
        //     return false;
        // }