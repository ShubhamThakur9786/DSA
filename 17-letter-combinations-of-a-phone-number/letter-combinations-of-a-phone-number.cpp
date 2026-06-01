class Solution {
public:
    void solve(int idx, vector<string> &ans, string &digits, string temp, unordered_map<char, string> mp) {
        if(idx >= digits.size()) {
            ans.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];
        for(int i=0; i<str.size(); i++) {
            temp.push_back(str[i]);
            solve(idx + 1, ans, digits,temp, mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> ans;
        int idx = 0;
        string temp = "";
        solve(idx, ans, digits, temp, mp);
        return ans;
    }
};