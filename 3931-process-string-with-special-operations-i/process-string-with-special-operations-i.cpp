class Solution {
public:
    string duplicate(string result) {
        string ans = "";
        for(int i=0; i<result.size(); i++) {
            ans += result[i];
        }
        return ans;
    }
    void reverse(string &result) {
        int i=0;
        int j=result.size()-1;
        while(i <= j) {
            swap(result[i], result[j]);
            i++;
            j--;
        }
    }
    string processStr(string s) {
        // * -> remove last char
        // # -> duplicates current res and append it to result
        // % -> reverse the result
        
        string result = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                result += s[i];
            }
            else if(s[i] == '*') {
                if(result.size() >= 1) {
                    result.pop_back();
                }
            }
            else if(s[i] == '#') {
                string dupres = duplicate(result);
                result += dupres;
            }
            else {
                reverse(result);
            }
        }
        return result;
    }
};