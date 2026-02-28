class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int cnt = 0;
        for(auto ch : s) {
            if(ch == '(' && cnt++ > 0) {
                res += ch;
            }
            if(ch == ')' && cnt-- > 1) {
                res += ch;
            }
        }

        return res;
    }
};